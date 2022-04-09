HWND CreateWindowEx(
DWORD dwExStyle, 
LPCTSTR lpClassName, 
LPCTSTR lpWindowName, 
DWORD dwStyle, 
int x, 
int y, 
int nWidth, 
int nHeight, 
HWND hWndParent, 
HMENU hMenu, 
HINSTANCE hInstance, 
LPVOID lpParam ) {
	char* winname = alloca(wcslen(lpWindowName)+3);
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
	if(hWndParent != NULL) {
		CREATESTRUCT *crtstrct = malloc(sizeof(_Wcstructsize));
		crtstrct->lpCreateParams = lpParam;
		crtstrct->hInstance = hInstance;
		crtstrct->hMenu = hMenu;
		crtstrct->hwndParent = hWndParent;
		crtstrct->cy = nHeight;
		crtstrct->cx = nWidth;
		crtstrct->y = y;
		crtstrct->x = x;
		crtstrct->style = dwStyle;
		crtstrct->lpszName = lpWindowName;
		crtstrct->lpszClass = lpClassName;
		crtstrct->dwExStyle = dwExStyle;
		LRESULT CALLBACK parentresponse = _WsendWMmessage(hWndParent,WM_CREATE,NULL,crtstrct);
		if(parentresponse < 0) {
			return NULL;
		}
	}
	_Whwnd *hwnd;
	hwnd = malloc(_Whwndsize);

	hwnd->_Wwindow = _Wwindow;
	hwnd->dwStyle = dwStyle;
	hwnd->dwExStyle = dwExStyle;

	wchar_t *winnamel = malloc(100);
	wcscpy(winnamel,lpWindowName);
	hwnd->windowname = winnamel;
	//printf("%ls",hwnd->windowname);
	uint8_t i;
	//if(strcmp(lpClassName,TEXT("")))
	for(i = 0;i < _Wclassesitr;i++) {
	  //fprintf(stderr,"%ls",_Wclasses[i].lpszClassName);
	  if(wcscmp(_Wclasses[i].lpszClassName,lpClassName) == 0) {
		hwnd->_Wassocclass = &_Wclasses[i];
		/*printf("%ls",hwnd->_Wassocclass->lpszClassName);
		fflush(stdout);*/
	  }
	}
	_Whwnds[_Whwndsitr] = hwnd;
	_Whwndsitr++;
	//free(winname);
	return hwnd;
}
