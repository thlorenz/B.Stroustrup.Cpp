#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

int for_loop(string input_line)
{
  int max_length = input_line.size();
  int quest_count = 0;

  for (int i = 0; i < max_length; i++)
    quest_count += (input_line[i] == '?');

  return quest_count;
}

int while_loop(string input_line)
{
  int max_length = input_line.size();
  int quest_count = 0;
  int i = 0;

  while(i < max_length)
    quest_count += (input_line[i++] == '?');

  return quest_count;
}

void tests() {
  assert(for_loop("")         == 0 && while_loop("")          == 0);
  assert(for_loop("hello")    == 0 && while_loop("hello")     == 0);
  assert(for_loop("?hello")   == 1 && while_loop("?hello")    == 1);
  assert(for_loop("?hello?")  == 2 && while_loop("?hello?")   == 2);
  assert(for_loop("?hel?lo?") == 3 && while_loop("?hel?lo?")  == 3);
}

int main(int argc, const char *argv[])
{
  cout << "running tests ... ";
  tests();
  cout << "all passed";

  return 0;
}
