#ifndef _PRODUCT_H
#define _PRODUCT_H
#include <iostream>
using namespace std;

class Product {
  protected:
  string _name;
  int _quantity;
  double _cost;
  
public: 
virtual double price()const = 0;
Product(string name, double cost);
~Product();
void set_quantity(int quantity);
friend std::ostream& operator<<(std::ostream& ost, const Product& product);
   
};

#endif

 
