int MessageBox(
  HWND    hWnd,
  LPCTSTR lpText,
  LPCTSTR lpCaption,
  UINT    uType
) {
    char* buffer1 = alloca(wcslen(lpCaption)+2);
    char* buffer2 = alloca(wcslen(lpText));
    sprintf(buffer1,"%ls",lpCaption);
    sprintf(buffer2,"%ls",lpText);
    /*switch(uType) {
        case MB
    }*/
    if(hWnd != NULL) { // Has a parent
        return SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, buffer1, buffer2, hWnd->_Wwindow);
    } else { // No parent
        return SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, buffer1, buffer2, NULL);
    }
}