#include <stdexcept>
#include <limits>
#include <vector>
#include <iomanip>
#include "Taxfree.h"
#include "Taxed.h"

int main()
{
    int quantity, choice;
    
    std::cout << 
           " ============================\n"
            <<
            
            "    Welcome to the Store\n"
               
           <<" ============================\n";
	
	    vector<string> Items{"bread","Milk","Eggs", "Lipbalm","TankTop","ToothPaste"};
        vector<double> vec{1.12, 2.21, 3.33,4.44,3.50,6.00}; 	 

for (int i = 0; i < 6; i++) 
        {
           cout<< i << "." << " " << Items[i]<< " " << vec[i]<<"\n";
        }
		
		Taxfree Bread {"Bread",1.12},  Milk {"Milk",2.21} , Eggs {"Eggs",3.33};
		Taxed Lipbalm {"Lipbalm",4.44} , TankTop {"TankTop",3.50} , ToothPaste {"ToothPaste",6.00};
		
		
	std::vector<Taxed> Taxed_cart;
	std::vector<Taxfree> Taxfree_cart;
do{
	std::cout<< "Input quantity and index of the item you want to purchase" << "\n";
	std::cin >> quantity;
	std::cin>> choice;
	
	 try{
          if (choice <0 || quantity <0) {
              throw 505;
          }
      }
      catch (int e){
          
          cout << "Invalid choice or quantity\n";
          continue;
      }
switch(choice)
	{
		case 0:
	       
		    Bread.set_quantity(quantity);
		    Taxfree_cart.push_back(Bread);
		    break;
		
	
	   case 1:
	
		Milk.set_quantity(quantity);
	    Taxfree_cart.push_back(Milk);
	break;
	
	  case 2:
	
	
		Eggs.set_quantity(quantity);
		Taxfree_cart.push_back(Eggs);
	break;
	case 3:
	
		Lipbalm.set_quantity(quantity);
		Taxed_cart.push_back(Lipbalm);
	break;	
	
	case 4:
	
		TankTop.set_quantity(quantity);
		Taxed_cart.push_back(TankTop);
	break;
	case  5:
	
		ToothPaste.set_quantity(quantity);
		Taxed_cart.push_back(ToothPaste);
	break;
	}
cout<< "Current Order"<<endl;
cout<< "-----------" <<endl;
	double Totalcost = 0;
for (int i=0 ; i<Taxed_cart.size() ; i++)
	{
	

	cout<< Taxed_cart[i] << endl;
	Totalcost = Totalcost + Taxed_cart[i].price();
	
	}
	for (int i=0 ; i<Taxfree_cart.size() ; i++)
	{
	    

	cout << Taxfree_cart[i] << endl;
    Totalcost = Totalcost + Taxfree_cart[i].price();
	}
	
	cout<<"The Total Cost :" << fixed <<std::setprecision(2)<< Totalcost <<"\n\n";
        
	} while(quantity!=0);
}



