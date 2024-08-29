#include <iostream>
#include <string>

std::string processString(const std::string &input)
{
  std::string result;

  for (char ch : input)
  {
    if (ch == ' ')
    {
      result += '_';
    }
    else if (ch != '.')
    {
      result += ch;
    }
  }

  result += ".cpp";
  return result;
}

int main()
{
  std::string input;

  std::cout << "Enter the string: ";
  std::getline(std::cin, input);

  std::string output = processString(input);

  std::cout << "Processed string: " << output << std::endl;

  return 0;
}
