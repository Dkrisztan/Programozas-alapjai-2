#ifndef EMBER_H
#define EMBER_H

class Ember {
  char *nev;

protected:
  int szulEv;

public:
  Ember(const char* n = "QJBZPV", int ev = 2002); // default konstruktor
  Ember(const Ember&);  // masolo konstruktor
  Ember& operator=(const Ember&); // ertekado operator
  const char* getNev() const; // nev lekerdezese
  virtual int getKor(int) const; // kor lekerdezese 
  int getKor() const; // kor lekerdezese
  virtual const char* foglalkozas() const; // foglalkozas 
  virtual ~Ember(); // destruktor
};

#endif