#include "ClassVector.h"

Vector::Vector()
{
	arr = nullptr;
	size = 0;
}

Vector::Vector(const Vector &obj)
{
	if (obj.size == 0) {
		this->arr = nullptr;
		this->size = 0;
		return;
	}
	this->arr = new int[obj.size];
	for (int i = 0; i < obj.size; i++)
	{
		this->arr[i] = obj.arr[i];
	}

	this->size = obj.size;
}

Vector::Vector(int size, int element) 
{
	if (size <= 0) return;

	this->arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = element;
	}
	this->size = size;
}

bool Vector::empty() const
{
	return size == 0;
}

int Vector::getSize() const
{
	return this->size;
}

int& Vector::operator[](int index) const
{
	return this->arr[index];
}

void Vector::insert(int index, int number)
{
	if (this->size <= 0 || index < 0 || index >= this->size) return;
	int *tmp = new int[size + 1];
	for (int i = 0, j = 0; i < size + 1; i++, j++)
	{
		if (i == index)
		{
			tmp[i] = number;
			j--;
		}
		else tmp[i] = this->arr[j];
	}
	delete[] this->arr;
	this->arr = tmp;
	this->size++;
}

void Vector::clear()
{
	this->~Vector();
}

void Vector::push_back(int number)
{
	int* tmp = new int[size + 1];
	for (int i = 0; i < size; i++)
		tmp[i] = arr[i];
	tmp[size] = number;
	delete[] arr;
	arr = tmp;
	this->size++;
}

void Vector::pop_back()
{
	if (this->size <= 0) return;
	if (this->size == 1) {
		this->~Vector();
		return;
	}

	int *tmp = new int[size - 1];

	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = this->arr[i];
	}
	delete[]this->arr;
	this->arr = tmp;
	this->size--;
}

void Vector::erase(int index)
{
	if (this->size <= 0 || index < 0 || index >= this->size) return;

	int *tmp = new int[size - 1];
	for (int i = 0, j = 0; i < size - 1; i++, j++)
	{
		if (i == index) j++;

		tmp[i] = this->arr[j];
	}
	delete[]this->arr;
	this->arr = tmp;
	this->size--;
}


Vector & Vector::operator=(const Vector & obj)
{
	if (this == &obj) return *this;
	
	if (obj.size == 0) { this->~Vector(); return *this; }
	if (obj.size!=this->size) {}
	if (this->size != obj.size) {

		this->~Vector();
		this->size = obj.size;
		this->arr = new int[this->size];
	}

	for (int i = 0; i < obj.size; i++)
	{
		this->arr[i] = obj.arr[i];
	}
	return *this;
}

Vector::~Vector()
{
	if (this->arr != nullptr) delete[]this->arr;
	this->arr = nullptr;
	this->size = 0;
}

ostream & operator<<(ostream & os, const Vector & v)
{
	for (int i = 0; i < v.getSize(); i++)
	{
		os << v[i] << " ";
	}

	return os;
}

istream & operator>>(istream&is, Vector&v) {
	for (int i = 0; i < v.getSize(); i++)
	{
		is >> v[i];
	}

	return is;
}
