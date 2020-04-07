#ifndef __ORDER_H
#define __ORDER_H
#include <vector>
#include "customer.h"
#include "desktop.h"
#include "options.h"

class Order {
  public:
    Order(Customer& customer);
	~Order();
	int add_product(Desktop& desktop);
	double price() const;
       // Order();
       Order(std::istream& ist);
         void save(std::ostream& ost);
	friend std::ostream& operator<<(std::ostream& ost, const Order& order);
	
    
  private:
    Customer* _customer;
	std::vector<Desktop*> _products;
	
	
};
#endif

