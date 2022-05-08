#include <iostream>
#include <cstdlib>
#include <cmath>
#include <unistd.h>
#include <fstream>
#include "memtrace.h"
#include "string.h"
#include "film.h"
#include "art.h"
#include "filmcoll.h"

using namespace std;

void menuoptions() {

  //! Csak design szempontból van
  cout << " ______ _ _                          _ _         " << endl;
  cout << " |  ___(_) |                        | (_)        " << endl;    
  cout << " | |_   _| |_ __ ___  _ __   ___  __| |_  __ _   " << endl;        
  cout << " |  _| | | | '_ ` _ \\| '_ \\ / _ \\/ _` | |/ _` |  " << endl; 
  cout << " | |   | | | | | | | | |_) |  __/ (_| | | (_| |  " << endl;
  cout << " \\_|   |_|_|_| |_| |_| .__/ \\___|\\__,_|_|\\__,_|  " << endl;  
  cout << "                     | |                         " << endl;       
  cout << "                     |_|                         " << endl;
  cout << " " << endl;
  cout << "[1] Film letrehozasa" << endl;
  cout << "[2] Film keresese" << endl;
  cout << "[3] Film listazasa" << endl;
  cout << "[4] Film torlese" << endl;
  cout << "[0] Kilepes a programbol" << endl;
  cout << "Add meg a valasztasod egy fenti szammal: ";
}

void menu() {
  menuoptions();
  int choice;
  cin >> skipws >> choice;
  getchar();
  if(choice >= 0 && choice <= 4) {
    switch(choice) {
      case 1:
        
        break;

      case 2:

        break;

      case 3:

        break;

      case 4:

        break;
      
      case 0:
        exit(0);
        
      default:
        cout << "Rossz valasztas" << endl;
        throw "Rossz valasztas";
        break;
    }
  } else {
    cout << "Rossz valasztas! Probald ujra!" << endl;
    sleep(2);
    system("cls || clear");
    menu();
  }
}

int main() {

  // while(true) {          
  //   menu();                  
  //   system("cls || clear");
  // }


  // Maraton(a,b,c); //! mukodik a maraton

  // ofstream f;
  // f.open("film.csv");

  //! Igy fog kinezni a fajlbairatas +ehhez meg kell a gyujtemenyhez adas ?? talan

  // String title, director, description, category;
  // unsigned int runningTime, releaseYear;

  // cout << "Add meg a film nevet: ";
  // cin >> title;
  // cout << "Add meg a film rendezojet: ";
  // cin >> director;
  // cout << "Add meg a film hosszat: ";
  // cin >> runningTime;
  // cout << "Add meg a film kiadasi evet: ";
  // cin >> releaseYear;
  // cout << "Add meg a film leirasat: ";
  // cin >> description;
  // cout << "Add meg a film kategoriajat (Hollywood, Art, FarEast, European): ";
  // cin >> category;
  // cout << endl;

  
  // a.toFile(f);
  // b.toFile(f);
  // f.close();

  //! Igy nez ki a fajlbol kiiratas

  // String title;
  // String director;
  // String rT, rY;
  // String description;
  // String cat;

  // getlineString(f, title, ',');
  // getlineString(f, director, ',');
  // getlineString(f, rT, ',');
  // getlineString(f, rY, ',');
  // getlineString(f, description, ',');
  // getlineString(f, cat, ',');

  // unsigned int runningT = stoul(rT.c_str());
  // unsigned int releaseY = stoul(rY.c_str());

  
  // Film *ujfilm = new Film(title, director, runningT, releaseY, description, retCat(stoi(cat.c_str())));
  // ujfilm->print();
  // delete ujfilm;

  // Film a("Frozen 2","Johnny Lawrence",123,2002,"ilyen random nagyon hosszu leiras hat mindjart meghalok xd",retCatStr("Art"));
  // Film b("Frozen 2","Johnny Lawrence",123,2012,"ilyen random mindjart meghalok xd",retCatStr("Art"));
  
  // ofstream f;

  // FilmColl coll;
  // coll.add(a);
  // coll.add(b);
  // coll.print(1,cout);
  // coll.find("Frozen 2"); // ez igy most ketszer irja ki
  // coll.save(f);
  
  // f.close();

  // Film *a = new Film("Frozen 2","Johnny Lawrence",123,2002,"ilyen random  leiras hat mindjart meghalok xd",retCatStr("Art"));
  // Film *b = new Film("Frozen 2","Johnny Lawrence",123,2042,"ilyen random nagyon hosszu leiras hat mindjart meghalok xd",retCatStr("European"));
  // Film *c = new Film("Frozen 2","Johnny Lawrence",123,2012,"ilyen random nagyon hossz",retCatStr("Hollywood"));
  
  // Maraton(*a, *b, *c);

  // FilmColl coll;
  // coll.printAll(cout); // itt nincs memoriaszivargas
  // coll.print(0, cout); // ez exceptiont dob de azert mert ures, viszont nincs memoriaszivargasos gond
  // coll.add(*a);
  // coll.add(*b);
  // coll.add(*c);
  // coll.printAll(cout);

  // ofstream f;
  // coll.save(f);
  // f.close();

  //! megadja hogy hany sor van egy fajlban, majd egy ekkora objektumtombot kell kesziteni es kiolvasni az adatokat
  // int sor = 0;
  // String line;

  // ifstream file;
  // file.open("film.csv");

  // while(getlineString(file, line)) {
  //   sor++;
  // }
  // cout << sor;


  return 0;
}