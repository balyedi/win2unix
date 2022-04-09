

#include "wingdi/textout.c"
#include "wingdi/setbkcolor.c"
#include "wingdi/createsolidbrush.c"

#ifdef UNICODE
#define TextOut TextOutW
#else
#define TextOut TextOutA
#endif