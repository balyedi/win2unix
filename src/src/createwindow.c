HWND CreateWindowW(
  /*[in, optional]*/ LPCTSTR lpClassName,
  /*[in, optional]*/ LPCTSTR lpWindowName,
  /*[in]*/           DWORD dwStyle,
  /*[in]*/           int x,
  /*[in]*/           int y,
  /*[in]*/           int nWidth,
  /*[in]*/           int nHeight,
  /*[in, optional]*/ HWND hWndParent,
  /*[in, optional]*/ HMENU hMenu,
  /*[in, optional]*/ HINSTANCE hInstance,
  /*[in, optional]*/ LPVOID lpParam
) {
	return CreateWindowEx(0,lpClassName,lpWindowName,dwStyle,x,y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam);
}
