#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

void findCommonSubstring(string A, string B, bool reverseA, bool reverseB)
{
  if (reverseA)
    reverse(A.begin(), A.end());
  if (reverseB)
    reverse(B.begin(), B.end());

  string commonAB, commonBA;
  for (char c : A)
  {
    auto pos = B.find(c);
    if (pos != string::npos)
    {
      commonAB += c;
      B.erase(0, pos + 1);
    }
  }

  for (char c : B)
  {
    auto pos = A.find(c);
    if (pos != string::npos)
    {
      commonBA += c;
      A.erase(0, pos + 1);
    }
  }

  if (reverseA)
    reverse(commonBA.begin(), commonBA.end());
  if (reverseB)
    reverse(commonAB.begin(), commonAB.end());

  string commonABrev = commonAB, commonBArev = commonBA;
  reverse(commonABrev.begin(), commonABrev.end());
  reverse(commonBArev.begin(), commonBArev.end());

  set<char> commonLetters;
  for (char c : commonAB)
    commonLetters.insert(c);
  for (char c : commonBA)
    commonLetters.insert(c);
  for (char c : commonABrev)
    commonLetters.insert(c);
  for (char c : commonBArev)
    commonLetters.insert(c);

  if (commonLetters.empty())
  {
    cout << "NONE" << endl;
  }
  else
  {
    for (char c : commonLetters)
    {
      cout << c;
    }
    cout << endl;
  }
}

int main()
{
  for (int i = 0; i < 5; i++)
  {
    string A, B;
    cin >> A >> B;
    findCommonSubstring(A, B, true, false);
    findCommonSubstring(A, B, true, true);
    findCommonSubstring(A, B, false, false);
    findCommonSubstring(A, B, false, true);
  }
  return 0;
}