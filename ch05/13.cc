#include <iostream>
#include <string>

using namespace std;

struct Date {
  int day;
  int month;
  int year;
};

Date read_date()
{
  Date date = {};
  cout << "Please enter a date: " << endl;
  cout << "day: "; cin >> date.day;
  cout << "month: "; cin >> date.month;
  cout << "year: "; cin >> date.year;
  return date;
}

void print_date(const Date date)
{
  cout << "You entered this date: " << date.month << "/" << date.day << "/" << date.year << endl;
}

int main(int argc, const char *argv[])
{
  Date date = read_date();
  print_date(date);
  return 0;
}
