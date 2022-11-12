#include "geesespotter_lib.h"

char *createBoard(std::size_t xdim, std::size_t ydim)
{
  char *create_array{new char[xdim * ydim]{0}};
  return create_array;
}

void cleanBoard(char *board)
{
  delete[] board;
  board = nullptr;
}

void printBoard(char *board, std::size_t xdim, std::size_t ydim)
{
  for (int y{0}; y < ydim; y++)
  {
    for (int x = y * xdim; x < ((y * xdim) + (xdim)); x++)
    {

      if ((board[x] & markedBit()) == markedBit())
      {
        std::cout << "M";
      }
      else if ((board[x] & hiddenBit()) == hiddenBit())
      {
        std::cout << "*";
      }
      else
      {
        std::cout << (int)(board[x] & valueMask());
      }
    }
    std::cout << std::endl;
  }
}

void hideBoard(char *board, std::size_t xdim, std::size_t ydim)
{
  for (int k{0}; k < (xdim * ydim); k++)
  {
    board[k] = board[k] | hiddenBit();
  }
}
int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc)
{
  int index = ((yloc * xdim) + (xloc));

  if ((board[index] & hiddenBit()) != hiddenBit())
  {
    return 2;
  }
  else
  {
    board[index] = board[index] ^ markedBit();
  }

  return 0;
}

void computeNeighbors(char *board, std::size_t xdim, std::size_t ydim)
{
  int index{0};
  int geese{0};
  char arr[ydim][xdim];

  for (int y{0}; y < ydim; y++)
  {
    for (int x{0}; x < xdim; x++)
    {
      arr[y][x] = board[index];
      index++;
    }
  }

  for (int y{0}; y < ydim; y++)
  {
    for (int x{0}; x < xdim; x++)
    {
      if ((arr[y][x] & valueMask()) != 9)
      {

        for (int i = -1; i <= 1; i++)
        {
          for (int j = -1; j <= 1; j++)
          {
            if (((i + y) >= 0) && ((j + x) >= 0) && ((i + y) < ydim) && ((j + x) < xdim))
            {
              if ((arr[(i + y)][(j + x)] & valueMask()) == 9)
              {
                geese++;
              }
            }
          }
        }

        arr[y][x] |= (char)geese;
        geese = 0;
      }
    }

    index = 0;
    for (int p{0}; p < ydim; p++)
    {
      for (int m{0}; m < xdim; m++)
      {
        board[index] = arr[p][m];
        index++;
      }
    }
  }
}

int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc)
{
  int count = ((yloc * xdim) + xloc);
  int index{0};
  char arr[ydim][xdim];

  if (board[count] & markedBit())
  {
    return 1;
  }
  if (!(board[count] & hiddenBit()))
  {
    return 2;
  }
  if ((board[count] & valueMask()) == 9)
  {
    board[count] ^= hiddenBit();
    return 9;
  }
  if ((board[count] & valueMask()) != 0)
  {
    board[count] ^= hiddenBit();
    return 0;
  }

  if ((board[count] & valueMask()) == 0)
  {
    for (int y{0}; y < ydim; y++)
    {
      for (int x{0}; x < xdim; x++)
      {
        arr[y][x] = board[index];
        index++;
      }
    }

    for (int i = -1; i <= 1; i++)
    {
      for (int j = -1; j <= 1; j++)
      {
        if (((i + yloc) >= 0) && ((j + xloc) >= 0) && ((i + yloc) < ydim) && ((j + xloc) < xdim))
        {
          arr[i][j] &= valueMask();
        }
      }
    }

    index = 0;
    for (int y{0}; y < ydim; y++)
    {
      for (int x{0}; x < xdim; x++)
      {
        board[index] = arr[y][x];
        index++;
      }
    }
  }

  return 0;
}

bool isGameWon(char *board, std::size_t xdim, std::size_t ydim)
{
    for (int i = 0; i<xdim * ydim; i++)
    {
      if (((board[i] & valueMask()) < 9) && (board[i] & hiddenBit())) {
        return false;
      }
    }
  return true;
}