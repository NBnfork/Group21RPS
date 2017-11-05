/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description: The Rock Class will have it's own fight function.
 * That will override the Tool base class.
*********************************************************************/
#include "rock.hpp"

Rock::Rock(){
	this->strength = 1;
	this->type = 'r';
}

Rock::Rock(int userInput){
    //user sets strength
	this->setStrength(userInput);
	}

char Rock::fight(Tool *computer) {

	char winner; // 'h', 'c', 't' (human, computer, tie)
	// rock against paper, rock strength is halved or inversely computer is doubled!
	if(computer->getType() == 'p') {
		if ((computer->getStrength() * 2) < strength)
			winner = 'h';
		else if ((computer->getStrength() * 2) > strength)
			winner = 'c';
		else
			winner = 't';
	}//rock vs. scissors, rock strength is doubled
	else if (computer->getType() == 's') {
		if (computer->getStrength() < (strength * 2))
			winner = 'h';
		else if (computer->getStrength() > (strength *2))
			winner = 'c';
		else
			winner = 't';
	}
	else //rock vs. rock
		winner = 't';

	return winner;
}
