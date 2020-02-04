#include "color.h"
#include <string>

int main()
{
    
Color Purple{106,13,173}; 
Color Torquoise {64,224,208};
Color pink {255,0,255};

std::cout << Purple.colorize("PURPLE!!") << std::endl;
std::cout << Torquoise.colorize("Torquoise!!") << std::endl;
std::cout << pink.colorize("Pinkkk!!") << std::endl;

int _red, _green,_blue;
    
std::cout << "Type an integer for red: "; 
std::cin >> _red; // Get user input from the keyboard

std::cout << "Type an integer for green: "; 
std::cin >> _green; // Get user input from the keyboard

std::cout << "Type an integer for red: "; 
std::cin >> _blue; // Get user input from the keyboard


Color color{_red, _green, _blue};
std::string text = color.to_string();
std::cout<<color.colorize(text)<<std::endl;
   
}
