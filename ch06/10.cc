#include <iostream>
#include <string.h>
#include <assert.h>
#include <algorithm>

using namespace std;

int strlen_(const char *s)
{
  int i;
  for (i = 0; s[i] != '\0'; i++);
  return i;
}


int strcmp_(const char *s1, const char *s2)
{
  for (int i = 0; ;i++) {
    char c1 = s1[i];
    char c2 = s2[i];

    if (c1 == '\0' && c2 == '\0') return 0;
    if (c1 == c2) continue;
    return (c1 < c2) ? -1 : 1;
  }
}

void assert_like_std_strlen(const char* s)
{
  cout << "asserting: strlen(" << s << ")";
  assert(strlen_(s) == strlen(s));
  cout << " OK." << endl;
}

void test_strlen()
{
  const char* strings[] = { "", "1", "1234", "123 5" };

  int len = (sizeof(strings) / sizeof(char*));
  for_each(strings, strings + len, assert_like_std_strlen);
}

void test_strcmp()
{
  assert(strcmp_(""    ,  "") == 0);
  assert(strcmp_("aa"  ,  "aa") == 0);
  assert(strcmp_("aaa" ,  "aa") == 1);
  assert(strcmp_("aaa" ,  "ab") == -1);
  assert(strcmp_("aa"  ,  "aaa") == -1);
}


int main(int argc, const char *argv[])
{
  test_strlen();
  test_strcmp();

  return 0;
}
