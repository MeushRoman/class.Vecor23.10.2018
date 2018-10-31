#pragma once
#include<iostream>
using namespace std;

class Vector
{
	int *arr;
	int size;

	
	Vector() = default;
	static Vector*inctance;
	Vector(int size, int element = 0);

public:

	static Vector*getInctance(int size) {
		if (inctance == nullptr)
			inctance = new Vector(size);

		return inctance;
	}

	Vector(const Vector&) = delete;
	Vector&operator=(const Vector&) = delete;

	Vector();
	Vector(const Vector&obj);
	Vector(int size, int element = 0);

	bool empty() const;

	int getSize() const;
	int &operator[](int index) const;

	void insert(int index, int number);
	void clear();
	void push_back(int number);
	void pop_back();
	void erase(int index);

	Vector& operator=(const Vector&obj);
	Vector& operator+=(const Vector&v);

	//перемещение
	Vector(Vector&&v);
	Vector & operator=(Vector&&v);

	~Vector();
};

Vector*Vector::inctance = nullptr;

ostream & operator<<(ostream &os, const Vector&v);
istream & operator>>(istream&is, Vector&v);

//Vector operator+(const Vector&a, const Vector&b) {
//
//	Vector n = a;
//	n += b;
//
//	return move(n);
//}
