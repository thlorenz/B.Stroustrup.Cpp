#include <iostream>

void swap_pointer(int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void swap_ref(int& a, int& b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

int main(int argc, const char *argv[])
{
  int a = 1;
  int b = 2;

  std::cout << "Before swap: a=" << a << " b=" << b << "\n";
  swap_pointer(&a, &b);
  std::cout << "After swap: a=" << a << " b=" << b << "\n";

  swap_ref(a, b);
  std::cout << "After second swap: a=" << a << " b=" << b << "\n";

  return 0;
}

