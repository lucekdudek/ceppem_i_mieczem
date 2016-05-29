#ifndef _DEBUG
	#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif
#include <iostream>
#include "controller/controller.h"
using namespace std;

int main(int argc, char *argv[])
{
    Controller::getController().run();
    return 0;
}