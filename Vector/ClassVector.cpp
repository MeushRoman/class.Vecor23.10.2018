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
	int *tmp = new int[this->size + 1];
	for (int i = 0, j = 0; i <= size; i++, j++)
	{
		//if (i < index) tmp[i] = this->arr[i]; else if(i == index) 
	}
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

}

void Vector::erase(int index)
{

}

void Vector::print()
{

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
