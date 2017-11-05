/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description: This is the implementation file for the Paper class
*********************************************************************/

#ifndef PAPER_HPP
#define PAPER_HPP

#include "tool.hpp"

class Paper : public Tool {

public:
    Paper();

    Paper(int);

    char fight(Tool* computer) override;
};

#endif