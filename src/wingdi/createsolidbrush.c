HBRUSH CreateSolidBrush(
  /*[in]*/ COLORREF color
) {
  HBRUSH brush = malloc(_Whbrushsize);
  brush->color = color;
  return brush;
}