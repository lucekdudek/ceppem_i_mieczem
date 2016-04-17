#include "window.h"

#include <stdio.h>

Window::Window() {
	// TODO Auto-generated constructor stub
	init(1280, 720, (char *) "Tytuł okna");

	textures = new unsigned int[3];
	textures[0] = loadGLTexture((char *) "texture.png");
	textures[1] = loadGLTexture((char *) "png.png");

	TTF_Font *fontArial = loadFont((char *) "arial.ttf", 50);
	textures[2] = renderText((char *) "hello world", fontArial);

	cursor1 = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
	cursor2 = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);

	while (!done) {
		previousTime = SDL_GetTicks();
		eventLoop();
		renderFrame();
		currentTime = SDL_GetTicks();

		int value = 1000 / MAX_FPS - (currentTime - previousTime);

		if (value > 0) {
			SDL_Delay(value);
		}
	}
}

Window::~Window() {
	// TODO Auto-generated destructor stub
	SDL_GL_DeleteContext(mainGLContext);
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
}

void Window::init(int width, int height, char *title) {
	done = false;
	w = width;
	h = height;
	// Create window.
	initSDL(width, height, title, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	createOrthoProj(width, height);
}

void Window::initSDL(Uint32 width, Uint32 height, char *title, Uint32 flags) {
	int error;
	error = SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init(); // TODO

	if (error) {
		printf("ERROR SDL INIT: %i\n", error);
	}

	// Turn on double buffering.
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Create the window
	mainWindow = SDL_CreateWindow(title,
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	mainGLContext = SDL_GL_CreateContext(mainWindow);

}

void Window::createOrthoProj(int width, int height) {
	// I use a near plane value of -1, and a far plane value of 1, which is what works best for 2D games.
	w = width;
	h = height;
	glLoadIdentity();
	glOrtho(0.0, (GLdouble) width, 0.0, (GLdouble) height, -1.0, 1.0);
}

void Window::eventLoop() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		int x, y, w, h;
		switch (event.type) {
		case SDL_KEYDOWN:
			// Quit when user presses a key.
			done = true;
			break;

		case SDL_QUIT:
			done = true;
			break;

		case SDL_MOUSEBUTTONDOWN:
			SDL_GetMouseState(&x, &y);
			w = 616;
			h = 409;
			if (x > (640 - w / 2) && x < (640 + w / 2) && y > (360 - h / 2)
					&& y < (360 + h / 2)) {
				if (SDL_GetWindowFlags(mainWindow)
						& SDL_WINDOW_FULLSCREEN_DESKTOP) {
					glViewport(0, 0, 1280, 720);
					createOrthoProj(1280.0, 720.0);
					SDL_SetWindowFullscreen(mainWindow, 0);
				} else {
					glViewport(0, 0, 1920, 1080);
					createOrthoProj(1920.0, 1080.0);
					SDL_SetWindowFullscreen(mainWindow,
							SDL_WINDOW_FULLSCREEN_DESKTOP);
				}
			}
			break;

		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&x, &y);
			//fprintf(stdout, "MOUSE x:%i y:%i\n", x, y);
			w = 616;
			h = 409;
			if (x > (640 - w / 2) && x < (640 + w / 2) && y > (360 - h / 2)
					&& y < (360 + h / 2))
				SDL_SetCursor(cursor2);
			else
				SDL_SetCursor(cursor1);
			break;

		default:
			break;
		}   // End switch

	}   // End while
}

int Window::loadGLTexture(char *fileName) {
	unsigned int textureId;
	SDL_Surface *textureImage;
	textureImage = IMG_Load(fileName);
	if (!textureImage) {
		fprintf(stderr, "Couldn't load %s.\n", fileName);
		return 0;
	} else {

		//Create the texture.
		glGenTextures(1, &textureId);
		int error = glGetError();
		if (error) {
			fprintf(stderr, "ERROR CODE %i.\n", error);
		}

		//Typical texture generation using data from the bitmap.
		glBindTexture(GL_TEXTURE_2D, textureId);

		//Generate the texture.
		if (textureImage->format->BytesPerPixel == 4) {
			glTexImage2D(GL_TEXTURE_2D, 0, 4, textureImage->w, textureImage->h,
					0, GL_RGBA, GL_UNSIGNED_BYTE, textureImage->pixels);
		} else {
			glTexImage2D(GL_TEXTURE_2D, 0, 3, textureImage->w, textureImage->h,
					0, GL_RGB, GL_UNSIGNED_BYTE, textureImage->pixels);
		}

		//Linear filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//Free up the memory.
		if (textureImage)
			SDL_FreeSurface(textureImage);

		return textureId;
	}
}

TTF_Font *Window::loadFont(char *fileName, int fontSize) {
	TTF_Font *text_font = TTF_OpenFont("arial.ttf", 50);
	if (text_font == NULL) {
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		return 0;
	}
	return text_font;
}

int Window::renderText(char *text, TTF_Font *text_font) {
	SDL_Color textColor = { 128, 0, 0 };

	SDL_Surface *sdl_surface = TTF_RenderText_Blended(text_font, text,
			textColor);
	if (sdl_surface == NULL) {
		printf("Unable to render text surface! SDL_ttf Error: %s\n",
				TTF_GetError());
		return 0;
	}

	GLuint texture_id;

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sdl_surface->w, sdl_surface->h, 0,
			GL_BGRA, GL_UNSIGNED_BYTE, sdl_surface->pixels);

	return texture_id;
}

void Window::drawImage(int x, int y, int textureId, int width, int height) {
	y = h - y - height;
	glBindTexture(GL_TEXTURE_2D, textureId);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(x, y, 0);
	glTexCoord2f(1, 1);
	glVertex3f(x + width, y, 0);
	glTexCoord2f(1, 0);
	glVertex3f(x + width, y + height, 0);
	glTexCoord2f(0, 0);
	glVertex3f(x, y + height, 0);
	glEnd();
}

void Window::renderFrame() {
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(0.7, 0.5, 0.8);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// For Ortho mode, of course
	int Width = 616;
	int Height = 409;
	int X = (1280 - Width) / 2;
	int Y = (720 - Height) / 2;

	drawImage(X, Y, textures[0], Width, Height);
	drawImage(X, Y, textures[1], 800, 600);
	drawImage(X, Y, textures[2], 242, 57);

	//glRecti(50, 100, 200, 300);
	SDL_GL_SwapWindow(mainWindow);
}

