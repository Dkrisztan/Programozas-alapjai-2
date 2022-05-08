/**
 * European osztály deklarációja
 */

#ifndef EUROPEAN_H
#define EUROPEAN_H

#include <iostream>
#include "film.h"
#include "memtrace.h"

using namespace std;

/**
 * @class European 
 * @brief Az European típusú filmek osztálya
 */
class European :public Film {
  bool EuropeanFilmAwards;      // Nyert-e European Film Awards-ot
public:
  /**
   * @brief Az european osztály paraméteres konstruktora
   * 
   * @param t     A film címe
   * @param dir   A film rendezője
   * @param rT    A film hossza
   * @param rY    A film kiadási éve
   * @param desc  A film leírása
   * @param EFA   Nyert e a film EuropeanFilmAwards-ot
   */
  European(const String& t, const String& dir, unsigned int rT, unsigned int rY, const String& desc, bool EFA = false) :Film(t, dir, rT, rY, desc), EuropeanFilmAwards(EFA) { setCategory(European_); }

  // Az european osztály paraméter nélküli konstruktora
  European() :Film(), EuropeanFilmAwards(false) { setCategory(European_); }

  /**
   * @brief Az european osztály másoló konstruktora
   * 
   * @param tmp Átmásolandó film
   */
  European(const European& tmp) :Film(tmp) {
    EuropeanFilmAwards = tmp.EuropeanFilmAwards;
  }

  /**
   * @brief Az european osztály destruktora
   */
  ~European() { }

  /**
   * @brief Nyert e awards-ot a film
   * 
   * @return Visszatéríti, hogy nyert e vagy nem awards-ot 
   */
  String getEuropeanFilmAwards() const {
    if(EuropeanFilmAwards) return "EuropeanFilmAwards nyertes";
    return "Nem EuropeanFilmAwards nyertes";
  }

  void print(ostream& os = cout) const;
  European& operator=(const European& rhs);
  bool operator==(const European& rhs) const;
  bool operator==(const Film& rhs) const {
    return false;
  }
  void toFile(ofstream& f) const {
    f << this->getTitle() << "," << this->getDirector() << "," << this->getrunningTime() << "," << this->getreleaseYear() << "," << this->getDescription() << "," << this->getCategory() << "," << this->getEuropeanFilmAwards() << endl;
  }
  
};

#endif