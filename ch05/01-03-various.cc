int main(int argc, const char *argv[])
{

  // 01
  char character = 'a';
  char* pointer_to_character = &character;

  int array_of_ten_ints[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int& ref_to_array = array_of_ten_ints[10];



  return 0;
}
