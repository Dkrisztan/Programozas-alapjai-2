/**
 * \file resistor.cpp
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállást modellező osztály megvalósítása
 */

/**
 * Itt kell megvalósítani a resistor.h-ban deklarált nem inline függvényeket.
 * A Jportára ezt a fájlt kell feltölteni.
 */

#include <iostream>
#include "resistor.h"

double Resistor::defR = 55;

Resistor::Resistor() {
  this->R = defR;
  Pr("ctor0");
}

Resistor::Resistor(double r) {
  this->R = r;
  Pr("ctor1");
}

Resistor::Resistor(const Resistor& rhs) :R(rhs.R) {
  Pr("Copy");
}

Resistor::~Resistor() {
  Pr("dtor");
}

Resistor& Resistor::operator=(const Resistor& rhs) {
  Pr("assign");
  R = rhs.R;
  return *this;
}

double Resistor::getU(double i) const {
  return i * R;
}

double Resistor::getI(double u) const {
  return u / R;
}

void Resistor::setDef(double r) {
   Resistor::defR = r;
}

Resistor Resistor::operator+(const Resistor& r)const {
  return Resistor(r.getR()+this->R);
}

Resistor Resistor::operator%(const Resistor& r)const {
  return Resistor (1/(1/(r.getR())+1/this->R));
}

Resistor operator*(int n, const Resistor& r) {
  if(n <= 0) {
    throw("QJBZPV");
  }
  return Resistor (n * r.getR());
}