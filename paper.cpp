/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description: The Paper Class will have it's own fight function.
 * That will override the Tool base class.
*********************************************************************/
#include "paper.hpp"

Paper::Paper() {
	//set default strength
	this->strength = 1;
	this->type = 'p';
}

Paper::Paper(int userInput){
	//user sets strength
	this->setStrength(userInput);
}

char Paper::fight(Tool *computer) {

	char winner; // 'h', 'c', 't' (human, computer, tie)
	// paper against rock, paper strength is doubled
	if(computer->getType() == 'p') {
		if ((computer->getStrength()) < strength*2)
			winner = 'h';
		else if ((computer->getStrength()) > strength*2)
			winner = 'c';
		else
			winner = 't';
	}//paper vs. scissors, paper strength is halved, or computer is doubled
	else if (computer->getType() == 's') {
		if ((computer->getStrength() * 2) < (strength ))
			winner = 'h';
		else if ((computer->getStrength() * 2) > (strength))
			winner = 'c';
		else
			winner = 't';
	}
	else //paper vs. paper
		winner = 't';

	return winner;
}
