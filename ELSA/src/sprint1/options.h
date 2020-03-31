#ifndef _OPTIONS_H
#define _OPTIONS_H
#include <iostream>

using namespace std;

class Options{
  protected:
  string _name;
  double _cost;
  
public: 
 Options(std::string name, double cost);
~Options();
double cost();
virtual std::string to_string() const;

friend std::ostream& operator<<(std::ostream& ost, const Options& options);
   
};
#endif
