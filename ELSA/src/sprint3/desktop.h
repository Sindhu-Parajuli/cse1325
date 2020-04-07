#ifndef __DESKTOP_H
#define __DESKTOP_H

#include <vector>
#include "options.h"

class Desktop{
  public:
    void add_option(Options& option);
	double price() const;
        Desktop();
        Desktop(std::istream& ist);
        void save(std::ostream& ost);
	friend std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);
    
  private:
	std::vector<Options*> options;
        //std::string& _ist;
	
	
};
#endif
