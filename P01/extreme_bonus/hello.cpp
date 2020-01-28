#include <iostream>
#include <stdlib.h>
using namespace std;

int main() 
{
	cout << "Hello " << getenv("USER") << "!" << endl;
	return 0;
}
