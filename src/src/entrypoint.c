SDL_Window* _Wwindow = NULL;
//SDL_Renderer *_Wrenderer = NULL;

int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "[w2u] could not initialize sdl2: %s\n", SDL_GetError());
	  	return 1;
	}
	int retint;
	#ifdef UNICODE
	retint = wWinMain(NULL,0);
	#else 
	retint = WinMain(NULL,0);
	#endif
	exit(retint);
}