#include <iostream>
#include <exception>
#ifndef _COIN_H
#define _COIN_H


enum class Coin_size{PENNY,NICKEL,DIME,QUARTER};
typedef int Year;

class Coin
{
private:
Coin_size _size;
Year _year;
std::string* _notes;

public:

Coin();

Coin(Coin_size size, Year year, char* notes);

Coin(const Coin&rhs);

Coin& operator=(const Coin& rhs);

~Coin();
void add_node(std::string a);

friend std::ostream&operator<<(std::ostream&os, const Coin& coin);

friend std::istream&operator<<(std::istream&is, const Coin& coin);


};
#endif




//////////////////////////////////////////////////////////
#include <iostream>
#include <exception>
#ifndef _COIN_H
#define _COIN_H


enum class Coin_size{PENNY,NICKEL,DIME,QUARTER};

std::ostream &operator<<(std::ostream &ost, const Coin_size& coin) 
{
    {Coin_size::PENNY,"0.1"},
    {Coin_size::NICKEL,"0.1"},
    {Coin_size::DIME,"0.1"},
    {Coin_size::QUARTER,"0.1"},
};

ost << coin;
return ost;



typedef int Year;

class Coin
{
private:
Coin_size _size;
Year _year;
char* _notes;

public:

Coin();

Coin(Coin_size size, Year year, char* notes);

};
#endif




