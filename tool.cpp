/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description: Implementation file for Tool class
*********************************************************************/
#include "tool.hpp"

Tool::Tool() {
    //set default strength
    this->strength = 1;
    this->type = 't';
}

Tool::Tool(int userInput) {
    //user sets strength
    this->setStrength(userInput);

}

void Tool::setStrength(int userInput) {
    strength = userInput;
}

char Tool::fight(Tool*) {
    return 0;
}

int Tool::getStrength() {
    return strength;
}

char Tool::getType() {
    return type;
}




