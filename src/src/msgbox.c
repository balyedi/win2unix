int MessageBox(
  HWND    hWnd,
  LPCTSTR lpText,
  LPCTSTR lpCaption,
  UINT    uType
) {
    char* buffer1 = malloc(wcslen(lpCaption)+2);
    char* buffer2 = malloc(wcslen(lpText));
    sprintf(buffer1,"%ls",lpCaption);
    sprintf(buffer2,"%ls",lpText);
    /*switch(uType) {
        case MB
    }*/
    return SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, buffer1, buffer2, _Wwindow);
    free(buffer2);
    free(buffer1);
}