/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description: The Rock Class will have it's own fight function.
 * That will override the Tool base class.
*********************************************************************/
#include "rock.hpp"

Rock::Rock(){
	//set default strength
	this->strength = 1;
}

Rock::Rock(int userInput) : Tool() {
    //user sets strength
	this->setStrength(userInput);
}

char Rock::fight(char computer) {
	char winner; // 'h', 'c', 't' (human, computer, tie)

	//TODO

	return winner;
}
