HDC BeginPaint(
   HWND          hWnd,
     LPPAINTSTRUCT lpPaint
) {
  _Whdc *hdc = malloc(_Whdcsize);
  //hdc->renderer = malloc(sizeof(struct SDL_Renderer));
  hdc->renderer = SDL_CreateRenderer(hWnd->_Wwindow, -1, SDL_RENDERER_ACCELERATED);
  hWnd->_Wassochdc = hdc;
  //hdc->renderer = hWnd->
  return hdc;
}