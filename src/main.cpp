//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include <iostream>
#include "controller/controller.h"
#include "model\items\wearable.h"
using namespace std;

int main(int argc, char *argv[])
{
    Controller::getController().run();
    return 0;
}