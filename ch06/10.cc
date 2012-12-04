#include <iostream>
#include <string.h>
#include <assert.h>
#include <algorithm>

using namespace std;

int strlen_(const char *s)
{
  int i;
  for (i = 0; s[i]; i++);
  return i;
}

void assert_strlen(const char* s)
{
  cout << "asserting: strlen(" << s << ")";
  assert(strlen_(s) == strlen(s));
  cout << " OK." << endl;
}

char* strcpy_std(char *to, const char *from)
{
  // don't understand this assignment
  char *s = to;
  for (s = to; (*s++ = *from++) != '\0';)
  return to;
}

char* strcpy_(char *to, const char *from)
{
  for (; *to = *from, *from; *to++, *from++);
  return to;
}

void assert_strcpy(const char* s)
{
  cout << "asserting: strcpy(" << s << ")";
  char to[50];
  strcpy_(to, s);

  assert(strcmp(to, s) == 0);
  cout << " OK." << endl;
}

int strcmp_(const char *s1, const char *s2)
{
  for (int i = 0; ;i++) {
    char c1 = s1[i];
    char c2 = s2[i];

    if (!c1 && !c2) return 0;
    if (c1 == c2) continue;
    return c1 - c2;
  }
}

void assert_strcmp(const pair<const char*, const char*> p)
{
  cout << "asserting: strcmp(" << p.first << ", " << p.second << ")";
  assert(strcmp_(p.first, p.second) == strcmp(p.first, p.second));
  cout << " OK." << endl;
}


void test_strlen()
{
  const char* strings[] = { "", "1", "1234", "123 5" };

  int len = (sizeof(strings) / sizeof(char*));
  for_each(strings, strings + len, assert_strlen);
}

void test_strcmp()
{
  const pair<const char*, const char*> pairs[] = {
    make_pair("", ""),
    make_pair("\n", ""),
    make_pair("a\n", ""),
    make_pair("aa", "aa"),
    make_pair("aaa", "aa"),
    make_pair("aaa", "ab"),
    make_pair("aa", "aaa")
  };

  int len = (sizeof(pairs) / sizeof(pair<const char*, const char*>));
  for_each(pairs, pairs + len, assert_strcmp);
}

void test_strcpy()
{
  const char* strings[] = { "", "1", "1234", "123 5", "a\nb" };

  int len = (sizeof(strings) / sizeof(char*));
  for_each(strings, strings + len, assert_strcpy);
}


int main(int argc, const char *argv[])
{
  test_strlen();
  test_strcpy();
  test_strcmp();

  return 0;
}
