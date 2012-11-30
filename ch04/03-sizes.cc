#include <iostream>

int main(int argc, const char *argv[])
{
  std::cout << "char: "   << (sizeof(char))   << " char* "    << (sizeof(char*))   << " char** " << (sizeof(char**)) << "\n";
  std::cout << "float: "  << (sizeof(float))  << " double: "  << (sizeof(double))  << "\n";
  std::cout << "float*: " << (sizeof(float*)) << " double*: " << (sizeof(double*)) << "\n";
  std::cout << "int: "    << (sizeof(int))    << " long: "    << (sizeof(long));

  return 0;
}
