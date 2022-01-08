#include"Node.h"

template<typename T>
class IList
{

	virtual void add(T t) = 0;

	virtual void remove(int index) = 0;

	virtual void remove(T t) = 0;

	virtual bool contains(T t) = 0;

	virtual bool isEmpty() = 0;

	virtual int indexOf(T t) = 0;

	virtual int size() = 0;

	virtual T* get(int index) = 0;

};

