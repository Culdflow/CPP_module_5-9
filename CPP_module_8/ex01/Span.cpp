#include "Span.hpp"

Span::Span( void ): _N(0), _nb_el(0), _span(NULL), _smallestNb(0), _biggestNb(0)
{
	std::cout << "[Span]: Default Constructor Called" << std::endl;
	std::cout << "[Span]: Max Amount Of Elements Set To 0" << std::endl;
}

Span::Span( unsigned int N ): _N(N), _nb_el(0), _span(new int[N]), _smallestNb(0), _biggestNb(0)
{
	std::cout << "[Span]: Constructor Called" << std::endl;
	std::cout << "[Span]: Max Amount Of Elements Set To " << N << std::endl;
}

Span::Span( const Span& copy ): _N(copy.getN()), _nb_el(copy.getNbEl()), _smallestNb(copy.getSmallestNb()), _biggestNb(copy.getBiggestNb())
{
	std::cout << "[Span]: Copy Constructor Called" << std::endl;
	std::cout << "[Span]: Max Amount Of Elements Set To " << copy.getN() << std::endl;
	if (copy.getN() > 0)
		_span = new int[copy.getN()];
	else
		_span = NULL;
	for (int i = 0; i < copy.getNbEl(); i++)
		_span[i] = copy.getSpan()[i];
}

Span::~Span( void )
{
	std::cout << "[Span]: Destructor Called" << std::endl;
	if (_span != NULL)
		delete [] _span;
}

Span&	Span::operator=( const Span& src )
{
	if (this->_span != NULL)
		delete [] this->_span;
	if (src.getN() > 0)
		this->_span = new int[src.getN()];
	else
		this->_span = NULL;
	for (int i = 0; i < src.getNbEl(); i++)
		this->_span[i] = src.getSpan()[i];
	return *this;
}

void	Span::addNumber( int nb )
{
	if ((unsigned int)this->getNbEl() >= this->getN())
		throw SpanAlreadyFullException();
	if (this->getNbEl() <= 0)
	{
		this->_biggestNb = nb;
		this->_smallestNb = nb;
	}
	this->_span[this->_nb_el] = nb;
	if (nb > this->getBiggestNb())
		this->_biggestNb = nb;
	if (nb < this->getSmallestNb())
		this->_smallestNb = nb;
	this->_nb_el += 1;
	std::cout << "[Span]: Added Number " << nb << std::endl;
}

int	Span::longestSpan( void )
{
	return (this->getBiggestNb() - this->getSmallestNb());
}

int	Span::shortestSpan( void )
{
	int	result = -1;

	if (this->getNbEl() < 2)
		throw NoSpanCanBeFoundException();
	for (int i = 0; i < this->getNbEl(); i++)
	{
		for (int y = 0; y < this->getNbEl(); y++)
		{
			if (i != y)
			{
				if (result == -1)
					result = abs(this->_span[i] - this->_span[y]);
				else if (abs(this->_span[i] - this->_span[y]) < result)
					result = abs(this->_span[i] - this->_span[y]);
			}
		}
	}
	return (result);
}

unsigned int	Span::getN( void )const
{
	return (this->_N);
}

int				Span::getNbEl( void )const
{
	return (this->_nb_el);
}

int				Span::getBiggestNb( void )const
{
	return (this->_biggestNb);
}

int				Span::getSmallestNb( void )const
{
	return (this->_smallestNb);
}

int*			Span::getSpan( void )const
{
	return (this->_span);
}