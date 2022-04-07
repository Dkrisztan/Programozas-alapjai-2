// Fájl: fuggvenyeim.cpp
// Ebben találhatók a függvények prototípusai,
// típusok, konstansok, egyéb deklarációk

#ifndef FUGGVENYEIM_H
#define FUGGVENYEIM_H

/*
  5-ös feladat
  6-os feladat
  @param f - független változó
  @param fok - polinom fokszám
  @param double eho[] - polinom együtthatói
*/

double polinom(double f, int fok, double eho[]);

/*
 * csere
 * Két int adat felcserélése
 * @param a - egyik adat
 * @param b - másik adat
 */

void csere(int& a, int& b);

/*
 * max
 * Két int adat közül a nagyobb
 * @param a - egyik adat
 * @param b - másik adat
 */
// Ez egy inline függvény, amit minden fordítási
// egységben definiálni kell.
inline int max(int a, int b) { return a > b ? a : b; }


/// Segédfüggvény double pontosságú számok összehasonlításához
bool almostEQ(double a, double  b);

#endif // FUGGVENYEIM_H
