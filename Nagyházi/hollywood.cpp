#include "hollywood.h"
#include "memtrace.h"

using namespace std;

/**
 * @brief Kiirja a Hollywood film adatait
 * @param os Az ostream amire az adatokat írja ki
 */
void Hollywood::print(ostream& os) const {
  Film::print(os);
  os << "Nyert-e dijat?: " << this->getOscarAward() << endl;
  os << "" << endl;
}

/**
 * @brief Értékadó operátor
 * 
 * @param rhs jobboldai opperandus (Film)
 * @return Film& értékadás után visszatérő Film
 */
Hollywood& Hollywood::operator=(const Hollywood& rhs) {
  setId(0);
  setTitle(rhs.getTitle());
  setDirector(rhs.getDirector());
  setrunningTime(rhs.getrunningTime());
  setreleaseYear(rhs.getreleaseYear());
  setDescription(rhs.getDescription());
  setCategory(rhs.getCategory());
  OscarAward = rhs.OscarAward;
  return *this;
}

/**
 * @brief Egyenlőség vizsgáló operátor
 * 
 * @param rhs jobboldali operandus
 * @return true Ha a két Hollywood film megegyezik
 * @return false Ha a két Hollywood film nem egyezik meg
 */
bool Hollywood::operator==(const Hollywood& rhs) const {
  return this->getTitle() == rhs.getTitle() && this->getDirector() == rhs.getDirector() && this->getrunningTime() == rhs.getrunningTime() && this->getreleaseYear() == rhs.getreleaseYear() && this->getDescription() == rhs.getDescription() && this->getCategory() == rhs.getCategory() && OscarAward == rhs.OscarAward;
}