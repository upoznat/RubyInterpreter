#ifndef __NAREDBA_HPP__
#define __NAREDBA_HPP__

#include <string>
#include <map>
#include <vector>
#include "izraz.hpp"


class Naredba {
public:
  virtual void Izvrsi() const = 0;
  virtual ~Naredba() {

  }
};

class NaredbaDodele : public Naredba {
public:
  NaredbaDodele(string s, Izraz *i)
    :_s(s), _izraz(i)
  {}
  void Izvrsi() const;
  ~NaredbaDodele() {
    delete _izraz;
  }
private:
  //zbog destruktora, treba nam op. dodele i kopi konstr.
  NaredbaDodele operator = (const NaredbaDodele& n);
  NaredbaDodele(const NaredbaDodele& n);
  string _s;
  Izraz *_izraz;
};

class NaredbaIspisa : public Naredba {
public:
  NaredbaIspisa(Izraz *i)
    :_izraz(i)
  {}
  void Izvrsi() const;
  ~NaredbaIspisa () {
    delete _izraz;
  }
private:
  NaredbaIspisa operator = (const NaredbaIspisa& n);
  NaredbaIspisa(const NaredbaIspisa& n);
  Izraz *_izraz;
};

class PraznaNaredba : public Naredba {
public:
  PraznaNaredba()
  {}
  void Izvrsi() const;
};

class BlokNaredba : public Naredba {
public:
  BlokNaredba(vector<Naredba *>*vec)
    :_vec(vec)
  {}
  void Izvrsi() const;
  ~BlokNaredba() {
    vector<Naredba *>::iterator i;
    for (i = _vec->begin(); i!=_vec->end(); i++)
      delete(*i);
    delete _vec;
  }
private:
  BlokNaredba operator = (const BlokNaredba& n);
  BlokNaredba(const BlokNaredba& n);
  vector<Naredba *> *_vec;
};

class IfElseNaredba : public Naredba {
public:
  IfElseNaredba(Izraz *i, Naredba *n1, Naredba *n2)
    :_uslov(i), _naredba(n1), _else_naredba(n2)
  {}
  void Izvrsi() const;
  ~IfElseNaredba () {
    delete _uslov;
    delete _naredba;
    delete _else_naredba;
  }
private:
  IfElseNaredba operator = (const IfElseNaredba& i);
  IfElseNaredba(const IfElseNaredba& i);
  Izraz *_uslov;
  Naredba *_naredba;
  Naredba *_else_naredba;
};

class WhileNaredba : public Naredba {
public:
  WhileNaredba(Izraz *i, Naredba *n)
    :_uslov(i), _petlja(n)
  {}
  void Izvrsi() const;
  ~WhileNaredba () {
    delete _uslov;
    delete _petlja;
  }
private:
  WhileNaredba operator = (const WhileNaredba& w);
  WhileNaredba(const WhileNaredba& w);
  Izraz *_uslov;
  Naredba *_petlja;
};

class RepeatUntilNaredba : public Naredba {
public:
  RepeatUntilNaredba(vector<Naredba*> *niz, Izraz *i)
    :_uslov(i), _niz(niz)
  {}
  void Izvrsi() const;
  ~RepeatUntilNaredba () {
    delete _uslov;
    vector<Naredba*>::iterator i;
    for (i = _niz->begin(); i!=_niz->end(); i++)
      delete (*i);
    delete _niz;
  }
private:
  RepeatUntilNaredba operator = (const RepeatUntilNaredba& r);
  RepeatUntilNaredba(const RepeatUntilNaredba& r);
  Izraz *_uslov;
  vector<Naredba*> *_niz;
};


#endif
