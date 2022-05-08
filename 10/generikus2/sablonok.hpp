#ifndef SABLONOK_HPP
#define SABLONOK_HPP

#define ELKESZULT 7

template <typename Iter>
void printEach(Iter first, Iter last, std::ostream& os, const char *sep = ",") {
  while (first != last) {
    os << *first++;
    if (first != last) os << sep;
    else os << std::endl;
  }
}

template <typename Iter>
int szamol_ha_negativ(Iter first, Iter last) {
  int cnt = 0;
  while (first != last)
    if (*first++ < 0) cnt++;
  return cnt;
}

template <typename Iter, typename Pred>
int szamol_ha(Iter first, Iter last, Pred pred) {
  int cnt = 0;
  while (first != last)
    if (pred(*first++)) cnt++;
  return cnt;
}

#endif