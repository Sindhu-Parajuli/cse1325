#ifndef _COLOR_H
#define _COLOR_H

#include <iostream>

class Color
{
private:
int _red;
int _green;
int _blue;

public:
Color(int red, int green, int blue);
std::string to_string();
std::string colorize(std::string text);
};
#endif
