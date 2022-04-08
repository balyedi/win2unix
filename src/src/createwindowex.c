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
		/*hwnd->bg = RGB(0,0,0);
		hwnd->fg = RGB(255,255,255);*/
		hwnd->dwStyle = dwStyle;
		hwnd->dwExStyle = dwExStyle;
		wchar_t *winnamel = malloc(100);
		wcscpy(winnamel,lpWindowName);
		hwnd->windowname = winnamel;
		//printf("%ls",hwnd->windowname);
		uint8_t i;
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
		free(winname);
    return hwnd;
} 
