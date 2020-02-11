#include "color.h"
#include <iostream>
#include <string>
using namespace std;


Color::Color():_reset{true}
{
 
}

Color::Color(int red, int green, int blue):_red(red), _green(green), _blue(blue),_reset{false} 
{

}

std::string Color::to_string(){
    return "(" + std::to_string(_red) + "," +  std::to_string(_green) +"," +  std::to_string(_blue) + ")";
   
}
std::ostream &operator<<(std::ostream &ost, const Color &color) {

if (color._reset)
{
 ost << "\033[0m";
}
else
{

ost << "\033[38;2;"+std::to_string(color._red)+";"+std::to_string(color._green)+";"+std::to_string(color._blue)+"m";

}
return ost;
}

std::istream &operator>>(std::istream &ist, Color &color) {

    ist >> color._red >> color._green >> color._blue; 
	color._reset=false;
    return ist;

}
