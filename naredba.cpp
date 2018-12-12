#include <iostream>
#include "naredba.hpp"
#include "izraz.hpp"
#include <map>

extern map<string, int> tablica;

void NaredbaDodele::Izvrsi() const {
  tablica[_s] = _izraz->Vrednost();
}

void NaredbaIspisa::Izvrsi() const {
  cout<<_izraz->Vrednost()<<endl;
}

void PraznaNaredba::Izvrsi() const {
  
}

void BlokNaredba::Izvrsi() const {
  vector<Naredba*>::iterator i;
  for (i = _vec->begin(); i!=_vec->end(); i++) {
    (*i)->Izvrsi();
  }
}

void IfElseNaredba::Izvrsi() const {
  if (_uslov->Vrednost())
    _naredba->Izvrsi();
  else
    _else_naredba->Izvrsi();
}

void WhileNaredba::Izvrsi() const {
  while(_uslov->Vrednost()) {
    _petlja->Izvrsi();
  }
}

void RepeatUntilNaredba::Izvrsi() const {
  do {
    vector<Naredba*>::iterator i;
    for (i = _niz->begin(); i!=_niz->end(); i++)
      (*i)->Izvrsi();
  }
  while (!_uslov->Vrednost());
}
