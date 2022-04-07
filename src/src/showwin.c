BOOL ShowWindow(
  HWND hWnd,
  int  nCmdShow
) {
  _Wrenderer = SDL_CreateRenderer(hWnd->_Wwindow, -1, SDL_RENDERER_ACCELERATED);
  hWnd->_Wassochdc = _Wrenderer;
  //puts("e");
  return TRUE;
}