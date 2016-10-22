﻿#pragma once
#include <stdlib.h>

//This a generically typed resizable array of a single type... In this case, the type is referenced using "T" (CSC161 level)
template<typename T>
class vector {
	long unsigned int d_size; // Stores no. of actually stored objects
	long unsigned int d_capacity; // Stores allocated capacity
	T *d_data; // Stores data
	
public:
	vector() : d_size(0), d_capacity(0), d_data(0) {}; // Default constructor

	vector(vector const &other) : d_size(other.d_size), d_capacity(other.d_capacity), d_data(0) {

		d_data = static_cast<T *>(malloc(d_capacity * sizeof(T)));
		memcpy(d_data, other.d_data, d_size * sizeof(T));
	}; // Copy constuctor

	~vector() {
		delete[] d_data;
		//free(d_data);
	}; // Destructor
	bool contains(T thing) {
		for (auto i = 0; i < d_size; i++) {
			if (d_data[i] == thing) return true;
		}
		return false;
	}
	vector &operator=(vector const &other) {
		//free(d_data); 
		delete[] d_data;
		d_size = other.d_size;
		d_capacity = other.d_capacity;
		d_data = static_cast<T*>(malloc(d_capacity * sizeof(T)));
		memcpy(d_data, other.d_data, d_size * sizeof(T));
		return *this;
	}; // Needed for memory management

	void push_back(T const &x) {

		if (d_capacity == d_size) resize();
		d_data[d_size++] = x;
	}; // Adds new value. If needed, allocates more space

	long unsigned int size() const {

		return d_size;
	}; // Size getter

	T const &operator[](long unsigned int idx) const {

		return d_data[idx];
	}; // Const getter
	T &operator[](long unsigned int idx) {

		return d_data[idx];
	}; // Changeable getter

private:
	void resize() {
		d_capacity = d_capacity ? d_capacity * 2 : 1;
		T *newdata = static_cast<T *>(malloc(d_capacity * sizeof(T)));
		memcpy(newdata, d_data, d_size * sizeof(T));
		//delete[] d_data;
		free(d_data);
		d_data = newdata;
	};// Allocates double the old space
};