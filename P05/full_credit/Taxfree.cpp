#include "Taxfree.h"
#include "Product.h"

Taxfree::Taxfree(std::string name, double cost):Product(name,cost)
{
	
}
 
Taxfree::~Taxfree(){};
double Taxfree::price () const 
 {
return  _quantity*_cost;

 }

