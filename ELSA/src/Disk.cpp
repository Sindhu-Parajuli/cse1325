#include "Disk.h"

Disk::Disk(std::string name, double cost, int gb)
    :Options{name,cost},_gb{gb} {}

    

Disk::~Disk() { }

// File I/O
Disk::Disk(std::istream& ist) : Options(ist) {
   std::string gb; 
   
  getline(ist, gb);

  _gb = std::stod(gb);
     
}

std::string Disk::to_string() const 
{
   return std::to_string(_gb) + " GB " + " " + _name + " , " +std::to_string(_cost);
}


void Disk::save(std::ostream& ost) const {
Options::save(ost);
ost << std::to_string(_gb) << std::endl;

}


