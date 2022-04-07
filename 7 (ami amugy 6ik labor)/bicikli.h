class Jarmu {
  double vMax;
public:
  Jarmu(double v) :vMax(v) { std::cout << "\tJarmu ctor vMax=" << vMax << std::endl; }
  Jarmu(const Jarmu& j) :vMax(j.vMax) { std::cout << "\tJarmu copy vMax=" << j.vMax << std::endl; }
  virtual ~Jarmu() { std::cout << "\tJarmu dtor vMax=" << vMax << std::endl; }
};

class Szan :public Jarmu {
  int kutyakSzama;
public:
  Szan(double v = 0, int n = 0) :Jarmu(v), kutyakSzama(n) { std::cout << "\tSzan ctor kutyakSzama=" << kutyakSzama << std::endl; }
  Szan(const Szan& sz) :Jarmu(sz), kutyakSzama(sz.kutyakSzama) { std::cout << "\tSzan copy kutyakSzama=" << sz.kutyakSzama << std::endl; }
  ~Szan() { std::cout << "\tSzan dtor kutyakSzama=" << kutyakSzama << std::endl; }
};

class Kerek {
  int atmero;
public:
  Kerek(int d) :atmero(d) { std::cout << "\tKerek ctor\n"; }
  Kerek(const Kerek& k) :atmero(k.atmero) { std::cout << "\tKerek copy\n"; }
  void kiir() { std::cout << "atmero=" << atmero << std::endl; }
  virtual ~Kerek() { std::cout << "\tKerek dtor\n"; }
 };

class Bicikli :public Jarmu {
  Kerek elso;
  Kerek hatso;
public:
  Bicikli(double v = 0, int n = 0) :Jarmu(v), elso(n), hatso(n) { std::cout << "\tBicikli ctor "; elso.kiir(); }
  Bicikli(const Bicikli& m) :Jarmu(m), elso(m.elso), hatso(m.hatso) { std::cout << "\tBicikli copy\n";}
  void kiir() { elso.kiir(); }
  ~Bicikli() { std::cout << "\tBicikli dtor atmero="; elso.kiir(); }
 };