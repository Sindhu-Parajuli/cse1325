#include "desktop.h"
#include "options.h"

void Desktop::add_option(Options& option) {
    
    options.push_back(&option);
}


double Desktop::price() const{
    double p = 0;
    for(int i=0; i< options.size(); ++i)
    {
    p = p + (options.at(i))->cost();
    }
   
    return p;
}

Desktop::Desktop(){}
 
Desktop::Desktop(std::istream& ist)

{
int n2;
 ist >> n2; ist.ignore(67278, '\n');
    while(n2--) options.push_back(new Options(ist));


}


void Desktop::save(std::ostream& ost)
{

ost << options.size() << '\n';
for(auto y : options){
 y->save(ost);


}
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


