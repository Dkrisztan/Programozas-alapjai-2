/**
 * Hollywood osztály deklarációja
 */

#ifndef HOLLYWOOD_H
#define HOLLYWOOD_H

#include <iostream>
#include "film.h"
#include "memtrace.h"

using namespace std;

/**
 * @class Hollywood 
 * @brief Az Hollywood típusú filmek osztálya
 */
class Hollywood :public Film {
  bool OscarAward;     // Nyert-e Hollywood Film Awards-ot
public:
  /**
   * @brief Az Hollywood osztály paraméteres konstruktora
   * 
   * @param t     A film címe
   * @param dir   A film rendezője
   * @param rT    A film hossza
   * @param rY    A film kiadási éve
   * @param desc  A film leírása
   * @param OA   Nyert e a film OscarAward-ot
   */
  Hollywood(const String& t, const String& dir, unsigned int rT, unsigned int rY, const String& desc, bool OA = false) :Film(t, dir, rT, rY, desc), OscarAward(OA) { setCategory(Hollywood_); }

  // Az Hollywood osztály paraméter nélküli konstruktora
  Hollywood() :Film(), OscarAward(false) { setCategory(Hollywood_); }

  /**
   * @brief Az Hollywood osztály másoló konstruktora
   * 
   * @param tmp Átmásolandó film
   */
  Hollywood(const Hollywood& tmp) :Film(tmp) {
    OscarAward = tmp.OscarAward;
  }

  /**
   * @brief Az Hollywood osztály destruktora
   */
  ~Hollywood() { }

  /**
   * @brief Nyert e awards-ot a film
   * 
   * @return Visszatéríti, hogy nyert e vagy nem awards-ot 
   */
  String getOscarAward() const {
    if(OscarAward) return "OscarAward nyertes";
    return "Nem OscarAward nyertes";
  }

  void print(ostream& os = cout) const;
  Hollywood& operator=(const Hollywood& rhs);
  bool operator==(const Hollywood& rhs) const;
  bool operator==(const Film& rhs) const {
    return false;
  }
  void toFile(ofstream& f) const {
    f << this->getTitle() << "," << this->getDirector() << "," << this->getrunningTime() << "," << this->getreleaseYear() << "," << this->getDescription() << "," << this->getCategory() << "," << this->getOscarAward() << endl;
  }

};

#endif