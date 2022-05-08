#ifndef MYSET_HPP
#define MYSET_HPP

#ifndef CPORTA
#define ELKESZULT 4
#endif

template <typename T, int siz = 10>
class Set {
  T data[siz];
  size_t nElem;
public:
  Set() :nElem(0) { }
  size_t size() const { return nElem; }
  bool isElement(const T& e) const;
  void insert(const T& e);
};

template <typename T, int siz>
void Set<T, siz>::insert(const T& e) {
  if (isElement(e)) return;  
  if (nElem >= siz) throw "Tele";
  data[nElem++] = e;
}

bool operator==(const Point& lhs, const Point& rhs) {
  return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}

template <typename T>
bool equal(const T& a, const T& b) {
  return a == b;
}

template <>
bool equal(const Point& a, const Point& b) {
  return a.getX() == b.getX();
}

template <typename T, int siz>
bool Set<T, siz>::isElement(const T& e) const {
  for(size_t i = 0; i < nElem; i++)
    if(e == data[i]) return true;
  return false;
}

#endif