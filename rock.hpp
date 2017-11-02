/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description: This is the implemenation file for the Rock class
*********************************************************************/

#ifndef ROCK_HPP
#define ROCK_HPP

#include "tool.hpp"

class Rock : public Tool{

public:
    Rock();

    Rock(int);

    void setStrength(int);

    char fight(char type) override;

};

#endif