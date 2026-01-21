#pragma once

#include <iostream>
#include <cmath>
#include <vector>

class Span
{
	private:
		unsigned int	_N;
		int				_nb_el;
		int*			_span;
		int				_smallestNb;
		int				_biggestNb;
	public:
		Span( void );
		Span( unsigned int N );
		~Span( void );
		Span( const Span& copy );

		Span&	operator=( const Span& src );

		void addNumber( int nb );
		template<typename T>
		void addRange(T first, T last)
		{
			for (; first != last; ++first)
			{
				try{
					addNumber(*first);
				}catch (const Span::SpanAlreadyFullException& e)
				{
					std::cerr << "[Span]: Span Full Can't Add: " << *first << std::endl;
				}
			}
		}
		int	shortestSpan( void );
		int	longestSpan( void );


		unsigned int	getN( void )const;
		int				getNbEl( void )const;
		int*			getSpan( void )const;
		int				getSmallestNb( void )const;
		int				getBiggestNb( void )const;

	
	class SpanAlreadyFullException: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Span already full");
			}
	};
	class NoSpanCanBeFoundException: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("No spam could be found");
			}
	};
};