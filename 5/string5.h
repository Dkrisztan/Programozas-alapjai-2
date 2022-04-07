#ifndef STRING_H
#define STRING_H
/**
 * \file string5.h
 *
 * Ez a fájl tartalmazza a
 *   - String osztály deklarációját
 *   - az inline függvényeket. Ha valamit inline-ként akar megvalósítani,
 *     akkor azt ebbe a fájlba írja! Tipikusan a rövid kódokat szokás
 *     inline-két megvalósítani (pl: c_str).
 *     Más függvényeket ill. definíciókat ne írjon a .h fájlba!
 *
 * A C nyelven megvalósított String adatszerkezetet (string1) a 2. laboron a
 * C++ nyelv nem OO eszközeivel átalakítottuk (string2_cpp).
 *
 * Most továbblépünk és a String adatszerkezetet igazi osztállyá alakítjuk:
 * Az adatokon műveletet végző függvényeket összezárjuk az adatokkal,
 * így ezek a függvények tagfüggvényekké válnak és
 *   formálisan eltűnik az első paraméterük (s0) (ezt this-ként azért megkapják).
 * A nevük is megváltozik, mert most már az összetartozást, és a
 *   paraméterek típusára való utalást már nem a név hordozza, hanem az osztály.
 * A createString... alakú függvényekből konstruktorok keletkeznek.
 * A disposeString destruktorrá alakul át.
 * Egyes műveletvégző függvényekből pedig operátor függvény lesz.
 */

/**
 * Az Ön feladata ebben fájlban bővíteni a megkezdett deklarációt, és string5.cpp
 * fájlban pedig megvalósítani (definiálni) az osztály egyes függvényeit úgy,
 * hogy az a lenti követelményeknek eleget tegyen.
 *
 * Ahogyan halad a megvalósítással egyre több tesztesetet kell lefuttatni,
 * ezért az ELKESZULT makró értéket folyamatosan növelje a feladatsorszámoknak
 * megfelelően!
 *
 * Tanulságos a megvalósítás előtt már a megnövelt értékkel is lefordítani
 * a programot, és elemezni a kapott hibajelzést.
 *
 */

/**
 * Az ELKESZULT makró értékét a lenti feladatoknak megfelelően állítsa be,
 * azaz, sorban haladva ahol tart a feladatok megoldásában!
 * Ne hagyjon ki feladatot!
 */
#define ELKESZULT 10

/**
 * \section fel Feladat:
 * A 2. laborgyakorlaton létrehoztunk egy dinamikus sztring (String) adatszerkezet
 * és a rajta műveleteket végző függvényeket
 * A tanultakat felhasználva a string5.h és a string5.cpp állományokban definiáljon ill.
 * implementáljon egy olyan sztring (String) osztályt C++ nyelven, ami dinamikusan tárol
 * és rendelkezik az alábbi tulajdonságokkal:
 *
 *ELKESZULT értéke - feladatok:
 *  1  A paraméter nélkül hívható konstruktora üres sztringet hozzon létre!
 *     Van olyan tagfüggvénye ( size() ), ami visszaadja a sztring hosszát.
 *  2. Van olyan tagfüggvénye ( c_str() ), ami C-sztringgel, azaz nullával lezárt
 *     karaktersorozatra mutató pointerrel (const char *) tér vissza.
 *  3. Van olyan konstruktora, ami karakterből hoz létre sztringet.
 *  4. Van olyan konstruktora, ami C-sztringből (const char*) hoz létre sztringet.
 *  5. Az osztályból létrehozott objektum legyen átadható értékparaméterként!
 *  6. Támogassa a többszörös értékadást (b = a = a)!
 *  7. Legyenek olyan operátorai (operator+), amivel a sztring végéhez sztringet
 *     és karaktert is lehet fűzni!
 *  8. Lehessen karakterhez is sztringet fűzni a + operátorral!
 *  9. A tárolt a karakterek legyenek elérhetőek a szokásos módon indexeléssel!
 *     Az indexeléssel elért elem legyen használható balértékként is!
 *     A konstans objektumok is legyenek indexelhetők.
 *     Az indexelési hiba esetén dobjon const char * kivételt!
 * 10. Készítsen olyan << operátort, amivel egy sztring kiírható egy ostream típusú
 *     objektumra!
 */

#include <iostream>

#ifndef MEMTRACE

#endif // MEMTRACE

class String {
    char *pData;        ///< pointer az adatra
    size_t len;         ///< hossz lezáró nulla nélkül
public:
/// Kiírunk egy Stringet (debug célokra)
/// Ezt a tagfüggvényt elkészítettük, hogy használja a hibák felderítéséhez.
/// Igény szerint módosítható
/// @param txt - nullával lezárt szövegre mutató pointer.
///              Ezt a szöveget írjuk ki a debug információ előtt.
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << '|' << std::endl;
    }

/// Két lehetőség van:
///     a) nem NULL pointert tárol, hanem ténylegesen üres sztringet.
///     b) NULL-t tárol, de a c_str() üres sztringet ad vissza helyette
/// Bármelyik megoldás jó, mert ez az osztály belügye.


    /// Paraméter nélküli konstruktor:
    String() :pData(0), len(0) {
      const char *s = "";
      pData = new char[(len = strlen(s)) + 1];
      strncpy(pData, s, len);
      pData[len] = 0; 
    }

    /// Sztring hosszát adja vissza.
    /// @return sztring tényleges hossza (lezáró nulla nélkül).
    size_t size() const { return len; }

    /// C-sztringet ad vissza
    /// @return pointer a tárolt, vagy azzal azonos tartalmú nullával lezárt sztring-re.
    const char* c_str() const { return pData; }

/// Itt folytassa a tagfüggvények deklarációit a feladatoknak megfelelően.
/// ...

    ~String();
    String(char ch);
    String(const char *p);
    String(const String& s1);
    String& operator=(const String& s);
    String operator+(String const& rhs) const;
    String& operator+=(String const& rhs);
    String& operator+=(char rhs);
    char operator[](size_t i) const;
    char& operator[](size_t i);

}; /// Itt az osztály deklarációjának vége

/// Ide kerülnek a globális operátorok deklarációi.
/// ...

String operator+(char c, const String& s); // ez valamiert globalis operator kell legyen
std::ostream& operator<<(std::ostream& os, String const& str);
std::istream& operator>>(std::istream& is, String& str);

#endif
