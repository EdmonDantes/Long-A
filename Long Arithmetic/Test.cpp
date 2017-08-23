#include <conio.h>
#include <chrono>
#include <iostream>
#include "Integer.h"

int main() {
	std::string n;
	std::cin >> n;
	std::string n1;
	std::cin >> n1;
	Integer a = Integer(n);
	Integer b = Integer(n1);
	auto begin_1 = std::chrono::high_resolution_clock::now();
	Integer* c = a.pow(b);
	auto end_2 = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_2 - begin_1).count() << "\n";
	std::cout << c->toString() << "\n";
	std::cout << "Press any key\n";
	_getwch();
	return 0;
}
