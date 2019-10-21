#pragma once
#include <string>
using namespace std;

struct Ast {
  virtual void postfix(string*) {}
  virtual int eval() { return 0; }
};

struct Int : Ast {
  int v;
  Int(int _v) { v = _v; }
  void postfix(string *s) { char b[32]; sprintf(b, "%d", v); s->append(b); }
  int eval() { return v; }
};
struct Add : Ast {
  Ast *x, *y;
  Add(Ast *_x, Ast *_y) { x = _x; y = _y; }
  void postfix(string *s) { s->append("(+ "); x->postfix(s); s->append(" "); y->postfix(s); s->append(")"); }
  int eval() { return x->eval() + y->eval(); }
};
struct Sub : Ast {
  Ast *x, *y;
  Sub(Ast *_x, Ast *_y) { x = _x; y = _y; }
  void postfix(string *s) { s->append("(- "); x->postfix(s); s->append(" "); y->postfix(s); s->append(")"); }
  int eval() { return x->eval() - y->eval(); }
};
struct Mul : Ast {
  Ast *x, *y;
  Mul(Ast *_x, Ast *_y) { x = _x; y = _y; }
  void postfix(string *s) { s->append("(* "); x->postfix(s); s->append(" "); y->postfix(s); s->append(")"); }
  int eval() { return x->eval() * y->eval(); }
};
struct Div : Ast {
  Ast *x, *y;
  Div(Ast *_x, Ast *_y) { x = _x; y = _y; }
  void postfix(string *s) { s->append("(/ "); x->postfix(s); s->append(" "); y->postfix(s); s->append(")"); }
  int eval() { return x->eval() / y->eval(); }
};
