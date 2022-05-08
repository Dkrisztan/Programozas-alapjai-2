#ifndef MONOTON_HPP
#define MONOTON_HPP

template <class Iter, class Pred>
bool monoton(Iter eleje, Iter vege, Pred pred) {
  if (eleje == vege) {
    return true;
  }
  Iter leg = eleje++;
  Iter i = eleje;
  while (i != vege && pred(*i, *leg)) {
    if (pred(*i, *leg)) {
      leg++;
      i++;
    }
  }
  if(i == vege) return true;
  else return false;
}

#endif