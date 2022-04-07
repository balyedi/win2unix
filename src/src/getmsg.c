BOOL GetMessage( /* basically a SDL_PollEvent wrapper */
    LPMSG lpMsg,
  
 HWND  hWnd,
   UINT  wMsgFilterMin,
          UINT  wMsgFilterMax
) {
    /*if(hWnd != NULL) {
        SDL_Quit();
    }*/
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            //printf("a\n");
            //fflush(stdout);
            _Wevent = WM_CLOSE;
            lpMsg->message = _Wevent;

            SDL_Delay(6);
            return TRUE;
            break;

        default:
            lpMsg->message = WM_PAINT;

            SDL_Delay(6);
            return TRUE;
            break;
    }
    lpMsg->hwnd = hWnd;
    SDL_Delay(6);
    return 1;
}