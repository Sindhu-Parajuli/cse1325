#ifndef __DISK_H
#define __DISK_H

#include "options.h"

class Disk : public Options {
  public:
    Disk(std::string name, double cost, int gb);
    Disk(std::istream& ist);
    std::string to_string() const override;
    void save(std::ostream& ost) const override;

     virtual ~Disk();
    
  protected:
    int _gb;
};

#endif


