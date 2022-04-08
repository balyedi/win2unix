

#include "wingdi/textout.c"
#include "wingdi/setbkcolor.c"

#ifdef UNICODE
#define TextOut TextOutW
#else
#define TextOut TextOutA
#endif