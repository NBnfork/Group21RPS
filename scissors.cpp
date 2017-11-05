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
	this->type = 's';
}

Scissors::Scissors(int userInput){
	//user sets strength
	this->setStrength(userInput);
}

char Scissors::fight(Tool *computer) {

	char winner; // 'h', 'c', 't' (human, computer, tie)
	// scissors against paper, scissor strength doubled
	if(computer->getType() == 'p') {
		if ((computer->getStrength()) < strength*2)
			winner = 'h';
		else if ((computer->getStrength()) > strength*2)
			winner = 'c';
		else
			winner = 't';
	}//scissors vs. rock, scissors strength is halfed, or computer strength is doubled
	else if (computer->getType() == 'r') {
		if ((computer->getStrength() * 2) < (strength))
			winner = 'h';
		else if ((computer->getStrength() * 2) > (strength))
			winner = 'c';
		else
			winner = 't';
	}
	else //scissors vs. scissors
		winner = 't';

	return winner;
}
