#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to count the number of seniors based on details
int countSeniors(vector<string> &details)
{
  int seniorCount = 0;
  for (const string &info : details)
  {
    // Extract the tens and ones digit of the age from the string
    char tens = info[11];
    char ones = info[12];
    // Check if the age is greater than 60
    if (tens > '6' || (tens == '6' && ones > '0'))
    {
      seniorCount++;
    }
  }
  return seniorCount;
}

// Driver code
int main()
{
  vector<string> details = {
      "7868190130M7522", "5303914400F9211", "9273338290F4010"};

  int seniors = countSeniors(details);

  cout << "Number of seniors: " << seniors << endl;

  return 0;
}
