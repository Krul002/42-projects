#include "mutantstack.hpp"
#include <vector>
int		main() {
	MutantStack<int>		s;
	MutantStack<int>::iterator	it;

	s.push(10);
	s.push(20);
	it = s.begin();
	std::cout << s.size() << " " << *(it++) << std::endl;
	std::cout << s.size() << " " << *(it--) << std::endl;
	std::cout << s.size() << " " << *(it) << std::endl;
	s.push(-10);
	it = s.end();
	std::cout << s.size() << " " << *(it-=3) << std::endl;
	return 0;
} 