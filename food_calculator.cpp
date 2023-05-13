#include <cctype>
#include <iostream>
using namespace std;
int main() {
  // Declare variables
  int rsvp;
  int expected_guests;
  int organizers;
  int dietary;
  int large;
  int medium;
  int base;
  int hw_large;
  int hw_medium;
  int veg_large;
  int veg_medium;
  char beverage;
  float show_up_ratio;
  float ratio;

  cout << "----------\n"
       << "Hello! Welcome to the ieee food calculator.\n"
       << "I'll help you calculate how much food you should order for an "
          "event!\n"
       << "----------\n";
  cout << endl;
  // Find out how many people

  cout << "First, we will find out how many people should show up.\n"
       << "1. How many people have RSVP'd?\n";
  cin >> rsvp;
  cout << "2. What's the ratio of people that usually show up?\n";
  cin >> show_up_ratio;
  cout << "3. How many people are helping organize this event?\n";
  cin >> organizers;
  cout << endl;
  expected_guests = (int)(rsvp * show_up_ratio) + 1;
  if (organizers >= expected_guests) {
    expected_guests = organizers;
  } else {
    expected_guests = (int)(rsvp * show_up_ratio) + 1;
  }
  cout << "Got it! From this info, we expect " << expected_guests
       << " people to attend.\n";
  cout << endl;
  // Check dietary restriction
  cout << "4. How many people requested vegetarian options?\n";
  cin >> dietary;

  // Check beverage options
  cout << "5. What type of beverage will be available? ([W]ater, [S]oda, "
          "[N]one)\n";
  cin >> beverage;
  base = (int)(expected_guests / 7);
  if (beverage == 'w' || beverage == 'W') {
    cout << endl;
    large = (int)(expected_guests / 7) * 0.9;
    medium = (int)(expected_guests - base * 7) * 0.9;
  } else if (beverage == 's' || beverage == 'S') {
    cout << endl;
    large = (int)(expected_guests / 7) * 0.75;
    medium = (int)(expected_guests - base * 7) * 0.75;
  } else {
    cout << endl;
    large = (int)(expected_guests / 7);
    medium = (int)(expected_guests - base * 7);
  }

  cout << "I think you should order " << large << " large and " << medium
       << " medium pizzas.\n";
  ratio = (float)dietary / expected_guests;
  if (ratio <= 0.2) {
    hw_large = large * 0.8;
    hw_medium = medium * 0.8;
    veg_large = large - hw_large;
    veg_medium = medium - hw_medium;
  } else {
    hw_large = (int)(large * (1 - ratio));
    hw_medium = (int)(medium * (1 - ratio));
    veg_large = large - hw_large;
    veg_medium = medium - hw_medium;
  }
  cout << "From the options you entered, I think you should order:\n"
       << "    " << hw_large << " large Hawaiian pizzas\n"
       << "    " << hw_medium << " medium Hawaiian pizzas\n"
       << "    " << veg_large << " large vegetarian pizzas\n"
       << "    " << veg_medium << " medium vegetarian pizzas\n";
  cout << endl;
  cout << endl;
  cout << "Hope this helps!\n";
  return 0;
}
