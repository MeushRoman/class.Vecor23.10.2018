#include <iostream>
#include "ClassVector.h"

using namespace std;

void main() {

	Vector v(10, 7);
	v.insert(5, 1);
	cout << v << endl;
	v.erase(5);
	cout << v;
	
	system("pause");
}