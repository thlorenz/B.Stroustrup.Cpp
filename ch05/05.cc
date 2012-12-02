#include <iostream>
#include <string>

int main(int argc, const char *argv[])
{
  char str[] = "a short string";
  std::cout << "char[] len: " << (sizeof(str)) << "\n";

  std::string str_s = "a short string";
  std::cout << "string len: " << (sizeof(str_s));

  return 0;
}
