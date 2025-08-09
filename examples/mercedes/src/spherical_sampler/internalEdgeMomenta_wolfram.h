#include "WolframLibrary.h"

EXTERN_C DLLEXPORT int Initialize_internalEdgeMomenta_wolfram(WolframLibraryData libData);

EXTERN_C DLLEXPORT void Uninitialize_internalEdgeMomenta_wolfram(WolframLibraryData libData);

EXTERN_C DLLEXPORT int internalEdgeMomenta_wolfram(WolframLibraryData libData, MTensor A1, mint A2, MTensor A3, MTensor *Res);

