#ifndef _TAXFREE_H
#define _TAXFREE_H
#include <iostream>
#include <exception>
#include "Product.h"

class Taxfree: public Product
{
	public:
	Taxfree(std::string name, double cost);
	virtual ~Taxfree();
    double price () const override;
};	
#endif

