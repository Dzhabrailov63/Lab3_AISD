#pragma once

#include <iostream>
#include <initializer_list> 
#include <complex>
#include <vector>

using namespace std;


template<typename T>
class CMyVector
{
private:
	vector<T>   m;

public:
	CMyVector(int);


	int  size() const;
	void push_back(T v);
	T* begin();
	T* end();
	  

	CMyVector<T> operator+(CMyVector<T>& obj);
	CMyVector<T> operator-(CMyVector<T>& obj);

	T operator*(CMyVector<T> obj);

	CMyVector<T> operator*(float a);
	CMyVector<T> operator/(float a);
		
	 T&       operator [ ](int i) ;

	template <typename T> friend  T            operator*(float a, T obj);
};


