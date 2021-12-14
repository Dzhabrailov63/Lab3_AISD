#include "CMyVector.h"

template class CMyVector<int>;
template class CMyVector<float>;
template class CMyVector<double>;

template class CMyVector<complex<float> >;
template class CMyVector<complex<double>>;


template <typename T> CMyVector<T>::CMyVector(int n) 
{ 
	this->m.resize(n);
}


template <typename T> void         CMyVector<T>::push_back(T v)
{
	m.push_back(v);
}
template <typename T> int          CMyVector<T>::size() const
{
	return m.size();
}

template <typename T> T*         CMyVector<T>::begin()
{
	return &m[0];
}

template <typename T> T* CMyVector<T>::end()
{
	return  &m[size() - 1] + 1;
}




template <typename T> CMyVector<T> CMyVector<T>::operator+(CMyVector<T>& obj)
{
	if (this->m.size() != obj.size()) throw "error operator+ ( )  different size";

	CMyVector temp(this->m.size());

	for (int i = 0; i < this->m.size(); i++)
		temp.m[i] = this->m[i] + obj.m[i];

	return temp;
}
template <typename T> CMyVector<T> CMyVector<T>::operator-(CMyVector<T>& obj)
{
	if (this->m.size() != obj.size()) throw "error operator- ( )  different size";

	CMyVector temp(this->m.size());

	for (int i = 0; i < this->m.size(); i++)
		temp.m[i] = this->m[i] - obj.m[i];

	return temp;
}

template <typename T> T            CMyVector<T>::operator*(CMyVector<T>     obj)
{
	if (this->m.size() != obj.size()) throw "error operator*( )  different size";
	
	T rez = 0;

	if (typeid(obj).name()[16] == 'c')
	{
		for (int i = 0; i < this->m.size(); i++)
		{
			if (typeid(obj.m[0]).name()[19] == 'd')
			{
				complex<double>* c = (complex<double>*)(&obj.m[i]);
				c->_Val[1] = c->_Val[1] * (-1);
				rez = rez + this->m[i] * obj.m[i];
			}
			else
			{
				complex<float>* c = (complex<float>*)(&obj.m[i]);
				c->_Val[1] = c->_Val[1] * (-1);
				rez = rez + this->m[i] * obj.m[i];
			}		
		}

		/*
		2
		1 1
		2 0
		2 1
		0 1
		*/	
	}
	else
	{	
		for (int i = 0; i < this->m.size(); i++)
			rez += this->m[i] * obj.m[i];
	}

	return rez;
}


void fun_1(int*    m, int a)
{
	*m = *m * a;
}
void fun_1(float*  m, int a)
{
	*m = *m * a;
}
void fun_1(double* m, int a)
{
	*m = *m * a;
}
void fun_1(complex<float>* m, int a)
{
	m->_Val[0] = m->_Val[0] * a;
	m->_Val[1] = m->_Val[1] * a;
}
void fun_1(complex<double>* m, int a)
{
	m->_Val[0] = m->_Val[0] * a;
	m->_Val[1] = m->_Val[1] * a;
}

template <typename T> CMyVector<T> CMyVector<T>::operator*(float a)
{	
	CMyVector<T> rez(*this);
	
	for (int i = 0; i < this->m.size(); i++)
		fun_1(&rez.m[i], a);
				
	return rez;
}


void fun_11(int* m, int a)
{
	*m = *m / a;
}
void fun_11(float* m, int a)
{
	*m = *m / a;
}
void fun_11(double* m, int a)
{
	*m = *m / a;
}
void fun_11(complex<float>* m, int a)
{
	m->_Val[0] = m->_Val[0] / a;
	m->_Val[1] = m->_Val[1] / a;
}
void fun_11(complex<double>* m, int a)
{
	m->_Val[0] = m->_Val[0] / a;
	m->_Val[1] = m->_Val[1] / a;
}

template <typename T> CMyVector<T> CMyVector<T>::operator/(float a)
{
	if (a == 0) throw "error operator/()  division by zero";

	CMyVector temp(*this);
	
	for (int i = 0; i < this->m.size(); i++)
		fun_11(&temp[i], a);

	return temp;
}




template <typename T>  T&           CMyVector<T>::operator[](int i) 
{
	if (i >= this->m.size() || i < 0) throw "error operator[] going beyond";
	return m[i];
}