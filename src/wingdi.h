#include "wingdi/textout.c"

#ifdef UNICODE
#define TextOut TextOutW
#else
#define TextOut TextOutA
#endif