
#include "fpshandler.h"

#include <windows.h>

FpsHandler :: FpsHandler(): Timer()
{

}

FpsHandler :: ~FpsHandler()
{

}

void FpsHandler :: delay()
{
    int frame_time = (1000 / MAX_FPS) - (finish()/1000000);
    if(frame_time>0)
        Sleep((DWORD)frame_time);
}

