#include <iostream>
#include <vector>

using namespace std;
bool lemonadeChange(vector<int> &bill)
{
  int fiveCount = 0, tenCount = 0; // Track the number of $5 and $10 bills

  if (bill[0] != 5)
    return false; // First customer must pay with $5

  for (int i = 0; i < bill.size(); i++)
  {
    if (bill[i] == 5)
    {
      fiveCount++; // Received a $5 bill, no change needed
    }
    else if (bill[i] == 10)
    {
      if (fiveCount > 0)
      {
        fiveCount--; // Give one $5 as change
        tenCount++;
      }
      else
      {
        return false; // No $5 bill to give as change
      }
    }
    else
    { // bill[i] == 20
      if (tenCount > 0 && fiveCount > 0)
      {
        tenCount--; // Give one $10 and one $5 as change
        fiveCount--;
      }
      else if (fiveCount >= 3)
      {
        fiveCount -= 3; // Give three $5 bills as change
      }
      else
      {
        return false; // Not enough change available
      }
    }
  }

  return true;
}
int main()
{
  vector<int> bills1 = {5, 5, 5, 10, 20};
  vector<int> bills2 = {5, 5, 10, 10, 20};
  vector<int> bills3 = {10, 10};   // This should return false because no initial $5 bill
  vector<int> bills4 = {5, 5, 10}; // This should return true

  // Test case 1
  if (lemonadeChange(bills1))
  {
    cout << "Test case 1: Change can be given to all customers." << endl;
  }
  else
  {
    cout << "Test case 1: Change cannot be given to all customers." << endl;
  }

  // Test case 2
  if (lemonadeChange(bills2))
  {
    cout << "Test case 2: Change can be given to all customers." << endl;
  }
  else
  {
    cout << "Test case 2: Change cannot be given to all customers." << endl;
  }

  // Test case 3
  if (lemonadeChange(bills3))
  {
    cout << "Test case 3: Change can be given to all customers." << endl;
  }
  else
  {
    cout << "Test case 3: Change cannot be given to all customers." << endl;
  }

  // Test case 4
  if (lemonadeChange(bills4))
  {
    cout << "Test case 4: Change can be given to all customers." << endl;
  }
  else
  {
    cout << "Test case 4: Change cannot be given to all customers." << endl;
  }

  return 0;
}