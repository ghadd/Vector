#pragma once

#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>
typedef unsigned int uint;

template <class T>
class Vector
{
public:
	Vector<T>();
	Vector<T>(uint _size);
	Vector<T>(uint _size, T _value);
	~Vector<T>();

	void resize(uint _newsize);
	void insert(T _value, uint _pos);
	void push_back(T _value);
	void push_front(T _value);
	void erase(uint _pos);
	void pop_back();
	void pop_front();

	uint get_size();

	T operator[](uint index);

protected:
	T* obj;
	uint size;
};

template <class T>
Vector<T>::Vector() {
	this->obj = (T*)malloc(1);
	this->size = 0;
}

template <class T>
Vector<T>::Vector(uint _size) {
	this->obj = (T*)malloc(sizeof(T) * _size);
	this->size = 0;
}

template <class T>
Vector<T>::Vector(uint _size, T _value) {
	this->obj = (T*)malloc(sizeof(T) * _size);
	this->size = _size;
	for (int i = 0; i < _size; i++) {
		obj[i] = _value;
	}
}

template <class T>
Vector<T>::~Vector() { free(obj); }

template <class T>
void Vector<T>::resize(uint _newsize) {
	if (this->size > _newsize) {
		this->size = _newsize;
		free(this->obj + _newsize);
	}
	else {
		this->obj = (T*)realloc(this->obj, sizeof(T) * _newsize);
	}
}

template <class T>
void Vector<T>::insert(T _value, uint _pos) {
	this->size++;
	this->resize(this->size + 1);
	for (int i = this->size; i > _pos; i--) {
		this->obj[i] = this->obj[i - 1];
	}
	this->obj[_pos] = _value;
}

template <class T>
void Vector<T>::erase(uint _pos) {
	for (int i = _pos; i < size - 1; i++) {
		this->obj[i] = this->obj[i + 1];
	}
	this->resize(--this->size);
}

template <class T>
void Vector<T>::pop_back() { erase(this->size); }

template <class T>
void Vector<T>::pop_front() { erase(0); }

template <class T>
void Vector<T>::push_back(T _value) { insert(_value, this->size); }

template <class T>
void Vector<T>::push_front(T _value) { insert(_value, 0); }

template <class T>
T Vector<T>::operator[](uint index) { return *(this->obj + index); }

template <class T>
uint Vector<T>::get_size() { return this->size; }

#endif // !VECTOR_H