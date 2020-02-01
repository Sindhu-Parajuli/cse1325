#include <iostream>

int main() {
    std::cout << "\033[38;2;128;180;20m" // Sets color to 0 red, 100 green, 177 blue
              << "Light Green"             // Text to print in the above color
              << "\033[0m"              // Resets terminal to default state
              << std::endl;             // Newline and flushes the output buffer

std::cout << "\033[38;2;38;150;140m" // Sets color to 0 red, 100 green, 177 blue
              << "Turquoise!!"             // Text to print in the above color
              << "\033[0m"              // Resets terminal to default state
              << std::endl;             // Newline and flushes the output buffer

std::cout << "\033[38;2;128;0;128m" // Sets color to 0 red, 100 green, 177 blue
              << "Hot Pink!!"             // Text to print in the above color
              << "\033[0m"              // Resets terminal to default state
              << std::endl;             // Newline and flushes the output buffer

//std::cout << red.colorize("Red") << std::endl


int _red;
int _green;
int _blue;
std::cout << "Type an integer for red: "; 
std::cin >> _red; // Get user input from the keyboard

std::cout << "Type an integer for green: "; 
std::cin >> _green; // Get user input from the keyboard

std::cout << "Type an integer for red: "; 
std::cin >> _blue; // Get user input from the keyboard

}

