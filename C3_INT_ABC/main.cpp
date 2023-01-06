#include <iostream>
#include <unordered_map>
#include <vector>

const int NUM_ROWS = 4;
const int NUM_COLS = 4;
const int NUM_CELLS = NUM_ROWS * NUM_COLS;

struct Grid
{
  char cells[NUM_CELLS];
  std::unordered_map<int, char> first_found_letters;
};

// Reads a grid from the input stream
Grid read_grid()
{
  Grid grid;
  for (int i = 0; i < NUM_CELLS; i++)
  {
    grid.cells[i] += ' ';
  }

  // Read the filled cells
  for (int i = 0; i < NUM_CELLS; i++)
  {
    int cell;
    std::cin >> cell;
    char letter;
    std::cin >> letter;
    grid.cells[cell - 1] = letter;
  }

  // Read the first found letters
  int num_first_found_letters;
  std::cin >> num_first_found_letters;
  for (int i = 0; i < num_first_found_letters; i++)
  {
    int cell;
    char letter;
    std::cin >> letter >> cell;
    grid.first_found_letters[cell] = letter;
  }

  return grid;
}

// Returns the row and column for the given cell index
std::pair<int, int> get_row_coll(int cell)
{
  return {(cell - 1) / NUM_COLS, (cell - 1) % NUM_COLS};
}

// Returns the letter at the given row and column, or ' ' if the cell is empty
char get_letter(const Grid &grid, int row, int col)
{
  return grid.cells[row * NUM_COLS + col];
}

// Returns the first found letter at the given cell, or ' ' if there is none
char get_first_found_letter(const Grid &grid, int row, int col, int row_delta, int col_delta)
{
  int cell = (row + row_delta) * NUM_COLS + (col + col_delta);
  if (grid.first_found_letters.count(cell))
  {
    return grid.first_found_letters.at(cell);
  }
  return ' ';
}

// Unfinished code.