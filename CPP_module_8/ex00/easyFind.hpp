#pragma once

# include <algorithm>
# include <iostream>
# include <vector>

class ValueNotFound: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Value wasn't found");
		}
};

template<typename T>
typename T::iterator easyfind(T& lst, int nb)
{
	typename T::iterator result = std::find(lst.begin(), lst.end(), nb);
	if (result == lst.end())
		throw ValueNotFound();
	return (result);
}
