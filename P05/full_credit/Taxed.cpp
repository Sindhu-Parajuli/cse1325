#include "Taxed.h"
#include "Product.h"
using namespace std;

Taxed::Taxed(string name, double cost):Product(name,cost){}
 
Taxed::~Taxed(){}
  
  double Taxed::_tax = 0.0825;
  
 void Taxed::set_tax_rate(double sales_tax)
 {
	 
	 _tax = sales_tax;
	 
 }
 
 double Taxed::price () const 
 {
	 return _quantity*_cost * (1+_tax);
 }
 
