/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description: Implementation file for Tool class
*********************************************************************/
#include "tool.hpp"

/*********************************************************************
 * Default constructor for the Tool class
*********************************************************************/
Tool::Tool() {
    //set default strength
    this->strength = 1;
    this->type = 't';
}

/*********************************************************************
 * Constructor for the Tool class, takes the users input to set the
 * strength
 * @param userInput is the users chosen strength
*********************************************************************/
Tool::Tool(int userInput) {
    //user sets strength
    this->setStrength(userInput);
}

/*********************************************************************
 * Sets strength
 * @param userInput is the strength
*********************************************************************/
void Tool::setStrength(int userInput) {
    strength = userInput;
}

/*********************************************************************
 * Should not be called
*********************************************************************/
char Tool::fight(Tool *) {
    return 0;
}

/*********************************************************************
 * Returns strength
*********************************************************************/
int Tool::getStrength() {
    return strength;
}

/*********************************************************************
 * Returns type
*********************************************************************/
char Tool::getType() {
    return type;
}




