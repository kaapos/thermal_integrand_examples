#include "stdlib.h"
#include "internalEdgeMomenta_wolfram.h"
#include "loopMomenta_wolfram.h"
#include "jacobian_wolfram.h"
#include "WolframRTL.h"

// #include <time.h>
// #include <stdio.h>

void sampler(double **x, int n_samples, const double params[3], int mcpow, int mcpowf, \
double a, double b, double cut, double cutIR, double *jacobianArray, double **loopMomentumArray) {
    // clock_t start_time = clock();

    WolframLibraryData libData = WolframLibraryData_new(WolframLibraryVersion);
    Initialize_internalEdgeMomenta_wolfram(libData);

    const int n_loops = 3;
    const int n_channels = 16;
    const int x_size = 7;
    const int dim = 3;
    const int n_params = 3;

    int i, j;
    int channelID;
    double jacobianData;
    double* mcLoopMomentumResult;
    
    mint pos[1];

    MTensor loopMomentumData;
    mint dimsLoopMomentumData[2];
    dimsLoopMomentumData[0] = n_loops;
    dimsLoopMomentumData[1] = dim;
    libData -> MTensor_new(MType_Real, 2, dimsLoopMomentumData, &loopMomentumData);

    MTensor mcLoopMomentumData;
    mint dimsMcLoopMomentumData[2];
    dimsMcLoopMomentumData[0] = n_loops;
    dimsMcLoopMomentumData[1] = dim;
    libData -> MTensor_new(MType_Real, 2, dimsMcLoopMomentumData, &mcLoopMomentumData);

    MTensor xData;
    mint dimsXData[1];
    dimsXData[0] = x_size - 1;
    libData -> MTensor_new(MType_Real, 1, dimsXData, &xData);

    MTensor paramData;
    mint dimsParamData[1];
    dimsParamData[0] = n_params;
    libData -> MTensor_new(MType_Real, 1, dimsParamData, &paramData);
    for(i = 0; i < n_params; ++i) {
        pos[0] = i + 1;
        libData -> MTensor_setReal(paramData, pos, params[i]);
    }
    

    for (i = 0; i < n_samples; ++i) {
        channelID = n_channels * x[i][x_size - 1] + 1;

        for (j = 0; j < x_size - 1; ++j) {
            pos[0] = j + 1;
            libData -> MTensor_setReal(xData, pos, x[i][j]);
        }

        loopMomenta_wolfram(libData, xData, channelID, paramData, a, b, cut, cutIR, &loopMomentumData);
        internalEdgeMomenta_wolfram(libData, loopMomentumData, channelID, paramData, &mcLoopMomentumData);
        jacobian_wolfram(libData, mcLoopMomentumData, channelID, paramData, mcpow, mcpowf, a, b, &jacobianData);

        jacobianArray[i] = n_channels * jacobianData;
        mcLoopMomentumResult = libData -> MTensor_getRealData(mcLoopMomentumData);

        for (j = 0; j < n_loops * dim; ++j) {
            loopMomentumArray[i][j] = mcLoopMomentumResult[j];
        }
    }

    // clock_t end_time = clock();
    // double timing_per_sample_us = 1000000 * ((double)(end_time - start_time)) / CLOCKS_PER_SEC / n_samples;
    // printf("Compiled sampling timing: %f µs for %d samples\n", timing_per_sample_us, n_samples);
}