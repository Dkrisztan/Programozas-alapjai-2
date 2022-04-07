/**
 * \file kassza.cpp
 *
 * Kassza osztály tagfüggvényeinek megvalósítása (definíciója)
 */

#include <iostream>
#include <iomanip>

#include "memtrace.h"
#include "kassza.h"

using std::setw;

/// Eladás.
/// @param mennyi - eladott mennyiség
/// @param mit  - referencia az eladott árura (Kompatibilitás kihasználása)
/// @param mikor - eladás dátuma
/// @return kivételt dob, ha nem fér be
void Kassza::elad(double mennyi, const Aru& mit, const Datum& mikor) {
    tetelek[db++] = Tetel(mennyi, &mit, mikor);
    if(db > maxdb) {
      throw "A Kassza megtelt";
    }
}

/// Kassza tartalmának kilistázása
/// @param os - output stream
void Kassza::list(std::ostream& os) const {
    for (size_t i = 0; i < db; i++) {
        os << tetelek[i].datum << ": "
           << setw(4) << tetelek[i].mennyiseg * tetelek[i].aru->getAr() << "Ft" << " -- "
           << tetelek[i].mennyiseg << " "
           << tetelek[i].aru->getEgys() << " "
           << *tetelek[i].aru << std::endl;
    }
}

/// Eladások listázása egy adott napon
/// @param os - output stream
/// @param mikor - melyik nap
void Kassza::list(std::ostream& os, const Datum& mikor) const {
  for (size_t i = 0; i < db; i++) {
		if (tetelek[i].datum == mikor) {
			os << tetelek[i].datum << ": " << setw(4) << tetelek[i].mennyiseg * tetelek[i].aru->getAr() << "Ft" << " -- " << tetelek[i].mennyiseg << " " << tetelek[i].aru->getEgys() << " " << *tetelek[i].aru << std::endl;
		}
	}
}

/// Eladások összege egy adott napra
/// @param mikor - melyik nap
/// @return - összeg
double Kassza::napiOsszeg(const Datum& mikor) {
  double ret = 0;
	for (size_t i = 0; i < db; i++) {
		if (tetelek[i].datum == mikor) {
			ret = ret + (tetelek[i].mennyiseg * tetelek[i].aru->getAr());
		}
	}
	return ret;
}

