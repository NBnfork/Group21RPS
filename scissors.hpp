/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description: This is the implementation file for the Scissors class
*********************************************************************/

#ifndef SCISSORS_HPP
#define SCISSORS_HPP

#include "tool.hpp"

class Scissors : public Tool {

public:
    Scissors();

    Scissors(int);

    char fight(Tool *computer) override ;



};

#endif