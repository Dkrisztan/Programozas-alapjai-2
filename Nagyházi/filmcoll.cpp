#include "filmcoll.h"
#include <sstream>
#include <cstring>

using namespace std;

/**
 * @brief Elem felvétele a filmkollekcióba
 * @param f 
 */
void FilmColl::add(Film& f) {
  f.setId(filmCollection.getnElement());
  filmCollection.addElement(f);
}

/**
 * @brief Elem felvétele a filmkollekcióba 
 * @param f 
 */
void FilmColl::add(Film* f) {
  add(*f);
}

/**
 * @brief Adott indexű elemet töröl a filmgyűjteményből
 * @param id 
 */
void FilmColl::remove(unsigned int id) {
  filmCollection.removeElement(id);
  if(filmCollection.getnElement() < id) throw "A megadott indexu elem nem letezik";
  for(unsigned int i = id; i < filmCollection.getnElement(); i++) {
    filmCollection[i]->setId(filmCollection[i]->getId() - 1);
  }
}

/**
 * @brief Kiírja a gyüjteményben található összes film adatát
 * @param os stream amire kiiratja az adatokat 
 */
void FilmColl::printAll(std::ostream& os) const {
  for(unsigned int i = 0; i < filmCollection.getnElement(); i++) {
    filmCollection[i]->print(os);
    os << endl;
  }
  os << endl;
}

/**
 * @brief Kiirja egy adott film adatát a gyűjteményből
 * @param id 
 * @param os 
 */
void FilmColl::print(unsigned int id, std::ostream& os) const {
  if(filmCollection.getnElement() < id) throw "A megadott indexu elem nem letezik";
  filmCollection[id]->print(os);
  os << endl;
}

/**
 * @brief Megnézi, hogy egy adott nevű film szerepel e a gyűjteményben
 * @param tmp Keresendő film neve 
 * @param os 
 */
void FilmColl::find(const String& tmp, std::ostream& os) const {
  bool result = false;
  for(unsigned int i = 0; i < filmCollection.getnElement(); i++) {
    if(filmCollection[i]->getTitle() == tmp) {
      cout << "Van ilyen film! A film adatai:" << endl;
      cout << endl;
      filmCollection[i]->print(os);
      result = true;
    }
    os << endl;
  }
  if(!result) {
    cout << "Nem talalhato ilyen film!" << endl;
  }
  os << endl;
}

void FilmColl::clear() {
  filmCollection = HeteroColl<Film>();
}

void FilmColl::save(ofstream& f, String fajl) {
  f.open(fajl.c_str());
  for(unsigned int i = 0; i < filmCollection.getnElement(); i++) {
    filmCollection[i]->toFile(f);
  }
}

/**
 * @brief Visszaadja, hogy egy fájlban hány sor van
 * @param s fájl neve
 * @return int 
 */
int nrRow(String s) {
  int sor = 0;
  String line;
  ifstream file;
  file.open(s.c_str());
  while(getlineString(file, line)) {
    sor++;
  }
  return sor;
}

/**
 * @brief Kiolvas egy fájlból
 * @param s ezt a fájlt nyissuk meg 
 * @param coll átadunk neki egy filmgyűjteményt amihez hozzáadhat filmeket
 */
void FilmColl::fromFile(String s) {
  // megnyitunk egy fájlt ami paraméterként lett beadva
  ifstream f;
  f.open(s.c_str());

  string line;      // Ebbe a stringbe olvasunk be egy sort

  string title;
  string director;
  string rT, rY;
  string description;
  string cat;
  string attr;

  string split[7];

  int row = nrRow("film.csv");

  int i = 0;
  while(i < row) {
    
    getline(f, line);
    stringstream oneline(line.c_str());

    for(int i = 0; !oneline.eof(); i++) {
      getline(oneline, split[i], ',');
    }

    unsigned int runningT = stoul(split[2].c_str());
    unsigned int releaseY = stoul(split[3].c_str());

    title = split[0].c_str();
    director = split[1].c_str();
    description = split[4].c_str();
    cat = split[5].c_str();
    attr = split[6].c_str();
    if(attr == "-") {
      Film *film = new Film(title.c_str(), director.c_str(), runningT, releaseY, description.c_str(), retCat(stoi(cat.c_str())));
      this->add(*film);
    } else if(attr == "Nem ArtFilmAwards nyertes") {
      Art *film = new Art(title.c_str(), director.c_str(), runningT, releaseY, description.c_str(), false);
      this->add(*film);
    } else if(attr == "ArtFilmAwards nyertes") {
      Art *film = new Art(title.c_str(), director.c_str(), runningT, releaseY, description.c_str(), true);
      this->add(*film);
    } else if(attr == "Nem EuropeanFilmAwards nyertes") {
      European *film = new European(title.c_str(), director.c_str(), runningT, releaseY, description.c_str(), false);
      this->add(*film);
    } else if(attr == "EuropeanFilmAwards nyertes") {
      European *film = new European(title.c_str(), director.c_str(), runningT, releaseY, description.c_str(), true);
      this->add(*film);
    } else if(attr == "Nem OscarAward nyertes") {
      Hollywood *film = new Hollywood(title.c_str(), director.c_str(), runningT, releaseY, description.c_str(), false);
      this->add(*film);
    } else if(attr == "OscarAward nyertes") {
      Hollywood *film = new Hollywood(title.c_str(), director.c_str(), runningT, releaseY, description.c_str(), true);
      this->add(*film);
    } else if(attr == "0") {
      FarEast *film = new FarEast(title.c_str(), director.c_str(), runningT, releaseY, description.c_str(), retOrg(stoi(attr.c_str())));
      this->add(*film);
    } else if(attr == "1") {
      FarEast *film = new FarEast(title.c_str(), director.c_str(), runningT, releaseY, description.c_str(), retOrg(stoi(attr.c_str())));
      this->add(*film);
    } else if(attr == "2") {
      FarEast *film = new FarEast(title.c_str(), director.c_str(), runningT, releaseY, description.c_str(), retOrg(stoi(attr.c_str())));
      this->add(*film);
    } else if(attr == "3") {
      FarEast *film = new FarEast(title.c_str(), director.c_str(), runningT, releaseY, description.c_str(), retOrg(stoi(attr.c_str())));
      this->add(*film);
    }
    i++;
  }

  f.close();
}