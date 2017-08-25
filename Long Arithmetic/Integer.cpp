#include "Float.cpp"
//Private section
int Integer::getNumber(char a) {
	return a - '0';
}
char Integer::getChar(int a) {
	return a + '0';
}

void Integer::initChar(char a) {
	this->value.clear();
	if (a == 0) {
		this->isPositive = true;
		this->value.add(0);
		return;
	}
	char l_0 = a;
	if (l_0 < 0) {
		this->isPositive = false;
		l_0 = 0 - l_0;
	}
	while (l_0 > 0) {
		this->value.add(l_0 % 10);
		l_0 /= 10;
	}
	this->value.revers();
}
void Integer::initCHAR(unsigned char a) {
	this->value.clear();
	if (a == 0) {
		this->isPositive = true;
		this->value.add(0);
		return;
	}
	unsigned char l_0 = a;
	while (l_0 > 0) {
		this->value.add(l_0 % 10);
		l_0 /= 10;
	}
	this->value.revers();
}
void Integer::initInt(int a) {
	this->value.clear();
	if (a == 0) {
		this->isPositive = true;
		this->value.add(0);
		return;
	}
	int l_0 = a;
	if (l_0 < 0) {
		this->isPositive = false;
		l_0 = 0 - l_0;
	}
	while (l_0 > 0) {
		this->value.add(l_0 % 10);
		l_0 /= 10;
	}
	this->value.revers();
}
void Integer::initINT(unsigned int a) {
	this->value.clear();
	if (a == 0) {
		this->isPositive = true;
		this->value.add(0);
		return;
	}
	unsigned int l_0 = a;
	while (l_0 > 0) {
		this->value.add(l_0 % 10);
		l_0 /= 10;
	}
	this->value.revers();
}
void Integer::initLong(long a) {
	this->value.clear();
	if (a == 0) {
		this->isPositive = true;
		this->value.add(0);
		return;
	}
	long l_0 = a;
	if (l_0 < 0) {
		this->isPositive = false;
		l_0 = 0 - l_0;
	}
	while (l_0 > 0) {
		this->value.add(l_0 % 10);
		l_0 /= 10;
	}
	this->value.revers();
}
void Integer::initLONG(unsigned long a) {
	this->value.clear();
	if (a == 0) {
		this->isPositive = true;
		this->value.add(0);
		return;
	}
	unsigned long l_0 = a;
	while (l_0 > 0) {
		this->value.add(l_0 % 10);
		l_0 /= 10;
	}
	this->value.revers();
}
void Integer::initLongLong(long long a) {
	this->value.clear();
	if (a == 0) {
		this->isPositive = true;
		this->value.add(0);
		return;
	}
	long long l_0 = a;
	if (l_0 < 0) {
		this->isPositive = false;
		l_0 = 0 - l_0;
	}
	while (l_0 > 0) {
		this->value.add(l_0 % 10);
		l_0 /= 10;
	}
	this->value.revers();
}
void Integer::initLONGLONG(unsigned long long a) {
	this->value.clear();
	if (a == 0) {
		this->isPositive = true;
		this->value.add(0);
		return;
	}
	unsigned long long l_0 = a;
	while (l_0 > 0) {
		this->value.add(l_0 % 10);
		l_0 /= 10;
	}
	this->value.revers();
}
void Integer::initFloat(const Float& a) {
	this->value.~DimValue();
	this->value = DimValue<unsigned int>(a.value);
	this->isPositive = a.isPositive;
	this->isNAN = a.isNAN;
}



Integer* Integer::add(Integer* a, Integer* b) {
	if (a->isNAN || b->isNAN) return new Integer();
	if (a->isPositive && b->isPositive) {
		if (a->value.size() >= b->value.size()) {
			unsigned int l_0 = 0;
			DimValue<unsigned int> l_1 = DimValue<unsigned int>();
			unsigned long long index_0 = a->value.size() - 1;
			unsigned long long index_1 = b->value.size() - 1;
			while (index_1 < -1) {
				unsigned int local_0 = a->value.get(index_0--);
				unsigned int local_1 = b->value.get(index_1--);
				unsigned int local_2 = local_0 + local_1 + l_0;
				l_1.add(local_2 % 10);
				l_0 = local_2 / 10;
			}
			while (index_0 < -1) {
				unsigned int local_0 = a->value.get(index_0--);
				unsigned int local_1 = l_0 + local_0;
				l_1.add(local_1 % 10);
				l_0 = local_1 / 10;
			}
			while (l_0 > 0) {
				l_1.add(l_0 % 10);
				l_0 /= 10;
			}
			l_1.revers();
			Integer *ret = new Integer(l_1,true);
			l_1.~DimValue();
			return ret;
		}
		else {
			return add(b, a);
		}
	}
	else if (a->isPositive && !b->isPositive) {
		return sub(a, b);
	}
	else if (!a->isPositive && b->isPositive) {
		return sub(b, a);
	}
	else if (!a->isPositive && !b->isPositive) {
		a->isPositive = true;
		b->isPositive = true;
		Integer* c = add(a, b);
		a->isPositive = false;
		b->isPositive = false;
		return c;
	}
	return new Integer();
}

Integer* Integer::sub(Integer* a, Integer* b) {
	if (a->isPositive && b->isPositive) {
		if (*a > *b) {
			DimValue<unsigned int> ret = DimValue<unsigned int>();
			unsigned int l_0 = 0;
			unsigned long long l_1 = a->value.size() - 1;
			unsigned long long l_2 = b->value.size() - 1;
			while (l_2 < -1) {
				long long l_3 = a->value.get(l_1--);
				long long l_4 = b->value.get(l_2--);
				long long l_5 = l_3 - l_4 - l_0;
				l_0 = 0;
				while (l_5 < 0) {
					l_0++;
					l_5 += 10;
				}
				ret.add(l_5);
			}
			while (l_1 < -1) {
				long long l_3 = a->value.get(l_1--);
				long long l_4 = l_3 - l_0;
				l_0 = 0;
				while (l_4 < 0) {
					l_0++;
					l_4 += 10;
				}
				ret.add(l_4);
			}
			ret.revers();
			return new Integer(ret, true);
		}
		else if (*a == *b){
			return ZERO;
		}
		else {
			Integer* c = sub(b, a);
			c->isPositive = !c->isPositive;
			return c;
		}
	}
	else if (a->isPositive && !b->isPositive) {
		b->isPositive = true;
		Integer* ret = add(a, b);
		b->isPositive = false;
		return ret;
	}
	else if (!a->isPositive && b->isPositive) {
		a->isPositive = true;
		Integer* c = add(a, b);
		a->isPositive = false;
		c->isPositive = !c->isPositive;
		return c;
	}
	else {
		a->isPositive = true;
		b->isPositive = true;
		Integer* c = sub(a,b);
		a->isPositive = false;
		b->isPositive = false;
		c->isPositive = !c->isPositive;
		return c;
	}
	return 0;
};

Integer* Integer::mult(Integer* a, Integer* b) {
	if (a->isPositive && b->isPositive) {
		Integer** all = new Integer*[b->value.size()];
		int x = 0;
		for (unsigned long long i = b->value.size() - 1; i < -1; i--) {
			unsigned int local_0 = b->value[i];
			DimValue<unsigned int> ret = DimValue<unsigned int>();
			for (unsigned long long j = a->value.size() - 1; j <-1; j--) {
				unsigned int local_1 = a->value.get(j);
				unsigned int sum = (local_0 * local_1) + x;
				x = sum / 10;
				ret.add(sum % 10);
			}
			while (x > 0) {
				ret.add(x % 10);
				x /= 10;
			}
			ret.revers();
			all[i] = new Integer(ret, true);
			for (unsigned long long j = b->value.size() - 1; j > i; j--) {
				all[i]->multOnTen();
			}
			ret.~DimValue();
		}
		Integer* ret = new Integer(0);
		for (unsigned long long i = 0; i < b->value.size(); i++) {
			*ret += *all[i];
		}
		for (auto i = 0; i < b->value.size(); i++) {
			delete all[i];
		}
		delete[] all;
		return ret;
	}
	else if (a->isPositive && !b->isPositive) {
		b->isPositive = true;
		Integer* c = mult(a, b);
		b->isPositive = false;
		c->isPositive = false;
		return c;
	}
	else if (!a->isPositive && b->isPositive) {
		a->isPositive = true;
		Integer* c = mult(a, b);
		a->isPositive = false;
		c->isPositive = false;
		return c;
	}
	else {
		a->isPositive = true;
		b->isPositive = true;
		Integer* c = mult(a, b);
		a->isPositive = false;
		b->isPositive = false;
		return c;
	}
}

Integer* Integer::divide(Integer* a, Integer* b) {
	if (a->isPositive && b->isPositive) {
		if (*a < *b) return ZERO;
		if (*a == *b) return new Integer(1);
		DimValue<unsigned int> ret = DimValue<unsigned int>();
		DimValue<unsigned int> x = DimValue<unsigned int>();
		unsigned long long i = 0;
		while (i < a->value.size()) {
			if (a->value[i] == 0) {
				if (x.size() > 0) {
					x[0] == 0;
					if (true) {
						ret.add(0);
						i++;
					}
					else {
						DimValue<unsigned int> local = DimValue<unsigned int>();
						local.addToStart(x);
						if (local < b->value && i<a->value.size()) {
							local.add(a->value.get(i));
							i++;
						}
						if (local < b->value) {
							ret.add(0);
							x.clear();
							x.addToBack(local);
						}
						else {
							Integer c_0 = Integer(local, true);
							ret.add(div(&c_0, b));
							x.clear();
							Integer* r = mod(&c_0, b, ret.get(ret.size() - 1));
							x.add(r->value);
							delete r;
							c_0.~Integer();
						}
						local.~DimValue();
						i++;
					}
				}
				else {
					ret.add(0);
					i++;
				}
			}
			else {
				if (x.size() > 0) {
					DimValue<unsigned int> local = DimValue<unsigned int>();
					local.addToStart(x);
					if (local < b->value && i < a->value.size()) {
						local.add(a->value.get(i++));
					}
					if (local < b->value) {
						ret.add(0);
						x.clear();
						x.add(local);
					}
					else {
						Integer c_0 = Integer(local, true);
						ret.add(div(&c_0, b));
						x.clear();
						Integer* r = mod(&c_0, b, ret.get(ret.size() - 1));
						x.add(r->value);
						delete r;
						c_0.~Integer();
					}
					local.~DimValue();
				}
				else {
					DimValue<unsigned int>* local = a->value.subValue(i, b->value.size());
					i += b->value.size() - 1;
					if (*local < b->value && i < a->value.size()) {
						local->add(a->value.get(++i));
					}
					if (*local < b->value) {
						ret.add(0);
						x.clear();
						x.add(*local);
					}
					else {
						Integer c_0 = Integer(local, true);
						ret.add(div(&c_0, b));
						x.clear();
						Integer* r = mod(&c_0, b, ret.get(ret.size() - 1));
						x.add(r->value);
						delete r;
						c_0.~Integer();
					}
					local->~DimValue();
					i++;
				}
			}
		}
		Integer* r = new Integer(ret, true);
		ret.~DimValue();
		x.~DimValue();
		return r;
	}
	else if (a->isPositive && !b->isPositive) {
		b->isPositive = true;
		Integer* ret = divide(a, b);
		ret->isPositive = false;
		b->isPositive = false;
		return ret;
	}
	else if (!a->isPositive && b->isPositive) {
		a->isPositive = true;
		Integer* ret = divide(a, b);
		ret->isPositive = false;
		b->isPositive = false;
		return ret;
	}
	else {
		a->isPositive = true;
		b->isPositive = true;
		Integer* ret = divide(a, b);
		a->isPositive = false;
		b->isPositive = false;
		return ret;
	}
}

unsigned int Integer::div(Integer* a, Integer* b) {
	unsigned int ret = 0;
	Integer c = *a;
	Integer Z = Integer(0);
	while (true) {
		Integer* tmp_0 = c - *b;
		c = *tmp_0;
		if (c >= Z) {
			ret++;
			delete tmp_0;
		}
		else { delete tmp_0; break; }
	}
	return ret;
}
Integer* Integer::mod(Integer* a, Integer* b, unsigned int div) {
	if (*b != Integer("0")) {
		Integer* c = new Integer(div);
		Integer* d = mult(b,c);
		Integer* ret = sub(a,d);
		delete c;
		delete d;
		return ret;
	}
	else return ZERO;
}

Integer* Integer::mod(Integer* a,Integer* b) {
	if (*b != Integer("0")) {
		Integer* c = divide(a, b);
		Integer* d = mult(b, c);
		Integer* ret = sub(a, d);
		delete c;
		delete d;
		return ret;
	}
	else return new Integer();
}

Integer::Integer(const DimValue<unsigned int> &value, bool isPositive) {
	this->value.~DimValue();
	this->value = value;
	this->value.removeFirst(0);
	this->isPositive = isPositive;
}

Integer::Integer(DimValue<unsigned int>* value, bool isPositive) {
	this->value.~DimValue();
	this->value = DimValue<unsigned int>(*value);
	this->value.removeFirst(0);
	this->isPositive = isPositive;
}

//Public section

Integer::Integer() {
	this->isNAN = true;
}
Integer::Integer(char a) {
	initChar(a);
}
Integer::Integer(unsigned char a) { 
	initCHAR(a); 
}
Integer::Integer(int a) {
	initInt(a);
}
Integer::Integer(unsigned int a) {
	initINT(a);
}
Integer::Integer(long a) {
	initLong(a);
}
Integer::Integer(unsigned long a) {
	initLONG(a);
}
Integer::Integer(long long a) {
	initLongLong(a);
}
Integer::Integer(unsigned long long a) {
	initLONGLONG(a);
}
Integer::Integer(char* a, int l) {
	if (l > 0) {
		int i = 0;
		if (a[0] == '-' || a[0] == '-') {
			isPositive = false;
			i++;
		}
		for (i; i < l; i++) {
			this->value.add(static_cast<unsigned int>(getNumber(a[i])));
		}
	}
	else isNAN = true;
}
Integer::Integer(std::string a) {
	if (a.length() > 0) {
		unsigned long long i = 0;
		if (a[0] == '-' || a[0] == '-') {
			isPositive = false;
			i++;
		}

		for (i; i < a.length(); i++) {
			this->value.add(static_cast<unsigned int>(getNumber(a[i])));
		}
	}
}
Integer::Integer(const Integer& a) {
	this->value.clear();
	this->value.addToBack(a.value);
	this->isPositive = a.isPositive;
	this->isNAN = a.isNAN;
}

Integer::Integer(const Integer* a) {
	this->value.clear();
	this->value.addToBack(a->value);
	this->isPositive = a->isPositive;
	this->isNAN = a->isNAN;
}

Integer::Integer(const Float& a) {
	initFloat(a);
}//изи
Integer::~Integer() {
	this->value.~DimValue();
}

Integer& Integer::operator = (const Integer& a) {
	if (a.isNAN) {
		this->isNAN;
	}
	else {
		this->value.~DimValue();
		this->value = DimValue<unsigned int>(a.value);
		this->value.removeFirst(0);
		this->isPositive = a.isPositive;
	}
	return *this;
}

Integer& Integer::operator = (const char a) {
	initChar(a);
	return *this;
}
Integer& Integer::operator = (const unsigned char a) {
	initCHAR(a);
	return *this;
}
Integer& Integer::operator = (const int a) {
	initInt(a);
	return *this;
};
Integer& Integer::operator = (const unsigned int a) {
	initINT(a);
	return *this;
};
Integer& Integer::operator = (const long a) {
	initLong(a);
	return *this;
};
Integer& Integer::operator = (const unsigned long a) {
	initLONG(a);
	return *this;
};
Integer& Integer::operator = (const long long a) {
	initLongLong(a);
	return *this;
};
Integer& Integer::operator = (const unsigned long long a) {
	initLONGLONG(a);
	return *this;
};
Integer& Integer::operator = (const Float& a) {
	initFloat(Float(a));
	return *this;
};

bool Integer::operator == (const Integer& a) {
	if (this->isPositive == a.isPositive && this->value.size() == a.value.size()) {
		for (unsigned long long i = 0; i < this->value.size(); i++) {
			if (this->value[i] != a.value[i]) return false;
		}
		return true;
	}
	return false;
};
bool Integer::operator == (const char a) {
	return *this == Integer(a);
};
bool Integer::operator == (const unsigned char a) {
	return *this == Integer(a);
};
bool Integer::operator == (const int a) {
	return *this == Integer(a);
};
bool Integer::operator == (const unsigned int a) {
	return *this == Integer(a);
};
bool Integer::operator == (const long a) {
	return *this == Integer(a);
};
bool Integer::operator == (const unsigned long a) {
	return *this == Integer(a);
};
bool Integer::operator == (const long long a) {
	return *this == Integer(a);
};
bool Integer::operator == (const unsigned long long a) {
	return *this == Integer(a);
};
bool Integer::operator == (const Float& a) {
	return *this == Integer(a);
};

bool Integer::operator != (const Integer& a){
	return !(*this == a);
};
bool Integer::operator != (const char a) {
	return !(*this == a);
};
bool Integer::operator != (const unsigned char a) {
	return !(*this == a);
};
bool Integer::operator != (const int a) {
	return !(*this == a);
};
bool Integer::operator != (const unsigned int a) {
	return !(*this == a);
};
bool Integer::operator != (const long a) {
	return !(*this == a);
};
bool Integer::operator != (const unsigned long a) {
	return !(*this == a);
};
bool Integer::operator != (const long long a) {
	return !(*this == a);
};
bool Integer::operator != (const unsigned long long a) {
	return !(*this == a);
};
bool Integer::operator != (const Float& a) {
	return !(*this == a);
};

bool Integer::operator < (const Integer& a) {
	if (a.isNAN) return true;
	if (this->isNAN) return false;
	if (a.isPositive && isPositive) {
		if (value.size() < a.value.size()) return true;
		else if (value.size() == a.value.size()) {
			for (unsigned long long i = 0; i < a.value.size(); i++) {
				if (a.value[i] > value[i]) return true;
				else if (a.value[i] < value[i]) return false;
			}
			return false;
		}
		else return false;
	}
	else if (a.isPositive && !isPositive) return true;
	else if (!a.isPositive && isPositive) return false;
	else if (!a.isPositive && isPositive) {
		if (value.size() < a.value.size()) return false;
		else if (value.size() == a.value.size()) {
			for (unsigned long long i = 0; i < -1; i++) {
				if (a.value[i] > value[i]) return false;
				else if (a.value[i] < value[i]) return true;
			}
			return false;
		}
		else return true;
	}
};
bool Integer::operator < (const char a) { return *this < Integer(a); };
bool Integer::operator < (const unsigned char a) { return *this < Integer(a); };
bool Integer::operator < (const int a) { return *this < Integer(a); };
bool Integer::operator < (const unsigned int a) { return *this < Integer(a); };
bool Integer::operator < (const long a) { return *this < Integer(a); };
bool Integer::operator < (const unsigned long a) { return *this < Integer(a); };
bool Integer::operator < (const long long a) { return *this < Integer(a); };
bool Integer::operator < (const unsigned long long a) { return *this < Integer(a); };
bool Integer::operator < (const Float& a) { return *this < Integer(a); };

bool Integer::operator > (const Integer& a){
	if (a.isNAN) return false;
	if (this->isNAN) return true;
	if (a.isPositive && isPositive) {
		if (value.size() < a.value.size()) return false;
		else if (value.size() == a.value.size()) {
			for (unsigned long long i = 0; i < value.size(); i++) {
				if (a.value[i] > value[i]) return false;
				else if (a.value[i] < value[i]) return true;
			}
			return false;
		}
		else return true;
	}
	else if (a.isPositive && !isPositive) return false;
	else if (!a.isPositive && isPositive) return true;
	else if (!a.isPositive && isPositive) {
		if (value.size() < a.value.size()) return true;
		else if (value.size() == a.value.size()) {
			for (unsigned long long i = 0; i < value.size(); i++) {
				if (a.value[i] > value[i]) return true;
				else if (a.value[i] < value[i]) return false;
			}
			return false;
		}
		else return false;
	}
};
bool Integer::operator > (const char a) { return *this > Integer(a); };
bool Integer::operator > (const unsigned char a){ return *this > Integer(a); };
bool Integer::operator > (const int a){ return *this > Integer(a); };
bool Integer::operator > (const unsigned int a){ return *this > Integer(a); };
bool Integer::operator > (const long a){ return *this > Integer(a); };
bool Integer::operator > (const unsigned long a){ return *this > Integer(a); };
bool Integer::operator > (const long long a){ return *this > Integer(a); };
bool Integer::operator > (const unsigned long long a){ return *this > Integer(a); };
bool Integer::operator > (const Float& a){ return *this > Integer(a); };

bool Integer::operator <= (const Integer& a){ return !(*this > a); };
bool Integer::operator <= (const char a){ return !(*this > Integer(a)); };
bool Integer::operator <= (const unsigned char a){ return !(*this > Integer(a)); };
bool Integer::operator <= (const int a){ return !(*this > Integer(a)); };
bool Integer::operator <= (const unsigned int a){ return !(*this > Integer(a)); };
bool Integer::operator <= (const long a){ return !(*this > Integer(a)); };
bool Integer::operator <= (const unsigned long a){ return !(*this > Integer(a)); };
bool Integer::operator <= (const long long a){ return !(*this > Integer(a)); };
bool Integer::operator <= (const unsigned long long a){ return !(*this > Integer(a)); };
bool Integer::operator <= (const Float& a){ return !(*this > Integer(a)); };

bool Integer::operator >= (const Integer& a){ return !(*this < a); };
bool Integer::operator >= (const char a){ return !(*this < Integer(a)); };
bool Integer::operator >= (const unsigned char a){ return !(*this < Integer(a)); };
bool Integer::operator >= (const int a){ return !(*this < Integer(a)); };
bool Integer::operator >= (const unsigned int a){ return !(*this < Integer(a)); };
bool Integer::operator >= (const long a){ return !(*this < Integer(a)); };
bool Integer::operator >= (const unsigned long a){ return !(*this < Integer(a)); };
bool Integer::operator >= (const long long a){ return !(*this < Integer(a)); };
bool Integer::operator >= (const unsigned long long a){ return !(*this < Integer(a)); };
bool Integer::operator >= (const Float& a){ return !(*this < Integer(a)); };

//Add

Integer* Integer::operator + (const Integer& a){
	Integer c = Integer(a);
	Integer* ret = add(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator + (const char a) { 
	Integer c = Integer(a);
	Integer* ret = add(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator + (const unsigned char a){
	Integer c = Integer(a);
	Integer* ret = add(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator + (const int a){
	Integer c = Integer(a);
	Integer* ret = add(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator + (const unsigned int a){
	Integer c = Integer(a);
	Integer* ret = add(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator + (const long a){
	Integer c = Integer(a);
	Integer* ret = add(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator + (const unsigned long a){
	Integer c = Integer(a);
	Integer* ret = add(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator + (const long long a){
	Integer c = Integer(a);
	Integer* ret = add(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator + (const unsigned long long a){
	Integer c = Integer(a);
	Integer* ret = add(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator + (const Float& a){
	Integer c = Integer(a);
	Integer* ret = add(this, &c);
	c.~Integer();
	return ret;
};

//Sub

Integer* Integer::operator - (const Integer& a){
	Integer c = Integer(a);
	Integer* ret = sub(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator - (const char a){
	Integer c = Integer(a);
	Integer* ret = sub(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator - (const unsigned char a){
	Integer c = Integer(a);
	Integer* ret = sub(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator - (const int a){
	Integer c = Integer(a);
	Integer* ret = sub(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator - (const unsigned int a){
	Integer c = Integer(a);
	Integer* ret = sub(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator - (const long a){
	Integer c = Integer(a);
	Integer* ret = sub(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator - (const unsigned long a){
	Integer c = Integer(a);
	Integer* ret = sub(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator - (const long long a){
	Integer c = Integer(a);
	Integer* ret = sub(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator - (const unsigned long long a){
	Integer c = Integer(a);
	Integer* ret = sub(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator - (const Float& a){
	Integer c = Integer(a);
	Integer* ret = sub(this, &c);
	c.~Integer();
	return ret;
};

//Multiply

Integer* Integer::operator * (const Integer& a){
	Integer c = Integer(a);
	Integer* ret = mult(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator * (const char a){
	Integer c = Integer(a);
	Integer* ret = mult(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator * (const unsigned char a){
	Integer c = Integer(a);
	Integer* ret = mult(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator * (const int a){
	Integer c = Integer(a);
	Integer* ret = mult(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator * (const unsigned int a){
	Integer c = Integer(a);
	Integer* ret = mult(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator * (const long a){
	Integer c = Integer(a);
	Integer* ret = mult(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator * (const unsigned long a){
	Integer c = Integer(a);
	Integer* ret = mult(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator * (const long long a){
	Integer c = Integer(a);
	Integer* ret = mult(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator * (const unsigned long long a){
	Integer c = Integer(a);
	Integer* ret = mult(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator * (const Float& a){
	Integer c = Integer(a);
	Integer* ret = mult(this, &c);
	c.~Integer();
	return ret;
};

//Divide

Integer* Integer::operator / (const Integer& a){
	Integer c = Integer(a);
	Integer* ret = divide(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator / (const char a){
	Integer c = Integer(a);
	Integer* ret = divide(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator / (const unsigned char a){
	Integer c = Integer(a);
	Integer* ret = divide(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator / (const int a){
	Integer c = Integer(a);
	Integer* ret = divide(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator / (const unsigned int a){
	Integer c = Integer(a);
	Integer* ret = divide(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator / (const long a){
	Integer c = Integer(a);
	Integer* ret = divide(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator / (const unsigned long a){
	Integer c = Integer(a);
	Integer* ret = divide(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator / (const long long a){
	Integer c = Integer(a);
	Integer* ret = divide(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator / (const unsigned long long a){
	Integer c = Integer(a);
	Integer* ret = divide(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator / (const Float& a){
	Integer c = Integer(a);
	Integer* ret = divide(this, &c);
	c.~Integer();
	return ret;
};



Integer* Integer::operator % (const Integer& a) {
	Integer c = Integer(a);
	Integer* ret = mod(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator % (const char a){
	Integer c = Integer(a);
	Integer* ret = mod(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator % (const unsigned char a){
	Integer c = Integer(a);
	Integer* ret = mod(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator % (const int a){
	Integer c = Integer(a);
	Integer* ret = mod(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator % (const unsigned int a){
	Integer c = Integer(a);
	Integer* ret = mod(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator % (const long a){
	Integer c = Integer(a);
	Integer* ret = mod(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator % (const unsigned long a){
	Integer c = Integer(a);
	Integer* ret = mod(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator % (const long long a){
	Integer c = Integer(a);
	Integer* ret = mod(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator % (const unsigned long long a){
	Integer c = Integer(a);
	Integer* ret = mod(this, &c);
	c.~Integer();
	return ret;
};
Integer* Integer::operator % (const Float& a){
	Integer c = Integer(a);
	Integer* ret = mod(this, &c);
	c.~Integer();
	return ret;
};



Integer& Integer::operator += (const Integer& a){
	Integer* tmp = *this + a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator += (const char a){
	Integer* tmp = *this + a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator += (const unsigned char a){
	Integer* tmp = *this + a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator += (const int a){
	Integer* tmp = *this + a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator += (const unsigned int a){
	Integer* tmp = *this + a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator += (const long a){
	Integer* tmp = *this + a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator += (const unsigned long a){
	Integer* tmp = *this + a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator += (const long long a){
	Integer* tmp = *this + a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator += (const unsigned long long a){
	Integer* tmp = *this + a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator += (const Float& a){
	Integer* tmp = *this + a;
	*this = *tmp;
	delete tmp;
	return *this;
};



Integer& Integer::operator -= (const Integer& a) {
	Integer* tmp = *this - a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator -= (const char a) {
	Integer* tmp = *this - a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator -= (const unsigned char a) {
	Integer* tmp = *this - a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator -= (const int a) {
	Integer* tmp = *this - a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator -= (const unsigned int a) {
	Integer* tmp = *this - a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator -= (const long a) {
	Integer* tmp = *this - a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator -= (const unsigned long a) {
	Integer* tmp = *this - a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator -= (const long long a) {
	Integer* tmp = *this - a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator -= (const unsigned long long a) {
	Integer* tmp = *this - a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator -= (const Float& a) {
	Integer* tmp = *this - a;
	*this = *tmp;
	delete tmp;
	return *this;
};



Integer& Integer::operator *= (const Integer& a) {
	Integer* tmp = *this * a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator *= (const char a) {
	Integer* tmp = *this * a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator *= (const unsigned char a) {
	Integer* tmp = *this * a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator *= (const int a) {
	Integer* tmp = *this * a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator *= (const unsigned int a) {
	Integer* tmp = *this * a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator *= (const long a) {
	Integer* tmp = *this * a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator *= (const unsigned long a) {
	Integer* tmp = *this * a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator *= (const long long a) {
	Integer* tmp = *this * a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator *= (const unsigned long long a) {
	Integer* tmp = *this * a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator *= (const Float& a) {
	Integer* tmp = *this * a;
	*this = *tmp;
	delete tmp;
	return *this;
};



Integer& Integer::operator /= (const Integer& a) {
	Integer* tmp = *this / a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator /= (const char a) {
	Integer* tmp = *this / a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator /= (const unsigned char a) {
	Integer* tmp = *this / a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator /= (const int a) {
	Integer* tmp = *this / a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator /= (const unsigned int a) {
	Integer* tmp = *this / a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator /= (const long a) {
	Integer* tmp = *this / a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator /= (const unsigned long a) {
	Integer* tmp = *this / a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator /= (const long long a) {
	Integer* tmp = *this / a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator /= (const unsigned long long a) {
	Integer* tmp = *this / a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator /= (const Float& a) {
	Integer* tmp = *this / a;
	*this = *tmp;
	delete tmp;
	return *this;
};


Integer& Integer::operator %= (const Integer& a) {
	Integer* tmp = *this % a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator %= (const char a) {
	Integer* tmp = *this % a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator %= (const unsigned char a) {
	Integer* tmp = *this % a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator %= (const int a) {
	Integer* tmp = *this % a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator %= (const unsigned int a) {
	Integer* tmp = *this % a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator %= (const long a) {
	Integer* tmp = *this % a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator %= (const unsigned long a) {
	Integer* tmp = *this % a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator %= (const long long a) {
	Integer* tmp = *this % a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator %= (const unsigned long long a) {
	Integer* tmp = *this % a;
	*this = *tmp;
	delete tmp;
	return *this;
};
Integer& Integer::operator %= (const Float& a) {
	Integer* tmp = *this % a;
	*this = *tmp;
	delete tmp;
	return *this;
};



Integer& Integer::operator ++ (int) {
	Integer& a = *this;
	*this += 1;
	return a;
}

Integer& Integer::operator -- (int) {
	Integer& a = *this;
	*this -= 1;
	return a;
}

Integer& Integer::operator ++() {
	*this += 1;
	return *this;
}

Integer& Integer::operator --() {
	*this -= 1;
	return *this;
}

Integer& Integer::operator -() {
	this->isPositive = !this->isPositive;
	return *this;
}

bool Integer::isChar() {
	if (*this <= CHAR_MAX && *this >= CHAR_MIN) return true;
	else return false;
}

bool Integer::isUnsignedChar() {
	if (*this <= UCHAR_MAX) return true;
	else return false;
};
bool Integer :: isInt() {
	if (*this <= INT_MAX && *this >= INT_MIN) return true;
	else return false;
};
bool Integer::isUnsignedInt() {
	if (*this <= UINT_MAX) return true;
	else return false;
};
bool Integer::isLong() {
	if (*this <= LONG_MAX && *this >= LONG_MIN) return true;
	else return false;
};
bool Integer::isUnsignedLong() {
	if (*this <= ULONG_MAX) return true;
	else return false;
};
bool Integer::isLongLong() {
	if (*this <= LLONG_MAX && *this >= LLONG_MIN) return true;
	else return false;
};
bool Integer::isUnsignedLongLong() {
	if (*this <= ULLONG_MAX) return true;
	else return false;
};

Integer::operator char() {
	char ret=0;
	if (isChar()) {
		for (unsigned long long i = 0; i < this->value.size(); i++) {
			ret += (this->getNumber(this->value[i]) * powl(10, i));
		}
	}
	else {
		Integer* c = *this % CHAR_MAX;
		for (unsigned long long i = 0; i < c->value.size(); i++) {
			ret += (c->getNumber(c->value[i]) * powl(10, i));
		}
		delete c;
	}
	if (!this->isPositive) ret = -ret;
	return ret;
}

Integer::operator const unsigned char() {
	unsigned char ret = 0;
	if (isUnsignedChar()) {
		for (unsigned long long i = 0; i < this->value.size(); i++) {
			ret += (this->getNumber(this->value[i]) * powl(10, i));
		}
	}
	else {
		Integer* c = *this % UCHAR_MAX;
		for (unsigned long long i = 0; i < c->value.size(); i++) {
			ret += (c->getNumber(c->value[i]) * powl(10, i));
		}
		delete c;
	}
	return ret;
};
Integer::operator int() {
	int ret = 0;
	if (isInt()) {
		for (unsigned long long i = 0; i < this->value.size(); i++) {
			ret += (this->getNumber(this->value[i]) * powl(10, i));
		}
	}
	else {
		Integer* c = *this % INT_MAX;
		for (unsigned long long i = 0; i < c->value.size(); i++) {
			ret += (c->getNumber(c->value[i]) * powl(10, i));
		}
		delete c;
	}
	if (!this->isPositive) ret = -ret;
	return ret;
};
Integer::operator unsigned int() {
	unsigned int ret = 0;
	if (isUnsignedInt()) {
		for (unsigned long long i = 0; i < this->value.size(); i++) {
			ret += (this->getNumber(this->value[i]) * powl(10, i));
		}
	}
	else {
		Integer* c = *this % UINT_MAX;
		for (unsigned long long i = 0; i < c->value.size(); i++) {
			ret += (c->getNumber(c->value[i]) * powl(10, i));
		}
		delete c;
	}
	return ret;
};
Integer::operator long() {
	long ret = 0;
	if (isLong()) {
		for (unsigned long long i = 0; i < this->value.size(); i++) {
			ret += (this->getNumber(this->value[i]) * powl(10, i));
		}
	}
	else {
		Integer* c = *this % LONG_MAX;
		for (unsigned long long i = 0; i < c->value.size(); i++) {
			ret += (c->getNumber(c->value[i]) * powl(10, i));
		}
		delete c;
	}
	if (!this->isPositive) ret = -ret;
	return ret;
};
Integer::operator unsigned long() {
	unsigned long ret = 0;
	if (isUnsignedLong()) {
		for (unsigned long long i = 0; i < this->value.size(); i++) {
			ret += (this->getNumber(this->value[i]) * powl(10, i));
		}
	}
	else {
		Integer* c = *this % ULONG_MAX;
		for (unsigned long long i = 0; i < c->value.size(); i++) {
			ret += (c->getNumber(c->value[i]) * powl(10, i));
		}
		delete c;
	}
	return ret;
};
Integer::operator long long() {
	long ret = 0;
	if (isLongLong()) {
		for (unsigned long long i = 0; i < this->value.size(); i++) {
			ret += (this->getNumber(this->value[i]) * powl(10, i));
		}
	}
	else {
		Integer* c = *this % LLONG_MAX;
		for (unsigned long long i = 0; i < c->value.size(); i++) {
			ret += (c->getNumber(c->value[i]) * powl(10, i));
		}
		delete c;
	}
	if (!this->isPositive) ret = -ret;
	return ret;
};
Integer::operator unsigned long long() {
	unsigned long long ret = 0;
	if (isUnsignedLongLong()) {
		for (unsigned long long i = 0; i < this->value.size(); i++) {
			ret += (this->getNumber(this->value[i]) * powl(10, i));
		}
	}
	else {
		Integer* c = *this % ULONG_MAX;
		for (unsigned long long i = 0; i < c->value.size(); i++) {
			ret += (c->getNumber(c->value[i]) * powl(10, i));
		}
		delete c;
	}
	return ret;
};

bool Integer::isZERO() {
	if (value.size() == 1) {
		if (value[0] == 0) {
			return true;
		}
	}
	return false;
}

bool Integer::isONE() {
	if (value.size() == 1) {
		if (value[0] == 1 && isPositive) {
			return true;
		}
	}
	return false;
}

bool Integer::isNEGONE() {
	if (value.size() == 1) {
		if (value[0] == 1 && !isPositive) {
			return true;
		}
	}
	return false;
}

bool Integer::isEven() {
	if (value.size() > 0) {
		if ((value[0] % 2) == 0) {
			return true;
		}
	}
	return false;
}


void Integer::multOnTen() {
	this->value.add(0);
}
void Integer::divideOnTen() {
	this->value.removeBack();
}
std::string Integer::toString() {
	if (this->isNAN) return "NAN";
	if (value.size() < 1) {
		return "0";
	}
	if (value.size() == 1) {
		if (value[0] == 0) {
			return "0";
		}
	}
	char *ret = new char[value.size()];
	for (unsigned int i = 0; i < value.size(); i++) {
		ret[i] = getChar(value[i]);
	}
	std::string str = std::string(ret, value.size());
	if (!this->isPositive) {
		str = '-' + str;
	}
	return str;
}

Integer* Integer::mod(Integer& a) {
	return *this % a;
}

Integer* Integer::mod(Integer* a) {
	return *this % *a;
}

Integer* Integer::pow(Integer& a) {
	if (a.isZERO()) {
		return new Integer(1);
	}
	else if (a.isONE()) {
		return new Integer(this);
	}
	else if (a.isPositive){
		Integer* l_0 = new Integer(this);
		Integer* tmp = new Integer(a);
		Integer* ret = new Integer(1);
		Integer z = Integer(0);
		while (*tmp > z) {
			if (tmp->isEven()) {
				*l_0 *= *l_0;
				*tmp /= 2;
			}
			else {
				*ret *= *l_0;
				(*tmp)--;
			}
		}
		delete l_0;
		delete tmp;
		return ret;
	}
	else {
		return 0;
	}
}

void Integer::abs() {
	isPositive = true;
}