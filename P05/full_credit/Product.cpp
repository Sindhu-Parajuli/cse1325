#include <iostream>
using namespace std;
#include "Product.h"


Product::Product(std::string name, double cost): _name{name}, _cost{cost}, _quantity{0}
{

}

Product::~Product() 
{ 
   
} 
// set_quantity simply assigns its parameter to the _quantity attribute

void Product::set_quantity(int quantity) {
   _quantity = quantity;
 
}

std::ostream& operator<<(std::ostream& ost, const Product& product) {
     ost << product. _name + "(" + to_string(product._quantity) + "@" + to_string(product._cost) + ")";
	 return ost;
	 
}

