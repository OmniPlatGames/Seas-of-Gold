// 
// Input.h
//
// This is a header file that contains the following: Input Class
#pragma once

#include <irrlicht.h>

// Input Enum to tell the mouse handler whether you want a lmb or rmb input
enum eInput {LMB, RMB};

// Input Class
// Quick tutorial below this class
class Input : public irr::IEventReceiver
{
public:
	Input(); // Constructor
	virtual bool OnEvent(const irr::SEvent& event); // Not used in the program 
													// But it keeps track of inputs

	virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const; // Ask if a key is down 
														  // returns true if so

	virtual bool IsMBDown(int MB) const; // Ask if a mouse button is down 
										 // returns true if so

	virtual irr::core::vector2df GetMousePosition() const; // Get mouse cursor position

private:
	bool m_KeyIsDown[irr::KEY_KEY_CODES_COUNT]; // Whether or not a key is down

	bool m_MBIsDown[2]; // Whether or not a mouse button is pressed

	irr::core::vector2df m_MPosition; // Mouse position
};

/*
How to use:

//Create the Input Object.

	Input in;

//Modify the irrlichtDevice creation to use it.

	IrrlichtDevice *device =
		createDevice(video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16,
		false, false, false, in); <---- Input added here

Ask for inputs in the main run loop.
	
	// Keyboard
	if(in.IsKeyDown(irr::KEY_KEY_W))
		// Do something

	// Mouse Button
	if(in.IsMBDown(LMB))
		// Do something

	// Mouse Position
	irr::core::vector2df mousePos = in.GetMousePosition();
*/