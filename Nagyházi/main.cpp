#include <iostream>
#include "string.h"

using namespace std;

//! majd a film osztalyba fog kerulni

class Valami {
  String nev;
  int hossz;
public:
  Valami() { nev = ""; hossz = 0; }
  Valami(String s, int h) { nev = s; hossz = h; }
  int getSize() const { return hossz; }
  void setSize(int h) { hossz = h; }
  String getNev() const { return nev; }
  ~Valami() { }
  Valami operator+(const Valami& rhs_s) const {
    Valami temp;
    temp.hossz = hossz + rhs_s.getSize();
    return temp;		
  }
};

std::ostream& operator<<(std::ostream& os, const Valami& v) {
  os << v.getSize();
  return os;
}

template<typename T>
T Maraton(T first) {
  return first;
}

template<typename T, typename... Args>
T Maraton(T first, Args... args) {
  return first + Maraton(args...);
}

int main() {
  
  Valami okay("ok", 123);
  Valami nemokay("nemok", 10);
  Valami talan("nemok", 20);
  Valami nemtudom("nemok", 15);

  cout << Maraton(okay, nemokay, talan, nemtudom);
  // cout << s2.Maraton(s1, s2) << endl; ez most meg nem mukodik, de majd fog a heterogen kollekcional
  
  return 0;
}