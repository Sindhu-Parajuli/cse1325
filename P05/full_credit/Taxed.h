#include <iostream>
#include <exception>
#include <string>

#ifndef _TAXED_H
#define _TAXED_H

#include "Product.h"


class Taxed: public Product
{
	private:
	static double _tax;
	
	public:
	Taxed(string name, double cost);
	virtual ~Taxed();
	double price () const override;
	static void set_tax_rate(double sales_tax);
	
};

#endif
