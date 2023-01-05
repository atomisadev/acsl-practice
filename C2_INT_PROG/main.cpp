#include <iostream>
#include <string>
#include <fstream>

std::string common_substrings(std::string str1, std::string str2) {
  std::string result_str = "";
  for (int i = 0; i < str1.length(); i++) {
    if (str2.find(str1[i]) != std::string::npos) {
      result_str += str1[i];
      str2 = str2.substr(str2.find(str1[i]) + 1);
    }
  }

  return result_str;
}

int main() {
  std::ifstream file("input.txt");
  std::string line;
  while (std::getline(file, line)) {
    std::size_t pos = line.find(" ");
    std::string str1 = line.substr(0, pos);
    std::string str2 = line.substr(pos + 1);
    std::cout << common_substrings(str1, str2) << std::endl;
  }
  return 0;
}