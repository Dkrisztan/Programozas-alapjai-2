#include "art.h"
#include "memtrace.h"

using namespace std;

/**
 * @brief Kiirja az art film adatait
 * @param os Az ostream amire az adatokat írja ki
 */
void Art::print(ostream& os) const {
  Film::print(os);
  os << "Nyert-e dijat?: " << this->getArtFilmAwards() << endl;
  os << "" << endl;
}

/**
 * @brief Értékadó operátor
 * 
 * @param rhs jobboldai opperandus (Film)
 * @return Film& értékadás után visszatérő Film
 */
Art& Art::operator=(const Art& rhs) {
  setId(0);
  setTitle(rhs.getTitle());
  setDirector(rhs.getDirector());
  setrunningTime(rhs.getrunningTime());
  setreleaseYear(rhs.getreleaseYear());
  setDescription(rhs.getDescription());
  setCategory(rhs.getCategory());
  ArtFilmAwards = rhs.ArtFilmAwards;
  return *this;
}

/**
 * @brief Egyenlőség vizsgáló operátor
 * 
 * @param rhs jobboldali operandus
 * @return true Ha a két art film megegyezik
 * @return false Ha a két art film nem egyezik meg
 */
bool Art::operator==(const Art& rhs) const {
  return this->getTitle() == rhs.getTitle() && this->getDirector() == rhs.getDirector() && this->getrunningTime() == rhs.getrunningTime() && this->getreleaseYear() == rhs.getreleaseYear() && this->getDescription() == rhs.getDescription() && this->getCategory() == rhs.getCategory() && ArtFilmAwards == rhs.ArtFilmAwards;
}