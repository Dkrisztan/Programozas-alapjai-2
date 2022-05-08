#include <iostream>          
#include <cstring>             
#include "string.h"

using std::cin;
using std::ios_base;

// Konstruktor egy karakterből
String::String(char ch) {
  len = 1;
  pData = new char[len+1];
  pData[0] = ch;
  pData[1] = '\0';
}

// Default konstruktor egy nullával lezárt char sorozatból
String::String(const char *p) {
  len = strlen(p);
  pData = new char[len+1];
  strcpy(pData, p);
}

// Másoló konstruktor
String::String(const String& s1) {
  len = s1.len;
  pData = new char[len+1];
  strcpy(pData, s1.pData);
}

// Értékadó operator=
String& String::operator=(const String& rhs_s) {
  if(this != &rhs_s) {
    delete[] pData;
    len = rhs_s.len;
    pData = new char[len+1];
    strcpy(pData, rhs_s.pData);
  }
  return *this;
}

// Indexelő [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza
char& String::operator[](unsigned int idx) {
  if (idx >= len) throw "String: indexelesi hiba";
  return pData[idx];
}

const char& String::operator[](unsigned int idx) const {
  if (idx >= len) throw "String: indexelesi hiba";
  return pData[idx];
}

// Összeadó + operátor, ami két stringet ad össze
String String::operator+(const String& rhs_s) const {
  String temp;
  temp.len = len + rhs_s.len;
  delete[] temp.pData;
  temp.pData = new char[temp.len+1];
  strcpy(temp.pData, pData);
  strcat(temp.pData, rhs_s.pData);

  return temp;		
}

// Ostream << operator
std::ostream& operator<<(std::ostream& os, const String& s0) {
  os << s0.c_str();
  return os;
}

// Istream >> operátor
std::istream& operator>>(std::istream& is, String& s0) {
  unsigned char ch;
  s0 = String("");
	std::ios_base::fmtflags fl = is.flags();
	is.setf(ios_base::skipws);
  while (is >> ch) {
	  is.unsetf(ios_base::skipws);
    if(ch == '\n') {
      break;
    }
    s0 = s0 + ch;
  }
	is.setf(fl);
  return is;
}

std::istream& getlineString(std::istream& is, String& str, char delim) {
  char ch;
  int i = 0;
  while (is.get(ch) && ch != delim) {
    str = str + ch;
    i++;
  }
  return is;
}