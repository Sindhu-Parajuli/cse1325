#ifndef _COLOR_H
#define _COLOR_H

#include <iostream>
#include <string>

class Color
{
private:
int _red;
int _green;
int _blue;
bool _reset;

public:
Color();
Color(int red, int green, int blue);
std::string to_string();
friend std::ostream &operator<<(std::ostream &os, const Color &color);
friend std::istream &operator>>(std::istream &ist, Color &color);
};
#endif
