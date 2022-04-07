// String osztály

#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
  char *pData;
  size_t len;
public:

  // Hossz lekérdezése.
	size_t size() const { return len; }

  // C-sztringet ad vissza
  const char* c_str() const { return pData;}
  
  // Konstruktor egy char karakterből
  String(char ch);
  
  // Default konstruktor egy nullával lezárt char sorozatból
  String(const char *p = "");
  
  // Másoló konstruktor
  String(const String& s1);

  /// Destruktor
  virtual ~String() { delete[] pData; }

  // Kiírunk egy Stringet (debug célokra)
  // Előtte kiírunk egy tetszőleges szöveget.
  void printDbg(const char *txt = "") const {
    std::cout << txt << "[" << len << "], " << (pData ? pData : "(NULL)") << std::endl;
  }

  // Értékadó operátor
  String& operator=(const String& rhs_s);

  // Két Stringet összefűz
  String operator+(const String& rhs_s) const;

  // Sztringhez karaktert összefűz
  String operator+(char rhs_c) const { return *this + String(rhs_c); }

  // A string egy megadott indexű elemének REFERENCIÁJÁVAL tér vissza
  char& operator[](unsigned int idx);

  // A string egy megadott indexű elemének REFERENCIÁJÁVAL tér vissza
  const char& operator[](unsigned int idx) const;
};

// Ostreamre való kiiratás
std::ostream& operator<<(std::ostream& os, const String& s0);

// Szó beolvasása az istreamről egy stringbe
std::istream& operator>>(std::istream& is, String& s0);

// Karakterhez sztringet fűz
inline String operator+(char ch, const String& str) { return String(ch) + str; }

#endif