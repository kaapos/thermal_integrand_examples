#include "WolframLibrary.h"

EXTERN_C DLLEXPORT int Initialize_OSEsAndSPs_wolfram(WolframLibraryData libData);

EXTERN_C DLLEXPORT void Uninitialize_OSEsAndSPs_wolfram(WolframLibraryData libData);

EXTERN_C DLLEXPORT int OSEsAndSPs_wolfram(WolframLibraryData libData, MTensor A1, MTensor A2, MTensor *Res);

