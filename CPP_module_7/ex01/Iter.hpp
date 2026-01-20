#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

template<typename T>
void iter(T* addr, size_t length, void (*fun)(T& el))
{
	if (!addr || !fun)
		return ;
	for (size_t i = 0; i < length; i++)
		fun(addr[i]);
}