#include "desktop.h"
#include "order.h"
#include <vector>

Order::Order(Customer& customer) : _customer{&customer}
{

}

Order::~Order() 
{ 
   
} 

int Order::add_product(Desktop& desktop) {_products.push_back(new Desktop(desktop));}
double Order::price() const{
    double p = 0.0;
    for(int i=0; i<_products.size(); ++i) 
    {
        p = p +  _products.at(i)->price();
    }
    return p;
}


Order::Order(std::istream& ist) {
_customer = new Customer(ist);
 int n3;
ist >> n3; ist.ignore(32767, '\n');
 while(n3--) _products.push_back(new Desktop(ist));


}


void Order::save(std::ostream& ost){

_customer->save(ost);
ost << _products.size() << '\n';
for(auto z : _products){
 z->save(ost);

}
}


std::ostream& operator<<(std::ostream& ost, const Order& order) {
  ost<< "Customer in line " << "\n"<< *order._customer<<"\n";
  
    for (auto t : order._products)
{
    ost<< *t;
}
    
     ost << "Total cost is " << order.price();
    return ost;
}

 


