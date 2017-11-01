/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description: The Scissors Class will have it's own fight function.
 * That will override the Tool base class.
*********************************************************************/
#include "scissors.hpp"

Scissors::Scissors() {
	//set default strength
	this->strength = 1;
}

Scissors::Scissors(int userInput) {
//user sets strength
	this->setStrength(userInput);
}

void Scissors::setStrength(int userInput) {
	strength = userInput;
}

char Scissors::fight(char computer) {
	char winner; // 'h', 'c', 't' (human, computer, tie)
	//TODO

	return winner;
}