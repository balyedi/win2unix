COLORREF SetBkColor(
  /*[in]*/ HDC      hdc,
  /*[in]*/ COLORREF color
) {
  SDL_SetRenderDrawColor(hdc->renderer,_Wget_component(color,0), _Wget_component(color,1), _Wget_component(color,2),0);
  hdc->bg = color;
}