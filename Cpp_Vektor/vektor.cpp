#include <iostream>
#include "vektor.h"

size_t Vektor::defSize = 10;
double Vektor::defValue = 30;

Vektor::Vektor(const Vektor& a) {
  this->nElements = a.nElements;
  pVec = new double[a.nElements];
  for (size_t i = 0; i < a.nElements; i++)
    pVec[i] = a.pVec[i];
}

Vektor::~Vektor() {
  delete[] pVec;
}

Vektor& Vektor::operator=(const Vektor& a) {
  this->nElements = a.nElements;
  for (size_t i = 0; i < a.nElements; i++)
    this->pVec[i] = a.pVec[i];
  return *this;
}

double& Vektor::operator[](size_t idx) {
  if(idx >= this->nElements) {
    throw "QJBZPV";
  } else if(idx < 0) {
    throw "QJBZPV";
  }
  return this->pVec[idx];
}

const double& Vektor::operator[](size_t idx) const {
  if(idx >= this->nElements) {
    throw "QJBZPV";
  } else if(idx < 0) {
    throw "QJBZPV";
  }
  return this->pVec[idx];
}

Vektor operator*(double val, const Vektor& vec) {
  Vektor ret = vec;
  for(size_t i = 0; i < vec.size(); i++) {
    ret[i] = vec[i] * val;
  }
  return ret;
}