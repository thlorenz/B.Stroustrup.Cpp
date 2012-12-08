#include <math.h>
#include <iostream>
#include <assert.h>

using namespace std;

int atoi_(const char *s)
{
  // Assumes input is a string of a valid number (i.e. no extra characters contained)

  int base =  10;
  int sign =  1;
  int val  =  0;

  if (*s == '-') { sign = -1; s++; }

  if (*s == '0' && *(s + 1) == 'x') {
    base = 16; s += 2;
  }
  else if (*s == '0' && *(s + 1)) {
    base = 8; s++;
  }

  while (*s) {
    char c = toupper(*s++);
    val *= base;
    val += isalpha(c) ? (c - 'A' + 10) : (c - '0');
  }

  return val * sign;
}

void assert_atoi_(pair<const char*, int> pair)
{
  const char *s = pair.first;
  int expected = pair.second;
  int actual;

  actual = atoi_(s);
  cout << "atoi(" << s << ") == " << expected << " actual: " << actual;
  assert(actual == expected);
  cout << " OK." << endl;
}

void test_decimals()
{
  const pair<const char*, int> decimal_notation[] = {
    make_pair("", 0),
    make_pair("0", 0),
    make_pair("1", 1),
    make_pair("12", 12),
    make_pair("123", 123),
    make_pair("-123", (-123)),
  };
  int cases = (sizeof(decimal_notation) / sizeof(pair<const char*, int>));
  for_each(decimal_notation, decimal_notation + cases, assert_atoi_);
}

void test_octals()
{
  const pair<const char*, int> octal_notation[] = {
    make_pair("01", 1),
    make_pair("013", 11),
    make_pair("-013", -11)
  };
  int cases = (sizeof(octal_notation) / sizeof(pair<const char*, int>));
  for_each(octal_notation, octal_notation + cases, assert_atoi_);
}

void test_hexadecimals()
{
  const pair<const char*, int> octal_notation[] = {
    make_pair("0x0", 0),
    make_pair("0x1", 1),
    make_pair("0xA", 10),
    make_pair("-0xA", -10),
    make_pair("0xF", 15),
    make_pair("0xFF", 255),
    make_pair("-0xFF", -255)
  };
  int cases = (sizeof(octal_notation) / sizeof(pair<const char*, int>));
  for_each(octal_notation, octal_notation + cases, assert_atoi_);
}

int main(int argc, const char *argv[])
{
  test_decimals();
  test_octals();
  test_hexadecimals();
  cout << endl << "result: " << atoi_("0xF") << endl; return 0;
}
