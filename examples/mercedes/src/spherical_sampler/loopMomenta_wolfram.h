#include "WolframLibrary.h"

EXTERN_C DLLEXPORT int Initialize_loopMomenta_wolfram(WolframLibraryData libData);

EXTERN_C DLLEXPORT void Uninitialize_loopMomenta_wolfram(WolframLibraryData libData);

EXTERN_C DLLEXPORT int loopMomenta_wolfram(WolframLibraryData libData, MTensor A1, mint A2, MTensor A3, mreal A4, mreal A5, mreal A6, mreal A7, MTensor *Res);

