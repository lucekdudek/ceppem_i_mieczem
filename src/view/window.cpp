#include "window.h"
#include "../controller/controller.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <SDL2/SDL_version.h>
#include <SDL2/SDL_syswm.h>

TTF_Font *Window::font;
bool Window::locked;

std::list<std::string> splitString(std::string str)
{
	std::list<std::string> words;

	std::size_t last = -1;
	std::size_t found;

	while ((found = str.find_first_of(" ")) != std::string::npos)
	{
		words.push_back(str.substr(last + 1, found - last - 1));
		last = found;
		str[found] = '*';
	}
	words.push_back(str.substr(last + 1));

	return words;
}

void setWindowsIcon(SDL_Window *sdlWindow)
{
	HINSTANCE handle = ::GetModuleHandle(nullptr);
	HICON icon = ::LoadIcon(handle, "IDI_MAIN_ICON");
	if (icon != nullptr)
	{
		SDL_SysWMinfo wminfo;
		SDL_VERSION(&wminfo.version);
		if (SDL_GetWindowWMInfo(sdlWindow, &wminfo) == 1)
		{
			HWND hwnd = wminfo.info.win.window;
			::SetClassLong(hwnd, GCL_HICON, reinterpret_cast<LONG>(icon));
			SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)icon);
		}
	}
}

void enableMaximizeButton(SDL_Window *sdlWindow)
{
	SDL_SysWMinfo wminfo;
	SDL_VERSION(&wminfo.version);
	if (SDL_GetWindowWMInfo(sdlWindow, &wminfo) == 1)
	{
		HWND hwnd = wminfo.info.win.window;

		//enable window maximize button
		SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) | WS_MAXIMIZEBOX);
	}
}

Window::Window()
{
	hovered = NULL;
	locked = false;
	// TODO Auto-generated constructor stub
	init(1280, 720, (char *) "Ceppem i mieczem");

	cursor1 = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
	cursor2 = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);

	SDL_GetCurrentDisplayMode(0, &this->current);
	printf("Screen size: %ix%i.\n", this->current.w, this->current.h);
	Window::font = loadFont((char *) "../data/arial.ttf", 50);
	restore = new Texture(1246, 10, 24, 24, "../data/restore.png");
}

Window::~Window()
{
	// TODO Auto-generated destructor stub
	SDL_GL_DeleteContext(mainGLContext);
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
}

void Window::init(int width, int height, char *title)
{
	done = false;
	w = width;
	h = height;

	clickmap = new char*[width];
	for (int i = 0; i < width; ++i)
		clickmap[i] = new char[height];

	// Create window.
	initSDL(width, height, title, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	createOrthoProj(width, height);
}

void Window::initSDL(Uint32 width, Uint32 height, char *title, Uint32 flags)
{
	int error;
	error = SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init(); // TODO

	if (error)
	{
		printf("ERROR SDL INIT: %i\n", error);
	}

	// Turn on double buffering.
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Create the window
	mainWindow = SDL_CreateWindow(title,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	/*SDL_SetWindowMinimumSize(mainWindow,1280,720);
	SDL_SetWindowMaximumSize(mainWindow,1280,720);*/
	mainGLContext = SDL_GL_CreateContext(mainWindow);
	setWindowsIcon(mainWindow);
	enableMaximizeButton(mainWindow);
}

void Window::createOrthoProj(int width, int height)
{
	// I use a near plane value of -1, and a far plane value of 1, which is what works best for 2D games.
	w = width;
	h = height;
	glLoadIdentity();
	glOrtho(0.0, (GLdouble)width, 0.0, (GLdouble)height, -1.0, 1.0);
}

void Window::eventLoop()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		int cx, cy, cw, ch; //current mouse position
		switch (event.type)
		{
		case SDL_KEYDOWN:
			// Quit when user presses a key.
			//Controller::setDone();
			break;

		case SDL_QUIT:
			Controller::setDone();
			break;

		case SDL_MOUSEBUTTONDOWN:
			SDL_GetMouseState(&cx, &cy);
			SDL_GetWindowSize(mainWindow, &cw, &ch);
			cx = ((cx * w) / cw);
			cy = ((cy * h) / ch);

			if (clickmap[cx][cy] > -1)
			{
				Controller::event(buttons[clickmap[cx][cy]]);
			}
			else if (1246 <= cx && cx <= 1270 && 10 <= cy && cy <= 34 && (SDL_GetWindowFlags(mainWindow) & SDL_WINDOW_FULLSCREEN_DESKTOP))
			{//1246,10,24,24
				locked = true;
				toggleFullscreen();
				//SDL_TimerID timerID = SDL_AddTimer(500, &unlock, "");
			}
			break;

		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&cx, &cy);
			SDL_GetWindowSize(mainWindow, &cw, &ch);
			cx = ((cx * w) / cw);
			cy = ((cy * h) / ch);
			//fprintf(stdout, "MOUSE x:%i y:%i\n", cx, cy);break;
			if (clickmap[cx][cy] > -1)
			{
				SDL_SetCursor(cursor2);
				hovered = buttonsElements[clickmap[cx][cy]]->getOnHover();
			}
			else if (1246 <= cx && cx <= 1270 && 10 <= cy && cy <= 34 && (SDL_GetWindowFlags(mainWindow) & SDL_WINDOW_FULLSCREEN_DESKTOP))
			{//1246,10,24,24
				SDL_SetCursor(cursor2);
				hovered = NULL;
			}
			else
			{
				SDL_SetCursor(cursor1);
				hovered = NULL;
			}
			break;
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_MAXIMIZED:
				if (!locked)
				{
					Window::toggleFullscreen();
				}
				else
				{
					locked = false;
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}   // End switch

	}   // End while
}

int Window::loadGLTexture(char* fileName)
{
	unsigned int textureId;
	SDL_Surface *textureImage;
	textureImage = IMG_Load(fileName);
	if (!textureImage)
	{
		fprintf(stderr, "Couldn't load %s.\n", fileName);
		return 0;
	}
	else
	{

		//Create the texture.
		glGenTextures(1, &textureId);
		int error = glGetError();
		if (error)
		{
			fprintf(stderr, "ERROR CODE %i.\n", error);
		}

		//Typical texture generation using data from the bitmap.
		glBindTexture(GL_TEXTURE_2D, textureId);

		//Generate the texture.
		if (textureImage->format->BytesPerPixel == 4)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, 4, textureImage->w, textureImage->h,
				0, GL_RGBA, GL_UNSIGNED_BYTE, textureImage->pixels);
		}
		else
		{
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

TTF_Font *Window::loadFont(char *fileName, int fontSize)
{
	TTF_Font *text_font = TTF_OpenFont("../data/arial.ttf", 50);
	if (text_font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		return 0;
	}
	return text_font;
}

int Window::renderText(char *text, int &w, int &h, TTF_Font *text_font)
{
	SDL_Color textColor = { 128, 0, 0 };

	SDL_Surface *sdl_surface = TTF_RenderUTF8_Blended(Window::font, text,
		textColor);
	w = (sdl_surface->w * 1280) / 1920;
	h = (sdl_surface->h * 1280) / 1920;
	if (sdl_surface == NULL)
	{
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
	SDL_FreeSurface(sdl_surface);

	return texture_id;
}

int Window::getTextWidth(const char *text, TTF_Font *text_font)
{
	SDL_Color textColor = { 128, 0, 0 };
	SDL_Surface *sdl_surface = TTF_RenderUTF8_Blended(Window::font, text, textColor);
	int sw = sdl_surface->w;
	SDL_FreeSurface(sdl_surface);
	return sw;
}
int Window::getTextHeight(const char *text, TTF_Font *text_font)
{
	SDL_Color textColor = { 128, 0, 0 };
	SDL_Surface *sdl_surface = TTF_RenderUTF8_Blended(Window::font, text, textColor);
	int sh = sdl_surface->h;
	SDL_FreeSurface(sdl_surface);
	return sh;
}

int Window::renderTextBox(char *text, int &w, int &h, int t_width, int t_heigth, TTF_Font *text_font)
{	
	t_width = (t_width * 1920) / 1280;
	t_heigth = (t_heigth * 1920) / 1280;
	SDL_Color textColor = { 128, 0, 0 };
	int text_width = 200;

	int line_height = getTextHeight("Jjysad", text_font);

	std::list<std::string> words = splitString(text);

	std::list<std::string> lines;
	std::string prev = "";
	std::string curr = "";
	for (auto i = words.begin(); i != words.end(); i++)
	{
		auto tmpElem = *i;

		if (curr.length() > 0)
		{
			curr = curr + " ";
		}
		curr = curr + *i;
		if (getTextWidth(curr.c_str(), text_font) > t_width)
		{
			if (i != words.begin())
			{
				lines.push_back(prev);
				i--;
			}
			else
			{
				break;
			}
			prev = "";
			curr = "";
		}
		else
		{
			prev = curr;
		}
	}
	if (curr.length() > 0)
	{
		lines.push_back(curr);
	}

	//get width of the longest line
	int max_width = 0;
	for (auto i = lines.begin(); i != lines.end(); i++)
	{
		int curr_width = getTextWidth((*i).c_str(), text_font);
		if (curr_width > max_width)
		{
			max_width = curr_width;
		}
	}

	//get height of text
	int max_height = lines.size()*line_height;

	//create transparent surface
	SDL_Surface* sdl_surface = SDL_CreateRGBSurface(0, max_width, max_height, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	
	
	int index = 0;
	for (auto i = lines.begin(); i != lines.end(); i++)
	{
		SDL_Surface *surface = TTF_RenderUTF8_Blended(Window::font, (*i).c_str(), textColor);
		SDL_SetSurfaceBlendMode(surface, SDL_BLENDMODE_NONE);
		SDL_Rect dest;
		dest.x = 0;
		dest.y = (line_height)*index;
		dest.w = surface->w;
		dest.h = surface->h;
		SDL_BlitSurface(surface, NULL, sdl_surface, &dest);
		SDL_FreeSurface(surface);
		index++;
	}

	if (sdl_surface == NULL)
	{
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
	SDL_FreeSurface(sdl_surface);

	w = (sdl_surface->w * 1280) / 1920;
	h = (sdl_surface->h * 1280) / 1920;

	return texture_id;
}

void Window::drawImage(int x, int y, int textureId, int width, int height)
{
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

GLubyte array[3 * 100 * 100];
void Window::renderFrame()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(0.7, 0.5, 0.8);
	//glColor4f(1.0f,1.0f,1.0f,0.5f);//set opacity

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// For Ortho mode, of course
	int Width = 616;
	int Height = 409;
	int X = (1280 - Width) / 2;
	int Y = (720 - Height) / 2;

	std::list<Element*> el = this->view->getList();
	for (std::list<Element*>::iterator it = el.begin(); it != el.end(); it++)
	{
		Element* e = ((Element*)(*it));
		std::list<Texture*> tex = e->getTextures();

		for (std::list<Texture*>::iterator it2 = tex.begin(); it2 != tex.end(); it2++)
		{
			drawImage((*it2)->getX(), (*it2)->getY(), (*it2)->getId(), (*it2)->getWidth(),
				(*it2)->getHeight());
		}
	}

	if (hovered != NULL)
	{
		drawImage(hovered->getX(), hovered->getY(), hovered->getId(), hovered->getWidth(), hovered->getHeight());
	}

	if (SDL_GetWindowFlags(mainWindow) & SDL_WINDOW_FULLSCREEN_DESKTOP)
	{
		drawImage(restore->getX(), restore->getY(), restore->getId(), restore->getWidth(), restore->getHeight());
	}


	/*glReadBuffer(GL_BACK_LEFT);
	glReadPixels(1280/2, 720/2, 100, 100, GL_RGB, GL_UNSIGNED_BYTE, array);
	glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, array);*/

	//glRecti(50, 100, 200, 300);
	SDL_GL_SwapWindow(mainWindow);
}

void Window::setView(View* view)
{
	View* temp = nullptr;
	if (this->view != nullptr)
	{
		temp = this->view;
	}

	this->view = view;

	if (temp != nullptr)
	{
		delete temp;
	}

	updateClickmap();
}
void Window::toggleFullscreen()
{
	if (SDL_GetWindowFlags(mainWindow) & SDL_WINDOW_FULLSCREEN_DESKTOP)
	{
		glViewport(0, 0, 1280, 720);
		createOrthoProj(1280.0, 720.0);
		Uint32 flags = (SDL_GetWindowFlags(mainWindow) ^ SDL_WINDOW_FULLSCREEN_DESKTOP);
		SDL_SetWindowFullscreen(mainWindow, flags);
		SDL_RestoreWindow(mainWindow);
		SDL_SetWindowSize(mainWindow, 1280, 720);
		SDL_SetWindowPosition(mainWindow, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	}
	else
	{
		glViewport(0, (this->current.h - this->current.w / 16.0 * 9.0) / 2.0,
			this->current.w, this->current.w / 16.0 * 9.0);
		//glViewport(0, 0, 1920, 1080);
		createOrthoProj(1280.0, 720.0);
		SDL_SetWindowFullscreen(mainWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
	enableMaximizeButton(mainWindow);
}

void Window::unloadGLTexture(int id)
{
	glDeleteTextures(1, (GLuint*)&id);
}

Uint32 Window::unlock(Uint32 interval, void* param)
{
	locked = false;
	return(interval);
}

void Window::updateClickmap()
{
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			clickmap[i][j] = -1;
		}
	}

	buttons.clear();
	buttonsElements.clear();

	std::list<Element*> el = this->view->getList();

	std::list<Element*>::iterator it = el.begin();
	std::advance(it, this->view->getClickMap());
	for (; it != el.end(); it++)
	{
		Element* e = ((Element*)(*it));

		if (e->clickable())
		{
			for (int i = e->getX(); i < (e->getWidth() + e->getX()); i++)
			{
				for (int j = e->getY(); j < (e->getHeight() + e->getY()); j++)
				{
					clickmap[i][j] = buttons.size();
				}
			}
			buttons.push_back(e->getOnClick());
			buttonsElements.push_back(e);
		}
	}
}