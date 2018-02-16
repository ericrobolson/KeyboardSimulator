/*
 * main.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: Eric
 */

#include "KeyboardEventHandler\KeyboardEventHandler.h"
#include <iostream>
using namespace std;

int main(){
	int wait = 0;
	while (wait < 10000){
		wait++;
		cout << "waiting" << wait <<      endl;
	}

	KeyboardEventHandler keyboard;

	for (int i = 0; i < 1000; i++){
		keyboard.PressKey(SpaceBar);
	}

	return 0;
}
