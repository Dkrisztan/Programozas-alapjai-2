/**
 * A heterogén kollekció osztálya
 */

#ifndef HETEROCOLL_HPP
#define HETEROCOLL_HPP

#include <iostream>
#include "memtrace.h"

/**
 * @brief Heterogén kollekció osztály
 * @tparam T sablonparaméter
 */
template<class T>
class HeteroColl {
  unsigned int nElement;    // Az elemek száma
  T** data;                 // A tömbre mutató pointer
public: 
  // Default konstruktor
  HeteroColl<T>() :nElement(0), data(new T*[nElement]) { }

  /**
   * @brief Másoló konstruktor
   * 
   * @param temp 
   */
  HeteroColl<T>(const HeteroColl* temp) :nElement(temp.nElement), data(new T*[nElement]) {
    for(unsigned int i = 0; i < temp.nElement; i++) {
      data[i] = temp.data[i];
    }
  }

  /**
   * @brief Destruktor
   */
  virtual ~HeteroColl<T>() {
    for(unsigned int i = 0; i < nElement; i++) {
      delete data[i];
    }
    delete[] data;
  }

  // Visszaadja a darabszámot
  unsigned int getnElement() const {
    return nElement;
  }

  /**
   * @brief Elem felvétele a kollekcióba
   * @param tmp A hozzáadandó elem
   */
  void addElement(T& tmp) {
    T** tempdata = new T*[nElement + 1];
    for(unsigned int i = 0; i < nElement; i++) {
      tempdata[i] = data[i];
    }
    tempdata[nElement] = &tmp;
    delete[] data;
    data = tempdata;
    nElement++;
  }

  /**
   * @brief Töröl egy elemet a kollekcióból
   * @param id A törlendő elem id-ja
   */
  void removeElement(unsigned int id) {
    if(nElement <= id) throw "Nem letezik az adott azonositoju elem";
    nElement--;
    T** tempdata = new T*[nElement];
    for(unsigned int i = 0; i < nElement; i++) {
      if(id <= i) {
        tempdata[i] = data[i+1];
      } else {
        tempdata[i] = data[i];
      }
    }
    delete data[id];
    delete[] data;
    data = tempdata;
  }

  /**
   * @brief Indexelő operátor
   * @param id Elem indexe
   * @return T*& visszatéríti a tömd adott elemét
   */
  T*& operator[](unsigned int id) const {
    if(nElement <= id) throw "Nem letezik az adott azonositoju elem";
    return data[id];
  }

};

#endif