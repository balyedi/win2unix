BOOL EndPaint(
  HWND              hWnd,
  const PAINTSTRUCT *lpPaint
) {
  SDL_RenderClear(hWnd->_Wassochdc->renderer);
  SDL_RenderPresent(hWnd->_Wassochdc->renderer);
  return TRUE;
}