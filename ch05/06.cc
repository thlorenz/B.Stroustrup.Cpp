void f(char c)
{ }

void g(char& cp)
{ }

void h(const char& ccp)
{ }

int main(int argc, const char *argv[])
{
  char a = 'a';
  unsigned char uc = 'u';
  signed char sc = 's';

  //
  // f() pass by value --  always needs temp variable
  //

  f('a');
  f(49);
  // f(3300); -- overflow in implicit constant conversion (warning)

  f(a);
  f(uc);
  f(sc);

  //
  // g()
  //

  // g('a'); g(49); g(3300); -- invalid initializion of non-const reference from a temorary

  g(a);
  // g(uc); g(sc); -- invalid initialization of reference of type char& from expression of unsigned/signed char

  h('a'); h(49); h(3300); // temp var created and passed as reference

  h(a);
  h(uc); h(sc); // temp var created if converted implicitly and passed as reference

  return 0;
}
