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
	char* winname = malloc(wcslen(lpWindowName)+2);
	sprintf(winname, "%ls", lpWindowName );
	_Wwindow = SDL_CreateWindow(
		  winname,
		  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		  nWidth, nHeight,
		  SDL_WINDOW_SHOWN
	);
	if(_Wwindow == NULL ) {
	  return NULL;
	}
	_Whwnd *hwnd;
	hwnd = malloc(_Whwndsize);

	hwnd->_Wwindow = _Wwindow;
	hwnd->dwStyle = dwStyle;
	hwnd->dwExStyle = NULL;

	wchar_t *winnamel = malloc(100);
	wcscpy(winnamel,lpWindowName);
	hwnd->windowname = winnamel;
	//printf("%ls",hwnd->windowname);
	uint8_t i;
	//if(strcmp(lpClassName,TEXT("")))
	for(i = 0;i < _Wclassesitr;i++) {
	  //fprintf(stderr,"%ls",_Wclasses[i].lpszClassName);
	  if(strcmp(_Wclasses[i].lpszClassName,lpClassName) == 0) {
		hwnd->_Wassocclass = &_Wclasses[i];
		/*printf("%ls",hwnd->_Wassocclass->lpszClassName);
		fflush(stdout);*/
	  }
	}
	_Whwnds[_Whwndsitr] = hwnd;
	_Whwndsitr++;
	free(winname);
	return hwnd;
}
