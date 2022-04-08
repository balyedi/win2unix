#ifdef UNICODE
#define CreateFile CreateFileW
#define DeleteFile DeleteFileW
#define WriteFile WriteFileW
#else
#define CreateFile CreateFileA
#define DeleteFile DeleteFileA
#define WriteFile WriteFileA
#endif

#include "fileapi/createfile.c"
#include "fileapi/deletefile.c"
#include "fileapi/writefile.c"