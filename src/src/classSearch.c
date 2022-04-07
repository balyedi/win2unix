const struct WNDCLASS* _WclassSearch(char* string) {
    uint8_t i;
    for(i = 0;i < _Wclassesitr;) {
        if(strcmp(string,_Wclasses[i]->lpszClassName)) {
            return _Wclasses[i];
        }
    }
}