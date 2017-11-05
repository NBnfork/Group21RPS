/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description: This is the implementation file of the Tool Class.
*********************************************************************/
#ifndef TOOL_HPP
#define TOOL_HPP

class Tool {

protected:

    int strength;
    char type;

public:
    Tool();

    Tool(int);

    void setStrength(int);

    int getStrength();
	char getType();
    virtual char fight(Tool*);
};

#endif
