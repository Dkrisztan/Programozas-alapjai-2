/**
 * \file pirodistak.h
 * Minden származtatott irodista osztály perzisztens változatának deklarációját ebbe a fájlba tegye!
 * Az egyszerűség kedvéért minden tagfüggvényt inline valósítson meg!
 *
 */
#ifndef PIRODISTAK_H
#define PIRODISTAK_H

#include <stdexcept>
#include "palkalmazott.h"
#include "irodistak.h"


// " itt készitse el a PCsopVez, PHatIdeju, PHatIdCsV és PHatIdCsVezH, osztályokat!"

/**
 * Perzisztens csoportvezető
 */

struct PCsopVez : public CsopVez, public Serializable {
  PCsopVez(const std::string& n, double f, csop_t cs) :Alkalmazott(n, f), CsopVez(n, f, cs) {}
  PCsopVez(const CsopVez& csv) : Alkalmazott(csv), CsopVez(csv) {}
  void write(std::ostream& os) const {
    os << "PCsopVez" << std::endl;
    PAlkalmazott(*this).write(os);
    os << getCs() << std::endl;
  }
  void read(std::istream& is) {
    std::string tmp;
    (is >> tmp).ignore(1);
    if (tmp != "PCsopVez") 
      throw std::out_of_range("PCsopvez_R "+tmp);
    PAlkalmazott pa("",0);
    pa.read(is);
    *((Alkalmazott*)this) = pa; 
    csop_t cs;
    (is >> cs).ignore(1);        
    setCs(cs);
  }
};

/**
 * Perzisztens Határozott idejű alkalmazott
 */
struct PHatIdeju : public HatIdeju, public Serializable {
  PHatIdeju(const std::string& n, double f, time_t t):Alkalmazott(n, f), HatIdeju(n, f, t) {}
  PHatIdeju(const HatIdeju& hati) : Alkalmazott(hati), HatIdeju(hati) {}
  void write(std::ostream& os) const {
    os << "PHatIdeju" << std::endl;
    PAlkalmazott(*this).write(os);  
    os << getIdo() << std::endl;
  }
  void read(std::istream& is) {
    std::string tmp;
    (is >> tmp).ignore(1);
    if (tmp != "PHatIdeju")    
      throw std::out_of_range("PHatIdeju_R "+tmp);
    PAlkalmazott pa("",0);    
    pa.read(is);
    *((Alkalmazott*)this) = pa; 
    time_t t;
    (is >> t).ignore(1);       
    setIdo(t);
  }
};

/**
 * Perzisztens Határozott idejű csoportvezető
 */
struct PHatIdCsV :public HatIdCsV, public Serializable {
  PHatIdCsV(const std::string& n, double f, csop_t cs, time_t t) :Alkalmazott(n, f), HatIdCsV(n, f, cs, t) {}
  PHatIdCsV(const HatIdCsV& haticsv) :Alkalmazott(haticsv), HatIdCsV(haticsv) {}
  void write(std::ostream& os) const {
    os << "PHatIdCsV" << std::endl;
    PCsopVez(*this).write(os); 
    os << getIdo() << std::endl;
  }
  void read(std::istream& is) {
    std::string tmp;
    (is >> tmp).ignore(1);
    if (tmp != "PHatIdCsV")    
      throw std::out_of_range("PHatIdCsV_R "+tmp);
    PCsopVez pcs("", 0, 0);    
    pcs.read(is);
    *((CsopVez*)this) = pcs;  
    time_t t;
    (is >> t).ignore(1);      
    setIdo(t);
  }
};

/**
 * Perzisztens Határozott idejű csoportvezető helyettes
 */
class PHatIdCsVezH :public HatIdCsVezH, public Serializable {

public:
  PHatIdCsVezH(const  std::string& n, double f, time_t t, HatIdCsV& kit) :Alkalmazott(n, f), HatIdCsVezH(n, f, t, kit) {}
  PHatIdCsVezH(const HatIdCsVezH& h) : Alkalmazott(h), HatIdCsVezH(h) {}
  void write(std::ostream& os) const {
    os << "PHatIdCsVezH" << std::endl;  
    PHatIdCsV(*this).write(os);
  }
  void read(std::istream& is) {
    std::string tmp;
    (is >> tmp).ignore(1);
    if (tmp != "PHatIdCsVezH")     
      throw std::out_of_range("PHatIdCsVezH: read");
    PHatIdCsV phcs("", 0, 0, 0);    
    phcs.read(is);
    *((HatIdCsV*)this) = phcs;    
  }
};

#endif // IRODISTAK_H