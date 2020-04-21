#ifndef __CPU_H
#define __CPU_H

#include "options.h"

class Cpu : public Options {
  public:
    Cpu(std::string name, double cost, int gb);
    Cpu(std::istream& ist);
    std::string to_string() const override;
    void save(std::ostream& ost) const override;

     virtual ~Cpu();
    
  protected:
    int _gb;
};

#endif


