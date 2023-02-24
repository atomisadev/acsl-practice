#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

struct Node
{
  char key;
  int count;
  Node *left, *right;
  Node(char c) : key(c), count(1), left(nullptr), right(nullptr) {}
};

void insert(Node *&root, char key)
{
  if (!root)
  {
    root = new Node(key);
  }
  else if (key == root->key)
  {
    root->count++;
  }
  else if (key < root->key)
  {
    insert(root->left, key);
  }
  else
  {
    insert(root->right, key);
  }
}

int countSingleChildNodes(Node *root)
{
  if (!root)
  {
    return 0;
  }

  int count = 0;
  if ((root->left && !root->right) || (root->right && !root->left))
  {
    count = root->count;
  }

  return count + countSingleChildNodes(root->left) + countSingleChildNodes(root->right);
}

int main()
{
  unordered_map<char, int> counter;
  string input;
  for (int i = 0; i < 5; i++)
  {
    getline(cin, input);
    Node *root = nullptr;
    for (char c : input)
    {
      if (isalpha(c))
      {
        insert(root, toupper(c));
      }
    }
    counter.clear();
    int count = countSingleChildNodes(root);
    cout << count << endl;
    delete root;
  }
  return 0;
}