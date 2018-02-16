/*
 * KeyboardEventHandler.h
 *
 *  Created on: Feb 15, 2018
 *      Author: Eric
 */

#ifndef SRC_KEYBOARDEVENTHANDLER_KEYBOARDEVENTHANDLER_H_
#define SRC_KEYBOARDEVENTHANDLER_KEYBOARDEVENTHANDLER_H_

enum Keys{ UpArrow, DownArrow, LeftArrow, RightArrow, SpaceBar};
const int MaxKeys = 100;


class KeyboardEventHandler {
private:
	bool * _pressedKeysHashTable;
	int GetKeyCode(Keys k);

public:
	KeyboardEventHandler();

	void PressKey(Keys k);
	void ReleaseKey(Keys k);

	virtual ~KeyboardEventHandler();
};

#endif /* SRC_KEYBOARDEVENTHANDLER_KEYBOARDEVENTHANDLER_H_ */
