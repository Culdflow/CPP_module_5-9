#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

template <typename T>
class Array
{
	public:
		Array( void );
		Array( unsigned int N );
		Array( Array& copy );
		~Array( void );

		Array&	operator=( const Array& src )
		{
			if (this->_array != NULL)
				delete [] this->_array;
			if (src.size() > 0)
			{
				this->_array = new T[src.size()];
				for (size_t i = 0; i < src.size(); i++)
				{
					this->_array[i] = src[i];
				}
				this->_size = src.size();
			}
			else
			{
				this->_array = NULL;
				this->_size = 0;
			}
			return *this;
		}
		T&	operator[]( size_t index )const
		{
			if (index >= this->size() || this->_array == NULL)
			{
				std::cout << index;
				throw IndexOutOfRange();
			}
			return (this->_array[index]);
		}

		unsigned int size() const;
		class IndexOutOfRange : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
		T* 				_array;
		unsigned int	_size;
};

template< typename T >
const char	*Array<T>::IndexOutOfRange::what() const throw()
{
	return ("[ERROR]: Index Out Of Range");
}

#include "Array.tpp"