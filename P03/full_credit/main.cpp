#include "color.h"
#include <string>

int main()
{
    
Color Purple{106,13,173}; 
Color Torquoise {64,224,208};
Color pink {255,0,255};
Color reset;

std::cout << Purple << "My first Favourite Purple!!" << std::endl;
std::cout << Torquoise << "My love Torquoise!!" << std::endl;
std::cout << pink << "Who doesn't love Pinkkk!!" << reset << std::endl;
Color value;
std::cout << "Type the RGB integers that you want to be colored!: "; 
std::cin >> value; // Get user input from the keyboard
std::cout << value << value.to_string() << std::endl; 

return 0;

}
