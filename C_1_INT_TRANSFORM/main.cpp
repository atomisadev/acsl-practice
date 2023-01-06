#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

int transform(int n, int p)
{
  // Convert into string
  std::string s = std::to_string(n);

  // Find the Pth digit
  int pthDigit = s[s.length() - p] - '0';

  // Build the transformed number as a string
  std::string transformed;
  for (int i = 0; i < s.length(); i++)
  {
    int digit = s[i] - '0';
    if (i < s.length() - p)
    {
      transformed += (digit + pthDigit) % 10 + '0';
    }
    else if (i > s.length() - p)
    {
      transformed += abs(digit - pthDigit) + '0';
    }
    else
    {
      transformed += s[i];
    }
  }

  return std::atoi(transformed.c_str());
}

int main()
{
  // Open the input file
  std::ifstream file("input.txt");
  if (!file.is_open())
  {
    std::cout << "Failed to open input.txt" << std::endl;
    return 1;
  }

  // Read the input from the file and test the transform function
  std::string line;
  while (std::getline(file, line))
  {
    std::istringstream iss(line);
    int n, p;
    iss >> n >> p;
    std::cout << transform(n, p) << std::endl;
  }

  return 0;
}