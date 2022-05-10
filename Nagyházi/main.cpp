#include <iostream>
#include <cstdlib>
#include <cmath>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstring>
#include "memtrace.h"
#include "string.h"
#include "film.h"
#include "art.h"
#include "filmcoll.h"
#include "gtest_lite.h"

using namespace std;

#define JPORTA

FilmColl coll;

// Eldönti egy stringről, hogy szám e
bool isNumber(const string& str) {
  for (char const &c : str) {
    if (isdigit(c) == 0) return false;
  }
  return true;
}

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
  cout << "[3] Filmek listazasa" << endl;
  cout << "[4] Film torlese" << endl;
  cout << "[5] Filmek beolvasasa fajlbol" << endl;
  cout << "[6] Filmek fajlba mentese" << endl;
  cout << "[0] Kilepes a programbol" << endl;
  cout << "Add meg a valasztasod egy fenti szammal: ";
}

void menu() {
  menuoptions();
  int choice;

  // Film adatai
  string title, director, description, category, runningTime, releaseYear;

  while (!(cin >> choice)) {
    cin.clear();
		cin.ignore(1000, '\n');
		cout << "Rossz valasztas! Probald ujra!" << endl;
    sleep(2);
    cout << "\033[2J\033[1;1H";
    menu();
	}
  
  if(choice >= 0 && choice <= 6) {

    switch(choice) {
      case 1: {
        fflush(stdin);
        cout << "Add meg a film nevet: ";
        getline(cin, title);
        cout << "Add meg a film rendezojet: ";
        getline(cin, director);
        cout << "Add meg a film hosszat: ";
        getline(cin, runningTime);
        cout << "Add meg a film kiadasi evet: ";
        getline(cin, releaseYear);
        cout << "Add meg a film leirasat: ";
        getline(cin, description);
        cout << "Add meg a film kategoriajat (Hollywood, Art, FarEast, European): ";
        getline(cin, category);
        fflush(stdin);

        if(isNumber(runningTime) && isNumber(releaseYear)) {

          if(category == "Art") {
            fflush(stdin);
            string option;
            cout << "Nyert-e ArtFilmAwards dijat? (igen/nem): ";
            getline(cin, option);
            if(option == "igen") {
              Art *ujfilm = new Art(title.c_str(), director.c_str(), stoul(runningTime), stoul(releaseYear), description.c_str(), true);
              coll.add(*ujfilm);
            } else if(option == "nem") {
              Art *ujfilm = new Art(title.c_str(), director.c_str(), stoul(runningTime), stoul(releaseYear), description.c_str(), false);
              coll.add(*ujfilm);
            } else {
              cout << "Rossz valasztas! Probald ujra!" << endl;
              sleep(2);
              cout << "\033[2J\033[1;1H";
              menu();
            }
          } else if(category == "Hollywood") {
            fflush(stdin);
            string option;
            cout << "Nyert-e Oscar dijat? (igen/nem): ";
            getline(cin, option);
            if(option == "igen") {
              Hollywood *ujfilm = new Hollywood(title.c_str(), director.c_str(), stoul(runningTime), stoul(releaseYear), description.c_str(), true);
              coll.add(*ujfilm);
            } else if(option == "nem") {
              Hollywood *ujfilm = new Hollywood(title.c_str(), director.c_str(), stoul(runningTime), stoul(releaseYear), description.c_str(), false);
              coll.add(*ujfilm);
            } else {
              cout << "Rossz valasztas! Probald ujra!" << endl;
              sleep(2);
              cout << "\033[2J\033[1;1H";
              menu();
            }
          } else if(category == "European") {
            fflush(stdin);
            string option;
            cout << "Nyert-e EuropeanFilmAwards dijat? (igen/nem): ";
            getline(cin, option);
            if(option == "igen") {
              European *ujfilm = new European(title.c_str(), director.c_str(), stoul(runningTime), stoul(releaseYear), description.c_str(), true);
              coll.add(*ujfilm);
            } else if(option == "nem") {
              European *ujfilm = new European(title.c_str(), director.c_str(), stoul(runningTime), stoul(releaseYear), description.c_str(), false);
              coll.add(*ujfilm);
            } else {
              cout << "Rossz valasztas! Probald ujra!" << endl;
              sleep(2);
              cout << "\033[2J\033[1;1H";
              menu();
            }
          } else if(category == "FarEast") {
            fflush(stdin);
            string option;
            cout << "Honnan ered a film? (China/Japan/Korea/Thailand): ";
            getline(cin, option);
            if(option == "China") {
              FarEast *ujfilm = new FarEast(title.c_str(), director.c_str(), stoul(runningTime), stoul(releaseYear), description.c_str(), China);
              coll.add(*ujfilm);
            } else if(option == "Japan") {
              FarEast *ujfilm = new FarEast(title.c_str(), director.c_str(), stoul(runningTime), stoul(releaseYear), description.c_str(), Japan);
              coll.add(*ujfilm);
            } else if(option == "Korea") {
              FarEast *ujfilm = new FarEast(title.c_str(), director.c_str(), stoul(runningTime), stoul(releaseYear), description.c_str(), Korea);
              coll.add(*ujfilm);
            } else if(option == "Thailand") {
              FarEast *ujfilm = new FarEast(title.c_str(), director.c_str(), stoul(runningTime), stoul(releaseYear), description.c_str(), Thailand);
              coll.add(*ujfilm);
            } else {
              cout << "Rossz valasztas! Probald ujra!" << endl;
              sleep(2);
              cout << "\033[2J\033[1;1H";
              menu();
            }
          } else {
            cout << "Rossz kategoria! Probald ujra!" << endl;
            sleep(2);
            cout << "\033[2J\033[1;1H";
            menu();
          }
        } else {
          cout << "Nem szamot adtal meg a lejatszasi idohoz vagy/es a kiadasi evhez! Probald ujra!" << endl;
          sleep(3);
          cout << "\033[2J\033[1;1H";
          menu();
        }

        cout << "Film hozzaadva!" << endl;
        sleep(2);
        cout << "\033[2J\033[1;1H";;
        menu();
        break;
      }

      case 2: {
        string s;
        fflush(stdin);
        cout << "Add meg a keresendo film nevet: ";
        getline(cin, s);
        try {
          coll.find(s.c_str(), cout);
        } catch(char const* err) {
          cout << "Kivetelt dobott mivel nem letezik ilyen film" << endl;
        }
        do {
          cout << endl;
          cout << "Nyomj Entert a folytatashoz...";
        } while (cin.get() != '\n');
        cout << "\033[2J\033[1;1H";;
        menu();
        break;
      }

      case 3: {
        cout << endl;
        cout << "################################" << endl;
        cout << "#                              #" << endl;
        cout << "#  Az osszes Film a taroloban  #" << endl;
        cout << "#                              #" << endl;
        cout << "################################" << endl;
        cout << endl;
        coll.printAll(cout);
        fflush(stdin);
        do {
          cout << endl;
          cout << "Nyomj Entert a folytatashoz...";
        } while (cin.get() != '\n');
        cout << "\033[2J\033[1;1H";;
        menu();
        break;
      }

      case 4: {
        fflush(stdin);
        unsigned int r; 
        cout << "Add meg a torulni kivant film id-jet: ";
        while (!(cin >> r)) {
          cin.clear();
		      cin.ignore(1000, '\n');
		      cout << "Rossz szamot adtal meg! Probald ujra!" << endl;
          sleep(2);
          cout << "\033[2J\033[1;1H";;
          menu();
	      }
        coll.remove(r);
        cout << "Film torulve!" << endl;
        sleep(2);
        cout << "\033[2J\033[1;1H";;
        menu();
        break;
      }

      case 5: {
        string fajl;
        fflush(stdin);
        cout << "Add meg a fajl nevet: ";
        getline(cin, fajl);
        coll.fromFile(fajl.c_str());
        cout << endl;
        coll.printAll(cout);
        fflush(stdin);
        do {
          cout << endl;
          cout << "Nyomj Entert a folytatashoz...";
        } while (cin.get() != '\n');
        cout << "\033[2J\033[1;1H";;
        menu();
        break;
      }

      case 6: {
        string fajl;
        fflush(stdin);
        cout << "Add meg a fajl nevet amibe mentse a filmeket: ";
        getline(cin, fajl);
        ofstream f;
        coll.save(f, fajl.c_str());
        f.close();
        cout << "\nA film sikeresen fajlba mentve!" << endl;
        do {
          cout << endl;
          cout << "Nyomj Entert a folytatashoz...";
        } while (cin.get() != '\n');
        cout << "\033[2J\033[1;1H";;
        menu();
        break;
      }

      case 0:
        exit(0);
        
      default:
        cout << "Rossz valasztas" << endl;
        break;
    }
  } else {
    cout << "Rossz valasztast adtal meg! Probald ujra!" << endl;
    sleep(2);
    cout << "\033[2J\033[1;1H";;
    menu();
  }
}

#ifdef JPORTA
void tests() {
  // Konstruktor tesztelése
  TEST(Filmek, Konstruktorok) {

    // Az összes típusú film konstruktorának tesztelése
    stringstream s1, s2, s3, s4, s5, s6;

    Film *f = new Film("Frida","Julie Taymor",123,2002,"A film Frida Kahlo mexikoi festono eletet mutatja be. 1922-ben Mexikovarosban Frida elvezi diakeveit a rajongo ferfiakat.",retCatStr("Art"));
    Hollywood *h = new Hollywood("Spider-Man","Sam Raimi",121,2002,"A film kozeppontjaban Peter Parker all egy szerencsetlen kulonc tinedzser akinek az elete hatalmas fordulatot vesz miutan megcsipi egy mutans pok.",false);
    Art *a = new Art("Leon the Professional","Luc Besson",133,1994,"Egy olasz bergyilkos akinek nincsenek erzelmei sok tejet iszik ulve alszik es nagy rajongoja a Gene Kelly-filmeknek. O Leon (Jean Reno) aki a legjobb a varosban egyedul dolgozik es maganyosan el.", true);
    European *e = new European("Intouchables","Olivier Nakache",108,2011,"Egy afrikai szarmazasu sofor bekesen vezet a kocsisorban a parizsi ejszakaban es idonkent figyelmes pillantast vet a mellette ulo korszakallas bajuszos feher utasara.",false);
    FarEast *fe = new FarEast("Parasite","Bong Joon-ho",132,2019,"Kim Githek es csaladja egy felszuterenben lakik Szoulban ahova nem sut be a nap es rendszeresen az ablakuk ala vizelnek a reszegek. A csalad alkalmi munkakbol tengodik mikozben nagyra toro almaik vannak.",retOrg("Korea"));
    Film *p = new Film();

    // Másoló konstruktor tesztelése
    Film copy = *p;

    f->print(s1);
    h->print(s2);
    a->print(s3);
    e->print(s4);
    fe->print(s5);
    p->print(s6);

    EXPECT_STREQ("Id: 0\nCim: Frida\nRendezo: Julie Taymor\nHossz: 123 perc\nKiadasi ev: 2002\nLeiras: A film Frida Kahlo mexikoi festono eletet mutatja be. 1922-ben Mexikovarosban Frida elvezi diakeveit a rajongo ferfiakat.\nKategoria: Art\n", s1.str().c_str());
    EXPECT_STREQ("Id: 0\nCim: Spider-Man\nRendezo: Sam Raimi\nHossz: 121 perc\nKiadasi ev: 2002\nLeiras: A film kozeppontjaban Peter Parker all egy szerencsetlen kulonc tinedzser akinek az elete hatalmas fordulatot vesz miutan megcsipi egy mutans pok.\nKategoria: Hollywood\nNyert-e dijat?: Nem OscarAward nyertes\n\n", s2.str().c_str());
    EXPECT_STREQ("Id: 0\nCim: Leon the Professional\nRendezo: Luc Besson\nHossz: 133 perc\nKiadasi ev: 1994\nLeiras: Egy olasz bergyilkos akinek nincsenek erzelmei sok tejet iszik ulve alszik es nagy rajongoja a Gene Kelly-filmeknek. O Leon (Jean Reno) aki a legjobb a varosban egyedul dolgozik es maganyosan el.\nKategoria: Art\nNyert-e dijat?: ArtFilmAwards nyertes\n\n", s3.str().c_str());
    EXPECT_STREQ("Id: 0\nCim: Intouchables\nRendezo: Olivier Nakache\nHossz: 108 perc\nKiadasi ev: 2011\nLeiras: Egy afrikai szarmazasu sofor bekesen vezet a kocsisorban a parizsi ejszakaban es idonkent figyelmes pillantast vet a mellette ulo korszakallas bajuszos feher utasara.\nKategoria: European\nNyert-e dijat?: Nem EuropeanFilmAwards nyertes\n\n", s4.str().c_str());
    EXPECT_STREQ("Id: 0\nCim: Parasite\nRendezo: Bong Joon-ho\nHossz: 132 perc\nKiadasi ev: 2019\nLeiras: Kim Githek es csaladja egy felszuterenben lakik Szoulban ahova nem sut be a nap es rendszeresen az ablakuk ala vizelnek a reszegek. A csalad alkalmi munkakbol tengodik mikozben nagyra toro almaik vannak.\nKategoria: FarEast\nA film eredete: Korea\n\n", s5.str().c_str());
    EXPECT_STREQ("Id: 0\nCim: \nRendezo: \nHossz: 0 perc\nKiadasi ev: 0\nLeiras: \nKategoria: Hollywood\n", s6.str().c_str());
    
    // Másoló konstruktor tesztelése
    EXPECT_EQ(p->getDescription(), copy.getDescription());

    delete f;
    delete h;
    delete a;
    delete e;
    delete fe;
    delete p;
  } ENDM

  // Maraton függvény tesztelése
  TEST(Filmek, Maraton) {
    Film *f = new Film("Frida","Julie Taymor",123,2002,"A film Frida Kahlo mexikoi festono eletet mutatja be. 1922-ben Mexikovarosban Frida elvezi diakeveit a rajongo ferfiakat.",retCatStr("Art"));
    Film *h = new Film("Spider-Man","Sam Raimi",121,2002,"A film kozeppontjaban Peter Parker all egy szerencsetlen kulonc tinedzser akinek az elete hatalmas fordulatot vesz miutan megcsipi egy mutans pok.",retCatStr("European"));
    Film *a = new Film("Leon the Professional","Luc Besson",133,1994,"Egy olasz bergyilkos akinek nincsenek erzelmei sok tejet iszik ulve alszik es nagy rajongoja a Gene Kelly-filmeknek. O Leon (Jean Reno) aki a legjobb a varosban egyedul dolgozik es maganyosan el.", retCatStr("FarEast"));
    
    stringstream s;
    Maraton(s, *f, *h, *a);
    EXPECT_STREQ("6.28333 ora lenne ezeket a filmeket megnezni\n", s.str().c_str());

    delete f;
    delete h;
    delete a;
  } ENDM

  // Üres gyűjtemény tesztelése
  TEST(FilmGyujtemeny, UresGyujtemeny) {
    FilmColl coll;
    stringstream s;
    unsigned int i = 0;
    EXPECT_EQ(i, coll.getFilmCollection().getnElement());
    coll.printAll(s);
    EXPECT_STREQ("\n", s.str().c_str());
  } ENDM

  // Gyűjteményhez adás tesztelése
  TEST(FilmGyujtemeny, GyujtemenyhezAdas) {
    FilmColl coll;
    stringstream s;
    Film *f = new Film("Frida","Julie Taymor",123,2002,"A film Frida Kahlo mexikoi festono eletet mutatja be. 1922-ben Mexikovarosban Frida elvezi diakeveit a rajongo ferfiakat.",retCatStr("Art"));
    coll.add(*f);
    coll.printAll(s);
    EXPECT_STREQ("Id: 0\nCim: Frida\nRendezo: Julie Taymor\nHossz: 123 perc\nKiadasi ev: 2002\nLeiras: A film Frida Kahlo mexikoi festono eletet mutatja be. 1922-ben Mexikovarosban Frida elvezi diakeveit a rajongo ferfiakat.\nKategoria: Art\n\n\n", s.str().c_str());
    
    // Teszteljük a túlindexelést is.
    EXPECT_ANY_THROW(coll.print(123123,s));
  } ENDM

  // Gyűjteményben keresés tesztelése
  TEST(FilmGyujtemeny, Kereses) {
    FilmColl coll;
    stringstream s;
    Hollywood *h = new Hollywood("Spider-Man","Sam Raimi",121,2002,"A film kozeppontjaban Peter Parker all egy szerencsetlen kulonc tinedzser akinek az elete hatalmas fordulatot vesz miutan megcsipi egy mutans pok.",false);
    coll.add(*h);
    coll.find(h->getTitle(), s);
    EXPECT_STREQ("Van ilyen film! A film adatai:\n\nId: 0\nCim: Spider-Man\nRendezo: Sam Raimi\nHossz: 121 perc\nKiadasi ev: 2002\nLeiras: A film kozeppontjaban Peter Parker all egy szerencsetlen kulonc tinedzser akinek az elete hatalmas fordulatot vesz miutan megcsipi egy mutans pok.\nKategoria: Hollywood\nNyert-e dijat?: Nem OscarAward nyertes\n\n\n\n", s.str().c_str());
    
    // Teszteljük azt is ha nem létezik a film.
    EXPECT_ANY_THROW(coll.find("expectthrow",s));
  } ENDM

  // Gyűjteménybe olvasás tesztelése
  TEST(FilmGyujtemeny, FajlbolKiolvasas) {
    FilmColl coll;
    stringstream s;
    coll.fromFile("test.csv");
    coll.printAll(s);
    EXPECT_STREQ("Id: 0\nCim: Frida\nRendezo: Julie Taymor\nHossz: 123 perc\nKiadasi ev: 2002\nLeiras: A film Frida Kahlo mexikoi festono eletet mutatja be. 1922-ben Mexikovarosban Frida elvezi diakeveit a rajongo ferfiakat.\nKategoria: Art\n\nId: 1\nCim: Spider-Man\nRendezo: Sam Raimi\nHossz: 121 perc\nKiadasi ev: 2002\nLeiras: A film kozeppontjaban Peter Parker all egy szerencsetlen kulonc tinedzser akinek az elete hatalmas fordulatot vesz miutan megcsipi egy mutans pok.\nKategoria: Hollywood\nNyert-e dijat?: Nem OscarAward nyertes\n\n\n\n", s.str().c_str());
  } ENDM

}
#endif

int main() {

  #ifndef JPORTA
  // Felhasználói felület ha nincs JPORTA definiálva -> menü
  while(true) {
    menu();
  }
  #endif

  // csak akkor teszteljen ha JPORTAN van, másképp felhasználói felület
  #ifdef JPORTA
  tests();
  #endif

  return 0;
}