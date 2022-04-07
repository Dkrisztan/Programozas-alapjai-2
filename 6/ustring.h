#ifndef USTRING_H
#define USTRING_H

#include "string5.h"
#include <iostream>

class UString :public String {
  static bool ucase;
public:
  UString() :String() { }
  UString(const String& s1) :String(s1){ }
  static void UCase(bool);
  static bool UCase();
};

std::ostream& operator<<(std::ostream& os, const UString& s0);

#endif