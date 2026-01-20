#pragma once

#include <iostream>

class Span
{
	public:
		Span( void );
		Span( unsigned int N );
		~Span( void );
		Span( Span& copy );

		Span&	operator=( const Span& src );

		void addNumber( int nb );
		int	shortestSpan( void );
		int	longestSpan( void );

		unsigned int	getN( void )const;
		int				getNbEl( void )const;
		int*			getSpan( void )const;
		int				getSmallestNb( void )const;
		int				getBiggestNb( void )const;

	private:
		unsigned int	_N;
		int				_nb_el;
		int*			_span;
		int				_smallestNb;
		int				_biggestNb;
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