#include "options.h"
#include "customer.h"
#include <string>
#include <iomanip>
#include <iostream>
#include "desktop.h"
#include "order.h"
#include "Ram.h"
#include "Cpu.h"
#include "Disk.h"

Options::Options(std::string name, double cost)
    : _name{name}, _cost{cost} {}
	
Options::~Options() 
{ 
   
} 

double Options::cost() {
  
    return _cost;
}




std::string Options::to_string() const{
    return  _name + ", " + "$" + std::to_string(_cost);
   
}


Options::Options(std::istream& ist) {
 std::string cost;
 getline(ist, _name);
 getline(ist, cost);

 _cost = std::stod(cost);

}

void Options::save(std::ostream& ost) const{

 ost << _name << std::endl;
 ost << std::to_string(_cost) << std::endl; 

}

std::ostream& operator<<(std::ostream& ost, const Options& options){
	ost << options.to_string();
	
	return ost;
	
}

