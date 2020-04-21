#include "Ram.h"

Ram::Ram(std::string name, double cost, int gb)
    :Options{name,cost},_gb{gb} {}

    

Ram::~Ram() { }

// File I/O
Ram::Ram(std::istream& ist) : Options(ist) {
   std::string gb; 
   
  getline(ist, gb);

  _gb = std::stod(gb);
     
}

std::string Ram::to_string() const 
{
    return  std::to_string(_gb) + " GB " + " " + _name + " , " +std::to_string(_cost);
}


void Ram::save(std::ostream& ost) const {
Options::save(ost);
ost << std::to_string(_gb) << std::endl;

}








