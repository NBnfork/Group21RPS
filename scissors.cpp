/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description: The Scissors Class will have it's own fight function.
 * That will override the Tool base class.
*********************************************************************/
#include "scissors.hpp"

/*********************************************************************
 * Default constructor for scissor class
*********************************************************************/
Scissors::Scissors() {
    //set default strength
    this->strength = 1;
    this->type = 's';
}

/*********************************************************************
 * Constructor that sets strength for tool based on input
 * @param userInput is the strength chosen by the user.
*********************************************************************/
Scissors::Scissors(int userInput) : Tool(userInput){
    //user sets strength
    this->type = 's';
}

/*********************************************************************
 * The fight function returns who wins based on what two tools are
 * fighting.
 * @param computer is the Tool that is being faught
*********************************************************************/
char Scissors::fight(Tool *computer) {

    char winner; // 'h', 'c', 't' (human, computer, tie)
    // scissors against paper, scissor strength doubled
    if (computer->getType() == 'p') {
        if ((computer->getStrength()) < strength * 2)
            winner = 'h';
        else if ((computer->getStrength()) > strength * 2)
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
    } else //scissors vs. scissors
        winner = 't';

    return winner;
}
