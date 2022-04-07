int FillRect(
  HDC        hDC,
  const RECT *lprc,
  HBRUSH     hbr
) {
  SDL_SetRenderDrawColor(hDC,
                   255, 255, 255,
                   100);
  SDL_RenderFillRect(hDC,NULL);
  return 0;
}
