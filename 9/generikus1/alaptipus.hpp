#ifndef ALAPTIPUS_HPP
#define ALAPTIPUS_HPP

template<class T>
class Alaptipus {
  T szam;
public:
  Alaptipus(T szam = 0) :szam(szam) { }
  operator T&()       { return szam; }
  operator T() const  { return szam; }
  T* operator&()      { return &szam; } 
  const T* operator&() const { return &szam; }
  virtual ~Alaptipus() { }
};
#endif