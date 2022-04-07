#ifdef UNICODE
#define CreateFile CreateFileW
#define WriteFile WriteFileW
#else
#define CreateFile CreateFileA
#define WriteFile WriteFileA
#endif

#include "fileapi/createfile.c"
#include "fileapi/writefile.c"