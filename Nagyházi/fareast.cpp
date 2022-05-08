#include "fareast.h"
#include "memtrace.h"

using namespace std;

/**
 * @brief Kiirja a fareast film adatait
 * @param os Az ostream amire az adatokat írja ki
 */
void FarEast::print(ostream& os) const {
  Film::print(os);
  os << "A film eredete: " << this->getOriginStr() << endl;
  os << "" << endl;
}

/**
 * @brief Értékadó operátor
 * 
 * @param rhs jobboldai opperandus (Film)
 * @return Film& értékadás után visszatérő Film
 */
FarEast& FarEast::operator=(const FarEast& rhs) {
  setId(0);
  setTitle(rhs.getTitle());
  setDirector(rhs.getDirector());
  setrunningTime(rhs.getrunningTime());
  setreleaseYear(rhs.getreleaseYear());
  setDescription(rhs.getDescription());
  setCategory(rhs.getCategory());
  origin = rhs.origin;
  return *this;
}

/**
 * @brief Egyenlőség vizsgáló operátor
 * 
 * @param rhs jobboldali operandus
 * @return true Ha a két fareast film megegyezik
 * @return false Ha a két fareast film nem egyezik meg
 */
bool FarEast::operator==(const FarEast& rhs) const {
  return this->getTitle() == rhs.getTitle() && this->getDirector() == rhs.getDirector() && this->getrunningTime() == rhs.getrunningTime() && this->getreleaseYear() == rhs.getreleaseYear() && this->getDescription() == rhs.getDescription() && this->getCategory() == rhs.getCategory() && origin == rhs.origin;
}

Origin retOrg(String org) {
  if(org == "China")
    return China;
  if(org == "Korea")
    return Korea;
  if(org == "Japan")
    return Japan;
  if(org == "Thailand")
    return Thailand;
  return China;
}

Origin retOrg(int org) {
  if(org == 0)
    return China;
  if(org == 1)
    return Japan;
  if(org == 2)
    return Korea;
  if(org == 3)
    return Thailand;
  return China;
}