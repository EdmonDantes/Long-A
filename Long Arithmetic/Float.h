#include "Integer.h"
class Float : public Integer {
private:

	unsigned long long id = -1;

public:

	Float();
	Float(char a);
	Float(int a);
	Float(unsigned int a);
	Float(long a);
	Float(unsigned long a);
	Float(long long a);
	Float(unsigned long long a);
	Float(float a);
	Float(double a);
	Float(long double a);
	Float(char* a, int l);
	Float(std::string str);
	Float(const Float& a);

	inline ~Float();
};