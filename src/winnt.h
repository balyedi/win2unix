#ifdef UNICODE
#define TEXT(x) L##x
#else
#define TEXT(x) x
#endif