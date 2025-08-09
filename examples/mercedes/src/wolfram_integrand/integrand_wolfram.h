#include "WolframLibrary.h"

EXTERN_C DLLEXPORT int Initialize_integrand_wolfram(WolframLibraryData libData);

EXTERN_C DLLEXPORT void Uninitialize_integrand_wolfram(WolframLibraryData libData);

EXTERN_C DLLEXPORT int integrand_wolfram(WolframLibraryData libData, MTensor A1, MTensor A2, mreal *Res);

