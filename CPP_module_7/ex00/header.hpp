#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

template<typename A>
void	swap(A &valueA, A &valueB)
{
	A temp = valueA;
	valueA = valueB;
	valueB = temp;
}

template<typename A>
A	min(A valueA, A valueB)
{
	if (valueA < valueB)
		return (valueA);
	return(valueB);
}

template<typename A>
A	max(A valueA, A valueB)
{
	if (valueA <= valueB)
		return (valueB);
	return (valueA);
}

