#include "desktop.h"
#include "options.h"

void Desktop::add_option(Options& option) {
    
    options.push_back(new Options(option));
}


double Desktop::price() const{
    double p = 0;
    for(int i=0; i< options.size(); ++i)
    {
    p = p + (options.at(i))->cost();
    }
   
    return p;
}
std::ostream& operator<<(std::ostream& ost, const Desktop& desktop) {
std::string concat;
 for (auto t : desktop.options)
{
    concat=concat+t->to_string() + "\n";
}
    
     ost << "Desktop : " << concat;
    return ost;
}


