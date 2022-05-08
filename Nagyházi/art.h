/**
 * Art osztály deklarációja
 */

#ifndef ART_H
#define ART_H

#include <iostream>
#include "film.h"
#include "memtrace.h"

using namespace std;

/**
 * @class Art 
 * @brief Az Art típusú filmek osztálya
 */
class Art :public Film {
  bool ArtFilmAwards;     // Nyert-e Art Film Awards-ot
public:
  /**
   * @brief Az art osztály paraméteres konstruktora
   * 
   * @param t     A film címe
   * @param dir   A film rendezője
   * @param rT    A film hossza
   * @param rY    A film kiadási éve
   * @param desc  A film leírása
   * @param AFA   Nyert e a film ArtFilmAwards-ot
   */
  Art(const String& t, const String& dir, unsigned int rT, unsigned int rY, const String& desc, bool AFA = false) :Film(t, dir, rT, rY, desc), ArtFilmAwards(AFA) { setCategory(Art_); }

  // Az art osztály paraméter nélküli konstruktora
  Art() :Film(), ArtFilmAwards(false) { setCategory(Art_); }

  /**
   * @brief Az art osztály másoló konstruktora
   * 
   * @param tmp Átmásolandó film
   */
  Art(const Art& tmp) :Film(tmp) {
    ArtFilmAwards = tmp.ArtFilmAwards;
  }

  /**
   * @brief Az art osztály destruktora
   */
  ~Art() { }

  /**
   * @brief Nyert e awards-ot a film
   * 
   * @return Visszatéríti, hogy nyert e vagy nem awards-ot 
   */
  String getArtFilmAwards() const {
    if(ArtFilmAwards) return "ArtFilmAwards nyertes";
    return "Nem ArtFilmAwards nyertes";
  }

  void print(ostream& os = cout) const;
  Art& operator=(const Art& rhs);
  bool operator==(const Art& rhs) const;
  bool operator==(const Film& rhs) const {
    return false;
  }
  void toFile(ofstream& f) const {
    f << this->getTitle() << "," << this->getDirector() << "," << this->getrunningTime() << "," << this->getreleaseYear() << "," << this->getDescription() << "," << this->getCategory() << "," << this->getArtFilmAwards() << endl;
  }

};

#endif