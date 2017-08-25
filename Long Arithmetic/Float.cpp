#include "Float.h"

Float::Float(const Integer& a) :Integer(a) {};

Float::Float(const Float& a):Integer(a){
	this->id = a.id;
};

Float::~Float(){
	this->value.~DimValue();
};