#include "store.h"
#include "desktop.h"
#include "order.h"
#include "customer.h"

Store::Store(){}

Store::Store(std::istream& ist){

    try {

    int n1,n2,n3,n4;
    ist >> n1; ist.ignore(32767, '\n');
    while(n1--) customers.push_back(Customer(ist));
    
    ist >> n2; ist.ignore(32767, '\n');
    while(n2--) options.push_back(new Options(ist));
    
    ist >> n3; ist.ignore(32767, '\n');
    while(n3--) desktops.push_back(Desktop(ist));
    
    ist >> n4; ist.ignore(32767, '\n');
    while(n4--) orders.push_back(Order(ist));


  } catch (std::exception& e) {
            cout << "Standard exception: " << e.what() << endl;
        } 


}

void Store::save(std::ostream& ost){

try{
ost << customers.size() << '\n';
for(auto x: customers){
	x.save(ost);
}
ost << options.size() << '\n';
for(auto y : options){
 y->save(ost);
}
ost << desktops.size() << '\n';
for(auto z : desktops){
 z.save(ost);
}
ost << orders.size() << '\n';
for(auto z1 : orders){
 z1.save(ost);
}

 } catch (std::exception& e) {
            cout << "Standard exception: " << e.what() << endl;
        } 

}

void Store::add_customer(Customer& customer) {customers.push_back(customer);}

int Store::num_customers() {return customers.size();}

Customer& Store::customer(int index) {return customers.at(index);}


void Store::add_option(Options& option){options.push_back(new Options(option));}

int Store::num_options() {return options.size();}

Options& Store::option(int index) {return *(options.at(index));}

int Store::new_desktop() {
    int s = desktops.size();
    desktops.push_back(*(new Desktop()));
    return s;}

void Store::add_option(int option,int desktop) {
    (desktops.at(desktop)).add_option(*(options.at(option)));
}

int Store::num_desktops() {return desktops.size();}

Desktop& Store::desktop(int index) {return desktops.at(index);}

int Store::new_order(int customer){

int s = orders.size();

orders.push_back(*(new Order(customers.at(customer))));
return s;
 
}
void Store::add_desktop(int desktop,int order)
  {
      (orders.at(order)).add_product(desktops.at(desktop));
  }
  
int Store::num_orders(){return orders.size();}
  

Order& Store::order(int index) {return orders.at(index);}

