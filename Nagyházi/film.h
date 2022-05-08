/**
 * Movie osztály deklarációja 
 */

#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <fstream>
#include "string.h"
#include "memtrace.h"

using namespace std;

/**
 * @brief A filmek típusai
 */
enum Category {
  Hollywood_,
  Art_,
  FarEast_,
  European_
};

/**
 * @class Film
 * @brief A film osztálya
 */
class Film {
  unsigned int id;          // A film id-je
  String title;             // A film címe
  String director;          // A film rendezője
  unsigned int runningTime; // A film lejátszási hossza percben megadva
  unsigned int releaseYear; // A film kiadási éve
  String description;       // A film rövid leírása
  Category category;        // A film kategóriája
public:
  /**
   * @brief A film osztály paraméteres konstruktora
   * 
   * @param t     A film címe
   * @param dir   A film rendezője
   * @param rT    A film hossza
   * @param rY    A film kiadási éve
   * @param desc  A film leírása
   * @param cat   A film kategóriája
   */
  Film(const String& t, const String& dir, unsigned int rT, unsigned int rY, const String& desc, Category cat = Hollywood_) :id(0), title(t), director(dir), runningTime(rT), releaseYear(rY), description(desc), category(cat) { }

  // A film osztály paraméter nélküli konstruktora
  Film() :id(0), title(""), director(""), runningTime(0), releaseYear(0), description(""), category(Hollywood_) { }

  /**
   * @brief A film osztály másoló konstruktora
   * 
   * @param tmp A film amelyet át fogunk másolni
   */
  Film(const Film& tmp) {
    id = 0;
    title = tmp.title;
    director = tmp.director;
    runningTime = tmp.runningTime;
    releaseYear = tmp.releaseYear;
    description = tmp.description;
    category = tmp.category;
  }

  /**
   * @brief A film osztály virtuális destruktora
   */
  virtual ~Film() { }

  //! SETTEREK
  void setId(unsigned int i) { id = i; }                            // A film id beállítása
  void setTitle(const String& t) { title = t; }                     // A film címének a beállítása
  void setDirector(const String& dir) { director = dir; }           // A film rendezőjének a beállítása
  void setrunningTime(unsigned int rT) { runningTime = rT; }        // A film hosszának a beállítása
  void setreleaseYear(unsigned int rY) { releaseYear = rY; }        // A film kiadási évének a beállítása
  void setDescription(const String& desc) { description = desc; }   // A film leírásának a beállítása
  void setCategory(Category c) { category = c; }                    // A film kategóriájának a beállítása

  //! GETTEREK
  unsigned int getId() const { return id; }                         // A film id lekérdezése
  String getTitle() const { return title; }                         // A film címének a lekérdezése
  String getDirector() const { return director; }                   // A film rendezőjének a lekérdezése
  unsigned int getrunningTime() const { return runningTime; }       // A film hosszának a lekérdezése
  unsigned int getreleaseYear() const { return releaseYear; }       // A film kiadási évének a lekérdezése
  String getDescription() const { return description; }             // A film leírásának a lekérdezése
  Category getCategory() const { return category; }                 // A film kategóriájának a lekérdezése
  String getCategoryStr() const {                                   // A film kategóriájának a lekérdezése stringként (kiiratáshoz)
    if(category == 0) {
      return "Hollywood";
    } else if(category == 1) {
      return "Art";
    } else if(category == 2) {
      return "FarEast";
    } else if(category == 3) {
      return "European";
    }

    return "";
  }               

  virtual void print(ostream& os = cout) const;
  Film& operator=(const Film& rhs);
  bool operator==(const Film& rhs) const;
  Film operator+(const Film& rhs) const;

  virtual void toFile(ofstream& f) const {
    f << title << "," << director << "," << runningTime << "," << releaseYear << "," << description << "," << this->getCategory() << "," << "-" << endl;
  }

};

Category retCat(int cat);
Category retCatStr(String cat);

template<typename T>
T MaratonStick(T first) {
  return first;
}

template<typename T, typename... Args>
T MaratonStick(T first, Args... args) {
  return first + MaratonStick(args...);
}

template<typename F>
void Maraton(F first) {
  cout << MaratonStick(first).getrunningTime() << endl;
}

template<typename F, typename... fArgs>
void Maraton(F first, fArgs... args) {
  cout << MaratonStick(first,args...).getrunningTime() / 60.0 << " ora lenne ezeket a filmeket megnezni" << endl;
}

#endif