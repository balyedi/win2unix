int FillRect(
  HDC        hDC,
  const RECT *lprc,
  HBRUSH     hbr
) {
  if(hbr < 31) {
      SDL_SetRenderDrawColor(hDC->renderer,
                   255, 255, 255,
                   100);
  }

  SDL_RenderFillRect(hDC->renderer,NULL);
  return 0;
}
