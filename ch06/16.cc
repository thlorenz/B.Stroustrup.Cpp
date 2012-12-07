#include <math.h>
#include <iostream>
#include <assert.h>

using namespace std;

int atoi_(const char *s)
{
  int len = strlen(s);
  int mul = pow(10, len);
  int sign = 1;
  int val = 0;

  if (*s == '-') { sign = -1; mul /= 10; *s++; }
  while (*s) val += (*s++ - '0') * (mul /= 10);

  return val * sign;
}

void assert_atoi_(pair<const char*, int> pair)
{
  const char *s = pair.first;
  int expected = pair.second;
  int actual;

  cout << "atoi(" << s << ") == " << expected << " actual: " << actual;
  actual = atoi_(s);
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

int main(int argc, const char *argv[])
{
  test_decimals();
  return 0;
}
