#include <iostream>
#include "ClassVector.h"

using namespace std;

void main() {

	Vector *v = Vector::getInctance(5);


	//Vector v(10, 7);
	//*v.insert(5, 1);
	//cout << v << endl;
	//v.erase(5);
	//cout << v;*/
	//
	//Vector v2(5,3);

	//v2 += v;

	cout << *v;


	system("pause");
}