LONG_PTR GetWindowLongPtrW(
  /*[in]*/ HWND hWnd,
  /*[in]*/ int  nIndex
) {
  switch(nIndex) {
    case GWL_EXSTYLE:
      return &hWnd->dwExStyle;
      break;
    case GWLP_HINSTANCE:
      return NULL;
      break;
    case GWLP_HWNDPARENT:
      return &hWnd->parent;
      break;
    case GWLP_ID:
      return NULL;
      break;
    case GWL_STYLE:
      return &hWnd->dwStyle;
      break;
    default:
      return NULL;
      break;
  }
}