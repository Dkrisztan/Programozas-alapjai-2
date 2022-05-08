#include "memtrace.h"
#include "film.h"

using namespace std;

/** 
 * @brief Kiirja egy film adatait
 * @param os Az ostream, amire az adatokat írja ki
 */
void Film::print(ostream& os) const {
  os << "Id: " << id << endl;
  os << "Cim: " << title << endl;
  os << "Rendezo: " << director << endl;
  os << "Hossz: " << runningTime << " perc" << endl;
  os << "Kiadasi ev: " << releaseYear << endl;
  os << "Leiras: " << description << endl;
  os << "Kategoria: " << this->getCategoryStr() << endl;
}

/**
 * @brief Értékadó operátor
 * 
 * @param rhs jobboldai opperandus (Film)
 * @return Film& értékadás után visszatérő Film
 */
Film& Film::operator=(const Film& rhs) {
  id = 0;
  title = rhs.title;
  director = rhs.director;
  runningTime = rhs.runningTime;
  releaseYear = rhs.releaseYear;
  description = rhs.description;
  category = rhs.category;
  return *this;
}

/**
 * @brief Egyenlőség vizsgáló operátor
 * 
 * @param rhs jobboldali operandus
 * @return true Ha a két film megegyezik
 * @return false Ha a két film nem egyezik meg
 */
bool Film::operator==(const Film& rhs) const {
  return title == rhs.title && director == rhs.director && runningTime == rhs.runningTime && releaseYear == rhs.releaseYear && description == rhs.description && category == rhs.category;
}

/**
 * @brief Két film összeadása (a hosszukat adja össze)
 * 
 * @param rhs jobboldali operandus
 * @return Film 
 */
Film Film::operator+(const Film& rhs) const {
  Film temp;
  temp.runningTime = runningTime + rhs.getrunningTime();
  return temp;
}

Category retCat(int cat) {
  if(cat == 0)
    return Hollywood_;
  if(cat == 1)
    return Art_;
  if(cat == 2)
    return FarEast_;
  if(cat == 3)
    return European_;
  return Hollywood_;
}

Category retCatStr(String cat) {
  if(cat == "Hollywood")
    return Hollywood_;
  if(cat == "Art")
    return Art_;
  if(cat == "FarEast")
    return FarEast_;
  if(cat == "European")
    return European_;
  return Hollywood_;
}