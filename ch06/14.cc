#include <iostream>
#include <string.h>

using namespace std;

const char* rev_returning(const char *src)
{
  int len = strlen(src) - 1;

  const char *cur = src + len;

  char *tgt = new char(len);
  char *t = tgt;

  while(cur >= src) *t++ = *cur--;
  t = 0;

  return tgt;
}

void rev_inplace_with_tmp_ptr(char *s)
{
  // not properly working
  char *p = s;

  while(*p) p++;

  char *t = s;
  while(--p > s)
  {
      //cout << " p: " << p;
      *t = *s;
      *s++ = *p;
      *p = *t;
  }
}
void rev_inplace_with_tmp(char *s)
{
  char *p = s;

  while(*p) p++;

  char t;
  while(--p > s)
  {
      //cout << " p: " << p;
      t = *s;
      *s++ = *p;
      *p = t;
  }
}

void rev_inplace(char *s)
{
  char *p = s;
  while(*p) p++;
  while(--p > s)
  {
      *p ^= *s;
      *s ^= *p;
      *p ^= *s++;
  }
}

int main(int argc, char *argv[])
{
  if(argc < 2) {
    cerr << "Not enough arguments!";
    return -1;
  }

  const char *res = rev_returning(argv[1]);
  cout << "result: " << res << endl;
  delete res;

  rev_inplace_with_tmp(argv[1]);
  cout << "result: " << argv[1] << endl;

  return 0;
}
