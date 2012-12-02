#include <iostream>
#include <string>

using namespace std;

int count(const string s, const char pair[])
{
  char fst = *pair;
  char snd = *++pair;

  int len = s.size();
  int pair_count = 0;

  for (int i = 0; i < len; i++)
    pair_count += (fst == s[i]) && (snd == s[i + 1]);

  return pair_count;
}

int main(int argc, const char *argv[])
{
  const char* pair = "lo";
  string s = "hello worlodd";

  int pair_count = count(s, pair);

  cout << "Found: " << pair << " " << pair_count << " times in \"" << s << "\"" << endl;

  return 0;
}
