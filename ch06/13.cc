#include <iostream>
#include <string.h>

using namespace std;

const char* cat_(const char *s1, const char *s2)
{
  int len = strlen(s1) + strlen(s2) + 1;
  char *res = new char(len);
  char *s = res;

  while (*s1) *s++ = *s1++;
  while (*s2) *s++ = *s2++;
  s = 0;

  return res;
}

int main(int argc, const char *argv[])
{
  const char *res = cat_("hello world", " my friend");
  cout << "result: " << res << endl;
  delete res;
  return 0;
}
