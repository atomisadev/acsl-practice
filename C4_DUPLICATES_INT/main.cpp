#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int NUM_LETTERS = 26;

struct State
{
  char letters[NUM_LETTERS];
  int counts[NUM_LETTERS];
};

// Initializes the state
void init_state(State &state)
{
  for (int i = 0; i < NUM_LETTERS; i++)
  {
    state.letters[i] = ' ';
    state.counts[i] = 0;
  }
}

// Returns the index of the given letter
int get_letter_index(char letter)
{
  return letter - 'A';
}

// Returns the letter at the given index
char get_letter(int index)
{
  return 'A' + index;
}

// Adds the given letter to the given state
void add_letter(State &state, char letter)
{
  int index = get_letter_index(letter);
  if (state.letters[index] == ' ')
  {
    state.letters[index] = letter;
  }
  state.counts[index]++;
}

// Removes the given letter from the given state
void remove_letter(State &state, char letter)
{
  int index = get_letter_index(letter);
  state.counts[index]--;
  if (state.counts[index] == 0)
  {
    state.letters[index] = ' ';
  }
}

// Returns the letter at the given position in the given state
char get_letter_at_position(const State &state, int position)
{
  for (int i = 0; i < NUM_LETTERS; i++)
  {
    if (state.counts[i] > position)
    {
      return state.letters[i];
    }
    position -= state.counts[i];
  }
  return ' ';
}

int main()
{
  State current_state;
  vector<State> states;

  string line;
  while (getline(cin, line))
  {
    if (line[0] == 'R')
    {
      init_state(current_state);
      states.clear();
      states.push_back(current_state);
      string letters = line.substr(7);
      for (char c : letters)
      {
        if (isalpha(c))
        {
          c = toupper(c);
          add_letter(current_state, c);
          states.push_back(current_state);
        }
      }
    }
    else if (line[0] == 'A')
    {
      string letters = line.substr(4);
      for (char c : letters)
      {
        if (isalpha(c))
        {
          c = toupper(c);
          add_letter(current_state, c);
          states.push_back(current_state);
        }
      }
    }
    else if (line[0] == 'D')
    {
      string letters = line.substr(7);
      for (char c : letters)
      {
        if (isalpha(c))
        {
          c = toupper(c);
          remove_letter(current_state, c);
          states.push_back(current_state);
        }
      }
    }
    else if (line[0] == 'R')
    {
      int position = stoi(line.substr(7));
      string history;
      for (const State &state : states)
      {
        char letter = get_letter_at_position(state, position);
        if (letter != ' ')
        {
          history += letter;
        }
      }
      cout << history << endl;
    }
  }

  return 0;
}