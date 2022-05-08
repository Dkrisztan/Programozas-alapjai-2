/**
 * FarEast osztály deklarációja
 */

#ifndef FAREAST_H
#define FAREAST_H

#include <iostream>
#include "film.h"
#include "memtrace.h"

using namespace std;

/**
 * @brief A FarEast filmek típusai
 */
enum Origin {
  China,
  Japan,
  Korea,
  Thailand
};

class FarEast :public Film {
  Origin origin;              // Hova valósi a film
public:
  /**
   * @brief A FarEast osztály paraméteres konstruktora
   * 
   * @param t     A film címe
   * @param dir   A film rendezője
   * @param rT    A film hossza
   * @param rY    A film kiadási éve
   * @param desc  A film leírása
   * @param org   A film eredete
   */
  FarEast(const String& t, const String& dir, unsigned int rT, unsigned int rY, const String& desc, Origin org = Japan) :Film(t, dir, rT, rY, desc), origin(org) { setCategory(FarEast_); }

  // A FarEast osztály paraméter nélküli konstruktora
  FarEast() :Film(), origin(Japan) { setCategory(FarEast_); }

  /**
   * @brief Az art osztály másoló konstruktora
   * 
   * @param tmp Átmásolandó film
   */
  FarEast(const FarEast& tmp) :Film(tmp) {
    origin = tmp.origin;
  }

  /**
   * @brief A FarEast osztály destruktora
   */
  ~FarEast() { }

  // A film eredetének a lekérdezése
  Origin getOrigin() const {
    return origin;
  }

  // A film eredetének stringként való kiiratása
   String getOriginStr() const {
    if(origin == 0) {
      return "China";
    } else if (origin == 1) {
      return "Japan";
    } else if (origin == 2) {
      return "Korea";
    } else if (origin == 3) {
      return "Thailand";
    }
    return "";
  } 

  void print(ostream& os = cout) const;
  FarEast& operator=(const FarEast& rhs);
  bool operator==(const FarEast& rhs) const;
  bool operator==(const Film& rhs) const {
    return false;
  }
  void toFile(ofstream& f) const {
    f << this->getTitle() << "," << this->getDirector() << "," << this->getrunningTime() << "," << this->getreleaseYear() << "," << this->getDescription() << "," << this->getCategory() << "," << this->getOrigin() << endl;
  }

};

Origin retOrg(String org);
Origin retOrg(int org);

#endif