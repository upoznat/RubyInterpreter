#ifndef __IZRAZ_HPP__ 
#define __IZRAZ_HPP__

#include <string>

using namespace std;

class Izraz {
public:
  virtual ~Izraz() {
  
  }
  virtual int Vrednost() const = 0;
};

class Promenljiva : public Izraz {
public:
  Promenljiva (string s) 
    :_s(s)
  {} 
  int Vrednost() const;
private:
  string _s;
};

class Konstanta : public Izraz {
public:
  Konstanta(int broj) 
    : _broj(broj)
  {}
  int Vrednost() const ;
private:
  int _broj;
};

class BinarniOperator : public Izraz {
public:
  BinarniOperator(Izraz *prvi, Izraz *drugi)
    :_prvi(prvi), _drugi(drugi)
  {}
  ~BinarniOperator() {
    delete _prvi;
    delete _drugi;
  }
private:
  //zbog destruktora, treba nam op. dodele i kopi konstr.
  BinarniOperator(const BinarniOperator& b);
protected:
  Izraz *_prvi;
  Izraz *_drugi;
};


class Plus : public BinarniOperator {
public:
  Plus(Izraz *prvi, Izraz *drugi)
    :BinarniOperator(prvi, drugi)
  {}
  int Vrednost() const ;
private:
  Plus operator = (const Plus& p);
};

class Minus : public BinarniOperator {
public:
  Minus(Izraz *prvi, Izraz *drugi)
    :BinarniOperator(prvi, drugi)
  {}
  int Vrednost() const;
private:
  Minus operator = (const Minus& p);
};

class Zvezda : public BinarniOperator {
public:
  Zvezda(Izraz *prvi, Izraz *drugi)
    :BinarniOperator(prvi, drugi)
  {}
  int Vrednost() const ;
private:
  Zvezda operator = (const Zvezda& p);
};

class Podeljeno : public BinarniOperator {
public:
  Podeljeno(Izraz *prvi, Izraz *drugi)
    :BinarniOperator(prvi, drugi)
  {}
  int Vrednost() const ;
private:
  Podeljeno operator = (const Podeljeno& p);
};

class Stepen : public BinarniOperator {
public:
  Stepen(Izraz *prvi, Izraz *drugi)
    :BinarniOperator(prvi, drugi)
  {}
  int Vrednost() const ;
private:
  Stepen operator = (const Stepen& p);
};

class Vece : public BinarniOperator {
public:
  Vece(Izraz *prvi, Izraz *drugi)
    :BinarniOperator(prvi, drugi)
  {}
  int Vrednost() const ;
private:
  Vece operator = (const Vece& p);
};

class Manje : public BinarniOperator {
public:
  Manje(Izraz *prvi, Izraz *drugi)
    :BinarniOperator(prvi, drugi)
  {}
  int Vrednost() const ;
private:
  Manje operator = (const Manje& p);
};


#endif
