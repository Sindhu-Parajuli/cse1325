#ifndef _COLOR_H
#define _COLOR_H

#include <iostream>

Class Color
{
private:
int _red;
int _green;
int _blue;
public:
Color(int _red,int _green, int _blue);
std::string to_string();
std::string colorize(std::string text);
};
#endif
