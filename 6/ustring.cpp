#include <iostream> 
#include <cstring>              
#include "ustring.h"
#include "memtrace.h"        

bool UString::ucase = false;

void UString::UCase(bool caps) {
  UString::ucase = caps;
}

bool UString::UCase() {
  return UString::ucase;
}

std::ostream& operator<<(std::ostream& os, const UString& s0) {
  for(size_t i = 0; i < s0.size(); i++) {
    char ch = UString::UCase() ? toupper(s0[i]) : s0[i];
    os << ch;
  }
  return os;
}