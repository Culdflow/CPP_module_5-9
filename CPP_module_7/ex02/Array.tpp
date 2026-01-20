
#include "Array.hpp"

template<typename T>
Array<T>::Array( void ): _size(0)
{
	std::cout << "[Array]: Default Constructor Called" << std::endl;
	_array = NULL;
}

template<typename T>
Array<T>::Array( unsigned int N ): _size(N)
{
	std::cout << "[Array]: Constructor Called" << std::endl;
	_array = new T[N];
}

template<typename T>
Array<T>::Array( Array& copy ): _size(copy.size())
{
	std::cout << "[Array]: Copy Constructor Called" << std::endl;
	_array = new T[copy.size()];
	for (size_t i = 0; i < copy.size(); i++)
	{
		_array[i] = copy[i];
	}
}

template<typename T>
Array<T>::~Array( void )
{
	std::cout << "[Array]: Destructor Called" << std::endl;
	delete [] this->_array;
}

template<typename T>
unsigned int	Array<T>::size()const
{
	return (this->_size);
}