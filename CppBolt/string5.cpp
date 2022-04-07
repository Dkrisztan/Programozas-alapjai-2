/**
 *
 * \file string5.cpp
 *
 * Itt kell megvalósítania a hiányzó tagfüggvényeket.
 * Segítségül megadtuk a C++ nem OO eszközeinek felhasználásával készített String-kezelő
 * függvényke neveit.
 *
 * Ha valamit INLINE-ként valósít meg, akkor annak a string5.h-ba kell kerülnie,
 * akár kívül akár osztályon belül definiálja. (Az inline függvényeknek minden
 * fordítási egységben elérhetőknek kell lenniük)
 * *
 * A teszteléskor ne felejtse el beállítani a string5.h állományban az ELKESZULT makrót.
 *
 */

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Sztringműveletekhez

#include "memtrace.h"           // a standard headerek után kell lennie
#include "string5.h"


/// Konstruktorok: egy char karakterből (createString)
///                egy nullával lezárt char sorozatból (createString)

String::String(char ch) {
  len = 1;
  pData = new char[len + 1];
  pData[0] = ch;
  pData[1] = '\0';
}

String::String(const char *p) {
  len = strlen(p);
  pData = new char[len + 1];
  strcpy(pData, p);
}

/// Másoló konstruktor: String-ből készít (createString)

String::String(const String& s1) {
  len = s1.len;
  pData = new char[len + 1];
  strcpy(pData, s1.pData);
}

/// Destruktor (disposeString)
String::~String() {
  delete[] pData;
}

/// operator=
String& String::operator=(const String& s) {
  if(this != &s) {
    delete[] pData;
    pData = new char[(len = s.len) + 1];
    strncpy(pData, s.pData, len);
    pData[len] = 0;
  }
  return *this;
}

/// [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza (charAtString)
/// indexhiba esetén const char * kivételt dob!

char String::operator[](size_t i) const {
    if(i < 0 || i >= len) {
      throw "QJBZPV";
    }
    return pData[i];
}
 
char& String::operator[](size_t i) {
    if(i < 0 || i >= len) {
      throw "QJBZPV";
    } 
    return pData[i];
}


/// + operátorok:
///                 String-hez jobbról karaktert ad (addString)
///                 String-hez String-et ad (addString)

String String::operator+(String const& rhs) const {
  String uj;
  delete[] uj.pData;
  uj.len = len + rhs.len;
  uj.pData = new char[uj.len + 1];
  strcpy(uj.pData, pData);
  strcat(uj.pData, rhs.pData);
  return uj;
}

String operator+(char c, const String& s) {
  return String(c) + s;
}

String& String::operator+=(String const& rhs) {
  return (*this = *this + rhs);
}

String& String::operator+=(char rhs) {
  char t[2] = {rhs, '\0'};
  return (*this = *this + String(t));
}

/// << operator, ami kiír az ostream-re
std::ostream& operator<<(std::ostream& os, String const& s) {
  os << s.c_str();
  return os;
}

/// >> operátor, ami beolvas az istream-ről egy szót

std::istream& operator>>(std::istream& is, String& s) {
  char c;
  String ret;
  
  while(is.get(c) && !isspace(c)) {
    ret += c;
  }

  s = ret;
  return is;
}