HANDLE CreateFileW(
  /*[in]*/           LPCWSTR               lpFileName,
  /*[in]*/           DWORD                 dwDesiredAccess,
  /*[in]*/           DWORD                 dwShareMode,
  /*[in, optional]*/ LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  /*[in]*/           DWORD                 dwCreationDisposition,
  /*[in]*/           DWORD                 dwFlagsAndAttributes,
  /*[in, optional]*/ HANDLE                hTemplateFile
) {
  char* filename = alloca(wcslen(lpFileName)+2);
  sprintf(filename,"%ls",lpFileName);
  int fd;
  fd = open(filename, O_RDWR | O_APPEND | O_CREAT, 0644);
  return (HANDLE)fd;
}