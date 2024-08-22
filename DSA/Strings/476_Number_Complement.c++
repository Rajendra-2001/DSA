#include <iostream>
#include <bitset>
#include <string>
using namespace std;
int main()
{
  int num;
  cout << "Enter the positive decimal number: ";
  cin >> num;                  // Example number
  std::bitset<32> binary(num); // 32 bits for standard int size

  // Convert bitset to string and trim leading zeros
  std::string binaryStr = binary.to_string();
  binaryStr = binaryStr.substr(binaryStr.find('1'));

  std::string t = binaryStr;
  int s = t.size();

  // Flip the bits in the string
  for (int i = 0; i < s; i++)
  {
    if (t[i] == '0')
      t[i] = '1';
    else
      t[i] = '0';
  }

  // Convert flipped binary string back to decimal
  std::bitset<32> flippedBinary(t);
  long long int ans = flippedBinary.to_ulong();

  std::cout << "Original binary: " << binaryStr << std::endl;
  std::cout << "Flipped binary: " << t << std::endl;
  std::cout << "1's complement of " << num << " is " << ans << std::endl;

  return 0;
}
