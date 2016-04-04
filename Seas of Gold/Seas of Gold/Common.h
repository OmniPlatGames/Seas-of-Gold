// Common.h
//
// Holds Things that will be used throughout the program
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#include "vector3d.h"
#include "vector2d.h"
#include "irrString.h"
#include <map>
#include <vector>
#include <Windows.h>
#include <irrlicht.h>
#include "driverChoice.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

typedef irr::core::vector3d<float> v3d;
typedef irr::core::vector2d<float> v2d;
typedef irr::core::string<char> irrstring;
//typedef std::map<int, int> inventory;

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;