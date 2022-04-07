BOOL EndPaint(
  HWND              hWnd,
  const PAINTSTRUCT *lpPaint
) {
  SDL_RenderClear(hWnd->_Wassochdc);
  SDL_RenderPresent(hWnd->_Wassochdc);
  return TRUE;
}