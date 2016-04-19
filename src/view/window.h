#ifndef WINDOW_H_
#define WINDOW_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "view.h"
#include <vector>

class Window {
protected:
    SDL_Window *mainWindow;
    SDL_GLContext mainGLContext;
public:
    Window();
    ~Window();

    int done;

    void eventLoop();
    void drawImage(int x, int y, int textureId, int width = 0, int height = 0);
    static int loadGLTexture(char* fileName);
    TTF_Font *loadFont(char *fileName, int fontSize);
    int renderText(char *text, TTF_Font *text_font);
    void renderFrame();

    void setView(View* view);
    void toggleFullscreen();
private:
    View* view;
    char** clickmap;
    std::vector<std::string> buttons;

    SDL_Cursor *cursor1;
    SDL_Cursor *cursor2;
    int previousTime;
    int currentTime;
    int w, h;

    void init(int width, int height, char *title);
    void initSDL(Uint32 width, Uint32 height, char *title, Uint32 flags);
    static Uint32 gameLoopTimer(Uint32 interval, void *param);
    void createOrthoProj(int width, int height);
    SDL_DisplayMode current;
};

const int MAX_FPS = 60;

#endif /* WINDOW_H_ */
