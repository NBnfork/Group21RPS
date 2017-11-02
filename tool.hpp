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

    virtual void setStrength(int);
    
    virtual int getStrength();

    //virtual as it will be overridden by each different type
    virtual char fight(char type);// will return fight results
};

#endif
