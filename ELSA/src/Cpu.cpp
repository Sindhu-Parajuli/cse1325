#include "Cpu.h"

Cpu::Cpu(std::string name, double cost, int gb)
    :Options{name,cost},_gb{gb} {}

    

Cpu::~Cpu() { }

// File I/O
Cpu::Cpu(std::istream& ist) : Options(ist) {
   std::string gb; 
   
  getline(ist, gb);

  _gb = std::stod(gb);
     
}

std::string Cpu::to_string() const 
{
  return  std::to_string(_gb) + " GB " + " " + _name + " , " +std::to_string(_cost);
}


void Cpu::save(std::ostream& ost) const {
Options::save(ost);
ost << std::to_string(_gb) << std::endl;

}



