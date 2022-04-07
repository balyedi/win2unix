LRESULT DispatchMessage(
  const MSG *lpMsg
) {
  /*printf("%p\n",lpMsg->hwnd);
  fflush(stdout);
  printf("%d",lpMsg->message);
  fflush(stdout);*/
  HWND hwnd;
  int itr;
  if(lpMsg->message != 0) {
  //printf("%p",lpMsg->message);
}
  if(_Wmsgqueueitr < 0) {
    return FALSE;
  }
  if(lpMsg->hwnd != NULL) {
    hwnd = lpMsg->hwnd;
  } else {
    //fprintf(stderr,"aaa%p",_Whwnds[0]);
    itr = _Whwndsitr - 1;
    _WsendWMmessage(_Whwnds[itr], lpMsg->message, NULL, NULL);
    //--_Wmsgqueueitr;
    return 0;
  }
  _WsendWMmessage(lpMsg->hwnd, lpMsg->message, NULL, NULL);
  //--_Wmsgqueueitr;
  return 0;
}