#ifndef WINDOW_H_
#define WINDOW_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "view.h"
#include "font.h"
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
    static void unloadGLTexture(int id);

    TTF_Font *loadFont(char *fileName, int fontSize);
	static int renderText(char *text, int &w, int &h, int fontSize, unsigned char r = 128, unsigned char g = 0, unsigned char b = 0);
	static int getTextWidth(const char *text, int fontSize);
	static int getTextHeight(const char *text, int fontSize);
	static int renderTextBox(char *text, int &w, int &h, int t_width, int t_heigth, int fontSize, unsigned char r=128, unsigned char g=0, unsigned char b=0);

    void renderFrame();

    void setView(View* view);
    void toggleFullscreen();
	void updateClickmap();
	static Font* fontLoader;
private:
    View* view;
    char** clickmap;
    std::vector<std::string> buttons;
    std::vector<Element*> buttonsElements;

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

	Texture* hovered;
	Texture* restore;
	static Uint32 unlock(Uint32 interval, void* param);
	static bool locked;
};

#endif /* WINDOW_H_ */
