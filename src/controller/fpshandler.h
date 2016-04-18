#ifndef CEPEM_I_MIECZEM_FPSHANDLER_H
#define CEPEM_I_MIECZEM_FPSHANDLER_H

#include "timer.h"

class FpsHandler : public Timer
{
public:
    FpsHandler();
    ~FpsHandler();
    void delay();
private:
    static const int MAX_FPS = 60;
};

#endif //CEPEM_I_MIECZEM_FPSHANDLER_H
