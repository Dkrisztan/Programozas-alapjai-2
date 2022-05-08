#include "european.h"
#include "memtrace.h"

using namespace std;

/**
 * @brief Kiirja az european film adatait
 * @param os Az ostream amire az adatokat írja ki
 */
void European::print(ostream& os) const {
  Film::print(os);
  os << "Nyert-e dijat?: " << this->getEuropeanFilmAwards() << endl;
  os << "" << endl;
}

/**
 * @brief Értékadó operátor
 * 
 * @param rhs jobboldai opperandus (Film)
 * @return Film& értékadás után visszatérő Film
 */
European& European::operator=(const European& rhs) {
  setId(0);
  setTitle(rhs.getTitle());
  setDirector(rhs.getDirector());
  setrunningTime(rhs.getrunningTime());
  setreleaseYear(rhs.getreleaseYear());
  setDescription(rhs.getDescription());
  setCategory(rhs.getCategory());
  EuropeanFilmAwards = rhs.EuropeanFilmAwards;
  return *this;
}

/**
 * @brief Egyenlőség vizsgáló operátor
 * 
 * @param rhs jobboldali operandus
 * @return true Ha a két european film megegyezik
 * @return false Ha a két european film nem egyezik meg
 */
bool European::operator==(const European& rhs) const {
  return this->getTitle() == rhs.getTitle() && this->getDirector() == rhs.getDirector() && this->getrunningTime() == rhs.getrunningTime() && this->getreleaseYear() == rhs.getreleaseYear() && this->getDescription() == rhs.getDescription() && this->getCategory() == rhs.getCategory() && EuropeanFilmAwards == rhs.EuropeanFilmAwards;
}