int main(int argc, const char *argv[])
{

  // 01
  char a_char = 'c';
  char *pointer_to_char = &a_char;

  int array_of_ten_ints[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int &ref_to_array = array_of_ten_ints[10];

  char *char_string = "hello";
  char *array_of_char_strings[2] = { "hello", "world" };
  char *( *pointer_to_array_of_char_strings )[2] = &array_of_char_strings;

  char *( *pointer_to_pointer_to_char ) = &pointer_to_char;

  const int const_int = 0;
  const int *pointer_to_const_int = &const_int;

  int an_int = 0;
  int const *const_pointer_to_int = &an_int;

  return 0;
}
