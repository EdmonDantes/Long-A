#include "Float.h"

Float::Float(const Float& a):Integer(a) {};

Float::~Float() {
	this->value.~DimValue();
};

Integer* Float::pow(Float& a){
	Integer::pow(a);
};