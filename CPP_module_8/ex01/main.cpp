#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try{
		sp.addNumber(11);
	}catch (const Span::SpanAlreadyFullException& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	int arr[] = {90, 2, 5, 80, 156};
	std::vector<int> v(arr, arr + 5);
	Span s = Span(3);
	s.addRange(v.begin(), v.end());
	std::cout << s.shortestSpan() << std::endl;
	std::cout << s.longestSpan() << std::endl;
	return 0;
}