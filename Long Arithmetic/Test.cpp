#include <conio.h>
#include <chrono>
#include <iostream>
#include "Integer.h"

int main() {
	std::string n;
	std::cin >> n;
	std::string n1;
	std::cin >> n1;
	double a_d = ::atof(n.c_str());
	double b_d = ::atof(n1.c_str());
	Integer a = Integer(n);
	Integer b = Integer(n1);
	auto begin = std::chrono::high_resolution_clock::now();
	Integer* c = a.pow(b);
	auto end = std::chrono::high_resolution_clock::now();
	auto begin_0 = std::chrono::high_resolution_clock::now();
	double ret = pow(a_d, b_d);
	auto end_0 = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "\n";
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_0 - begin_0).count() << "\n";
	std::cout << c->toString() << "\n";
	std::cout << ret << "\n";
	std::cout << "Press any key\n";
	_getwch();
	return 0;
}
