#ifndef _MAX_HPP
#define _MAX_HPP
/**
 * FELADATOK:
 *  2. Valósítson meg EBBEN a fájlban, a Sajat névtéren belül egy olyan sablont, ami
 *     alaptípusok esetén a paraméterként kapott érték közül a nagyobbat adja.
 *  3. Specializálja a sablont a nem_oo.h állományban deklarált Komplex típusra
 *     úgy hogy a nagyobb abszolút értékû Komplex számot adja vissza!
 *
 * Ügyeljen a helyes névtér használatra!
 *   Tipp: Használja a scope operátort, vagy nyisson névteret!
 */

#include "nem_oo.h"

namespace sajat {
  template <typename T>
  T max(T x, T y) {
    return x > y ? x : y;
  }

  template <>
  Komplex max(Komplex k1, Komplex k2) {
    if(absKomplex(k1) > absKomplex(k2)) {
      return k1;
    } else {
      return k2;
    } 
  }
}


#endif // _MAX_HPP

