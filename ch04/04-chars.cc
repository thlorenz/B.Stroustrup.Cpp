#include <iostream>

int main(int argc, const char *argv[]) {
  char i;
  for (i = 'a'; i <= 'z'; i++) {
    std::cout << i << " " << int(i) << " --- ";
  }
  for (i = '0'; i <= '9'; i++) {
    std::cout << i << " " << int(i) << " --- ";
  }

  return 0;
}
