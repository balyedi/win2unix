ATOM RegisterClass(

CONST WNDCLASS *lpWndClass
	// address of structure with class data
) {
	_Wclasses[_Wclassesitr].lpszClassName = lpWndClass->lpszClassName;
	_Wclasses[_Wclassesitr].lpfnWndProc = lpWndClass->lpfnWndProc;
	//puts(_Wclasses[_Wclassesitr].lpszClassName);
	//fflush(stdout);
	//_Wclasses[_Wclassesitr].lpszClassName = lpWndClass->lpszClassName;
	//printf("%lsa\n",_Wclasses[0]->lpszClassName);
	//fflush(stdout);
	++_Wclassesitr;
}