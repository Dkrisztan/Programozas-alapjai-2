/**
 * A Filmgyűjtemény osztály deklarációja
 */

#ifndef FILMCOLL_H
#define FIMLCOLL_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "string.h"
#include "hollywood.h"
#include "art.h"
#include "fareast.h"
#include "european.h"
#include "heterocoll.hpp"
#include "memtrace.h"

/**
 * @brief Filmcoll osztály  
 */
class FilmColl {
  HeteroColl<Film> filmCollection; // A filmeket tartalmazó pointertömb
public:
  // Default konstruktor
  FilmColl() :filmCollection(HeteroColl<Film>()) { }

  /**
   * @brief Visszaadja a filmCollection tömböt
   * @return HeteroColl<Film>& 
   */
  HeteroColl<Film>& getFilmCollection() {
    return filmCollection;
  }

  void add(Film& f);
  void remove(unsigned int id);
  void add(Film* f);
  void printAll(std::ostream& os = std::cout) const;
  void print(unsigned int id, std::ostream& os = std::cout) const;
  void find(const String& tmp, std::ostream& os = std::cout) const;
  void clear();
  void save(ofstream& f, String fajl);
  void fromFile(String s);

  ~FilmColl() {}

};

#endif