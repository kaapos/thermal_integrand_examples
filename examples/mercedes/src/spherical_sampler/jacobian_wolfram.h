#include "WolframLibrary.h"

EXTERN_C DLLEXPORT int Initialize_jacobian_wolfram(WolframLibraryData libData);

EXTERN_C DLLEXPORT void Uninitialize_jacobian_wolfram(WolframLibraryData libData);

EXTERN_C DLLEXPORT int jacobian_wolfram(WolframLibraryData libData, MTensor A1, mint A2, MTensor A3, mint A4, mint A5, mreal A6, mreal A7, mreal *Res);

