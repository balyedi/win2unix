LRESULT CALLBACK _WsendWMmessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	//fprintf(stderr,"%ls",hwnd->windowname);
	//hwnd->_Wassocclass->lpfnWndProc(hwnd,uMsg,wParam,lParam);
	if(hwnd == 32) {
		fprintf(stderr,"as");
		//_Wclasses->lpfnWndProc(hwnd,uMsg,wParam,lParam);
		LRESULT CALLBACK (*winprocptr)(HWND,UINT,WPARAM,LPARAM) = _Wclasses[--_Wclassesitr].lpfnWndProc;
		(*winprocptr)(hwnd,uMsg,wParam,lParam);
	} else {
		LRESULT CALLBACK (*winprocptr)(HWND,UINT,WPARAM,LPARAM) = hwnd->_Wassocclass->lpfnWndProc;
		(*winprocptr)(hwnd,uMsg,wParam,lParam);
	}
}
/*void _WsendWMmessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  if(lpMsg->hwnd != NULL) {
    hwnd = lpMsg->hwnd;
  } else {
    //fprintf(stderr,"aaa%p",_Whwnds[0]);
    itr = _Whwndsitr - 1;
    _WsendWMmessageR(_Whwnds[itr], lpMsg->message, NULL, NULL);
    return;
  }
  _WsendWMmessageR(lpMsg->hwnd, lpMsg->message, NULL, NULL);
  return;
  }*/