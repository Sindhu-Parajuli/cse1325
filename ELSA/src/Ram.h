#ifndef __RAM_H
#define __RAM_H

#include "options.h"

class Ram : public Options {
  public:
    Ram(std::string name, double cost, int gb);
    Ram(std::istream& ist);
    std::string to_string() const override;
    void save(std::ostream& ost)const override;

    virtual ~Ram();
    
  protected:
    int _gb;
};

#endif


