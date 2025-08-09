#include "stdlib.h"
#include "integrand_wolfram.h"
#include "OSEsAndSPs_wolfram.h"
#include "WolframRTL.h"

// #include <time.h>
// #include <stdio.h>

void integrand(double **loopMomentumArray, double *jacobianArray, int n_samples, const double params[3], \
double tolerance, int do_stability_check, double *resultArray, int *successArray) {
    // clock_t start_time = clock();

    WolframLibraryData libData = WolframLibraryData_new(WolframLibraryVersion);
    Initialize_integrand_wolfram(libData);

    const int n_params = 3;
    const int n_OSEsAndSPs = 47;
    const int n_loops = 3;
    const int dim = 3;

    int i, j, k;
    int success;
    double integrandData;
    double result;
    
    mint pos[1];
    mint pos2[2];

    MTensor OSEsAndSPsData;
    mint dimsOSEsAndSPsData[1];
    dimsOSEsAndSPsData[0] = n_OSEsAndSPs;
    libData -> MTensor_new(MType_Real, 1, dimsOSEsAndSPsData, &OSEsAndSPsData);

    MTensor loopMomentumData;
    mint dimsLoopMomentumData[2];
    dimsLoopMomentumData[0] = n_loops;
    dimsLoopMomentumData[1] = dim;
    libData -> MTensor_new(MType_Real, 2, dimsLoopMomentumData, &loopMomentumData);

    MTensor paramData;
    mint dimsParamData[1];
    dimsParamData[0] = n_params;
    libData -> MTensor_new(MType_Real, 1, dimsParamData, &paramData);
    for(i = 0; i < n_params; ++i) {
        pos[0] = i + 1;
        libData -> MTensor_setReal(paramData, pos, params[i]);
    }
    
    for (i = 0; i < n_samples; ++i) {

        for (j = 0; j < n_loops; ++j) {
            pos2[0] = j + 1;
            for (k = 0; k < dim; ++k) {
                pos2[1] = k + 1;
                libData -> MTensor_setReal(loopMomentumData, pos2, loopMomentumArray[i][dim*j+k]);
            }
        }

        OSEsAndSPs_wolfram(libData, loopMomentumData, paramData, &OSEsAndSPsData);
        integrand_wolfram(libData, OSEsAndSPsData, paramData, &integrandData);

        result = jacobianArray[i] * integrandData;
        success = 1;

        if (do_stability_check == 1) {
            // implement stability check here
        }

        if (success == 0) {
            result = 0.0;
        }

        if (result != result) {
            result = 0.0;
            success = 0;
        }

        resultArray[i] = result;
        successArray[i] = success;
    }

    // clock_t end_time = clock();
    // double timing_per_sample_us = 1000000 * ((double)(end_time - start_time)) / CLOCKS_PER_SEC / n_samples;
    // printf("Compiled evaluation timing: %f µs for %d samples\n", timing_per_sample_us, n_samples);
}