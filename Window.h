#ifndef WINDOW_H_
#define WINDOW_H_
#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"

class Window {
protected:
	SDL_Window* mainWindow;
	SDL_GLContext mainGLContext;
public:
	Window();
	virtual ~Window();

	void eventLoop();
	void drawImage(int x, int y, int textureId, int width=0, int height=0);
	int done;
	int loadGLTexture(char* fileName);
private:
	SDL_Cursor* cursor1;
	SDL_Cursor* cursor2;
	int previousTime;
	int currentTime;
	unsigned int* textures;

    void init(int width, int height, char* title);
    void initSDL(Uint32 width, Uint32 height, char* title, Uint32 flags);

    static Uint32 gameLoopTimer(Uint32 interval, void* param);

    void createOrthoProj(int width, int height);

    void renderFrame();
    int w, h;
};

const int MAX_FPS = 60;

#endif /* WINDOW_H_ */
