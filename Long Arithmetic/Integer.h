#include "DimValue.cpp"
#include <string>
#define ZERO new Integer("0");
class Integer {
private:

	static friend class Float;
	DimValue<unsigned int> value = DimValue<unsigned int>();
	bool isPositive = true;
	bool isNAN = false;

	int getNumber(char a);
	char getChar(int a);

	void initChar(char a);
	void initCHAR(unsigned char a);
	void initInt(int a);
	void initINT(unsigned int a);
	void initLong(long a);
	void initLONG(unsigned long a);
	void initLongLong(long long a);
	void initLONGLONG(unsigned long long a);
	void initFloat(const Float& a);

	static Integer* add(Integer* a, Integer* b);
	static Integer* sub(Integer* a, Integer* b);
	static Integer* mult(Integer* a, Integer* b);
	static Integer* divide(Integer* a, Integer* b);

	static unsigned int div(Integer* a, Integer* b);
	static Integer* mod(Integer* a, Integer* b,unsigned int div);
	Integer* mod(Integer* a, Integer* b);

	Integer(const DimValue<unsigned int> &value, bool isPositive);
	Integer(DimValue<unsigned int> *value, bool isPositive);

public:

	Integer();
	Integer(char a);
	Integer(unsigned char a);
	Integer(int a);
	Integer(unsigned int a);
	Integer(long a);
	Integer(unsigned long a);
	Integer(long long a);
	Integer(unsigned long long a);
	Integer(char* a, int l);
	Integer(const std::string str);
	Integer(const Integer& a);
	Integer(const Integer* a);
	inline Integer(const Float& a);

	inline ~Integer();

	Integer& operator = (const Integer& a);
	Integer& operator = (const char a);
	Integer& operator = (const unsigned char a);
	Integer& operator = (const int a);
	Integer& operator = (const unsigned int a);
	Integer& operator = (const long a);
	Integer& operator = (const unsigned long a);
	Integer& operator = (const long long a);
	Integer& operator = (const unsigned long long a);
	Integer& operator = (const Float& a);

	bool operator == (const Integer& a);
	bool operator == (const char a);
	bool operator == (const unsigned char a);
	bool operator == (const int a);
	bool operator == (const unsigned int a);
	bool operator == (const long a);
	bool operator == (const unsigned long a);
	bool operator == (const long long a);
	bool operator == (const unsigned long long a);
	bool operator == (const Float& a);

	bool operator != (const Integer& a);
	bool operator != (const char a);
	bool operator != (const unsigned char a);
	bool operator != (const int a);
	bool operator != (const unsigned int a);
	bool operator != (const long a);
	bool operator != (const unsigned long a);
	bool operator != (const long long a);
	bool operator != (const unsigned long long a);
	bool operator != (const Float& a);

	bool operator < (const Integer& a);
	bool operator < (const char a);
	bool operator < (const unsigned char a);
	bool operator < (const int a);
	bool operator < (const unsigned int a);
	bool operator < (const long a);
	bool operator < (const unsigned long a);
	bool operator < (const long long a);
	bool operator < (const unsigned long long a);
	bool operator < (const Float& a);

	bool operator > (const Integer& a);
	bool operator > (const char a);
	bool operator > (const unsigned char a);
	bool operator > (const int a);
	bool operator > (const unsigned int a);
	bool operator > (const long a);
	bool operator > (const unsigned long a);
	bool operator > (const long long a);
	bool operator > (const unsigned long long a);
	bool operator > (const Float& a);
	
	bool operator <= (const Integer& a);
	bool operator <= (const char a);
	bool operator <= (const unsigned char a);
	bool operator <= (const int a);
	bool operator <= (const unsigned int a);
	bool operator <= (const long a);
	bool operator <= (const unsigned long a);
	bool operator <= (const long long a);
	bool operator <= (const unsigned long long a);
	bool operator <= (const Float& a);

	bool operator >= (const Integer& a);
	bool operator >= (const char a);
	bool operator >= (const unsigned char a);
	bool operator >= (const int a);
	bool operator >= (const unsigned int a);
	bool operator >= (const long a);
	bool operator >= (const unsigned long a);
	bool operator >= (const long long a);
	bool operator >= (const unsigned long long a);
	bool operator >= (const Float& a);

	Integer* operator + (const Integer& a);
	Integer* operator + (const char a);
	Integer* operator + (const unsigned char a);
	Integer* operator + (const int a);
	Integer* operator + (const unsigned int a);
	Integer* operator + (const long a);
	Integer* operator + (const unsigned long a);
	Integer* operator + (const long long a);
	Integer* operator + (const unsigned long long a);
	Integer* operator + (const Float& a);

	Integer* operator - (const Integer& a);
	Integer* operator - (const char a);
	Integer* operator - (const unsigned char a);
	Integer* operator - (const int a);
	Integer* operator - (const unsigned int a);
	Integer* operator - (const long a);
	Integer* operator - (const unsigned long a);
	Integer* operator - (const long long a);
	Integer* operator - (const unsigned long long a);
	Integer* operator - (const Float& a);

	Integer* operator * (const Integer& a);
	Integer* operator * (const char a);
	Integer* operator * (const unsigned char a);
	Integer* operator * (const int a);
	Integer* operator * (const unsigned int a);
	Integer* operator * (const long a);
	Integer* operator * (const unsigned long a);
	Integer* operator * (const long long a);
	Integer* operator * (const unsigned long long a);
	Integer* operator * (const Float& a);

	Integer* operator / (const Integer& a);
	Integer* operator / (const char a);
	Integer* operator / (const unsigned char a);
	Integer* operator / (const int a);
	Integer* operator / (const unsigned int a);
	Integer* operator / (const long a);
	Integer* operator / (const unsigned long a);
	Integer* operator / (const long long a);
	Integer* operator / (const unsigned long long a);
	Integer* operator / (const Float& a);

	Integer* operator % (const Integer& a);
	Integer* operator % (const char a);
	Integer* operator % (const unsigned char a);
	Integer* operator % (const int a);
	Integer* operator % (const unsigned int a);
	Integer* operator % (const long a);
	Integer* operator % (const unsigned long a);
	Integer* operator % (const long long a);
	Integer* operator % (const unsigned long long a);
	Integer* operator % (const Float& a);

	Integer& operator += (const Integer& a);
	Integer& operator += (const char a);
	Integer& operator += (const unsigned char a);
	Integer& operator += (const int a);
	Integer& operator += (const unsigned int a);
	Integer& operator += (const long a);
	Integer& operator += (const unsigned long a);
	Integer& operator += (const long long a);
	Integer& operator += (const unsigned long long a);
	Integer& operator += (const Float& a);

	Integer& operator -= (const Integer& a);
	Integer& operator -= (const char a);
	Integer& operator -= (const unsigned char a);
	Integer& operator -= (const int a);
	Integer& operator -= (const unsigned int a);
	Integer& operator -= (const long a);
	Integer& operator -= (const unsigned long a);
	Integer& operator -= (const long long a);
	Integer& operator -= (const unsigned long long a);
	Integer& operator -= (const Float& a);

	Integer& operator *= (const Integer& a);
	Integer& operator *= (const char a);
	Integer& operator *= (const unsigned char a);
	Integer& operator *= (const int a);
	Integer& operator *= (const unsigned int a);
	Integer& operator *= (const long a);
	Integer& operator *= (const unsigned long a);
	Integer& operator *= (const long long a);
	Integer& operator *= (const unsigned long long a);
	Integer& operator *= (const Float& a);

	Integer& operator /= (const Integer& a);
	Integer& operator /= (const char a);
	Integer& operator /= (const unsigned char a);
	Integer& operator /= (const int a);
	Integer& operator /= (const unsigned int a);
	Integer& operator /= (const long a);
	Integer& operator /= (const unsigned long a);
	Integer& operator /= (const long long a);
	Integer& operator /= (const unsigned long long a);
	Integer& operator /= (const Float& a);

	Integer& operator %= (const Integer& a);
	Integer& operator %= (const char a);
	Integer& operator %= (const unsigned char a);
	Integer& operator %= (const int a);
	Integer& operator %= (const unsigned int a);
	Integer& operator %= (const long a);
	Integer& operator %= (const unsigned long a);
	Integer& operator %= (const long long a);
	Integer& operator %= (const unsigned long long a);
	Integer& operator %= (const Float& a);

	Integer& operator ++ (int); //a++
	Integer& operator -- (int); //a--
	Integer& operator ++ (); //++a
	Integer& operator -- (); //--a
	Integer& operator - ();

	operator char();
	operator const unsigned char ();
	operator int();
	operator unsigned int();
	operator long();
	operator unsigned long();
	operator long long();
	operator unsigned long long();

	bool isChar();
	bool isUnsignedChar();
	bool isInt();
	bool isUnsignedInt();
	bool isLong();
	bool isUnsignedLong();
	bool isLongLong();
	bool isUnsignedLongLong();

	bool isZERO();
	bool isONE();
	bool isNEGONE();
	bool isEven();

	void multOnTen();
	void divideOnTen();
	std::string toString();
	Integer* mod(Integer& a);
	Integer* mod(Integer* a);
	Integer* pow(Integer& a);


	void abs();
};
