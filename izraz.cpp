#include "izraz.hpp"

#include <map>
using namespace std;

extern map<string, int> tablica;

extern int yyerror(string s);

int Promenljiva::Vrednost() const {
  map<string, int>::iterator i=tablica.find(_s);
	if(i!=tablica.end()) return tablica[_s];
	else return 0;
}

int Konstanta::Vrednost() const {
  return _broj;
}

int Plus::Vrednost() const {
  return _prvi->Vrednost() + _drugi->Vrednost();
}

int Minus::Vrednost() const {
  return _prvi->Vrednost() - _drugi->Vrednost();
}

int Zvezda::Vrednost() const {
  return _prvi->Vrednost() * _drugi->Vrednost();
}

int Podeljeno::Vrednost() const {
  if (_drugi->Vrednost()==0)
    yyerror("Deljenje nulom");
  return _prvi->Vrednost() / _drugi->Vrednost();
}

int Stepen::Vrednost() const {
  int tmp=1;
  for(int i=_drugi->Vrednost();i>0;i--)
    tmp*=_prvi->Vrednost();
  return tmp;
}

int Manje::Vrednost() const {
  return _prvi->Vrednost() < _drugi->Vrednost();
}

int Vece::Vrednost() const {
  return _prvi->Vrednost() > _drugi->Vrednost();
}
