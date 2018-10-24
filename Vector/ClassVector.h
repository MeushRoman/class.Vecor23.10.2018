#pragma once
#include<iostream>
using namespace std;

class Vector
{
	int *arr;
	int size;
public:

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
	void print();
	Vector& operator=(const Vector&obj);

	~Vector();
};

ostream &operator<<(ostream &os, const Vector&v);
istream & operator>>(istream&is, Vector&v);

