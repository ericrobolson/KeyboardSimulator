/*
 * KeyboardEventHandler.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: Eric
 */

#include "KeyboardEventHandler.h"
#include <windows.h>

const int KEYEVENT_KEYUP = 0x02;

KeyboardEventHandler::KeyboardEventHandler() {
	_pressedKeysHashTable = new bool[MaxKeys];

	for (int currentHashIndex = 0; currentHashIndex < MaxKeys; currentHashIndex++){
		_pressedKeysHashTable[currentHashIndex] = false;
	}
}

void KeyboardEventHandler::PressKey(Keys k){
	keybd_event(GetKeyCode(k), 0, 0, 0);
}

void KeyboardEventHandler::ReleaseKey(Keys k){
	keybd_event(GetKeyCode(k), 0, KEYEVENT_KEYUP, 0);
}

KeyboardEventHandler::~KeyboardEventHandler() {
	// unpress all currently pressed keys
	for (int currentHashIndex = 0; currentHashIndex < MaxKeys; currentHashIndex++){
		if (_pressedKeysHashTable[currentHashIndex] == true){
			Keys currentKey = static_cast<Keys>(currentHashIndex);

			ReleaseKey(currentKey);
		}
	}

	delete [] _pressedKeysHashTable;
}


int KeyboardEventHandler::GetKeyCode(Keys k){
	// keycodes found on:
	// https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
	switch (k){
		case UpArrow:
			return VK_UP;
		case DownArrow:
			return VK_DOWN;
		case LeftArrow:
			return VK_LEFT;
		case RightArrow:
			return VK_RIGHT;
		case SpaceBar:
			return VK_SPACE;
	}

	return 0;
}
