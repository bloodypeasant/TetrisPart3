#include <iostream>
#include "Block.hpp"
#include "Math.hpp"

using std::cout;

SDL_Renderer *Block::renderer = nullptr; // to be set externally
int Block::size = 10;                    // to be set externally

Block::Block(Color const &color, int row, int col)
    : color(color), col(col), row(row)
{
}

void Block::Draw()
{
  SDL_Rect rect{col * size + 1, row * size + 1, size - 2, size - 2};
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
  SDL_RenderFillRect(renderer, &rect);
}

int Block::GetCol()
{
  return col;
}

int Block::GetRow()
{
  return row;
}

void Block::Rotate(double pivRow, double pivCol, int direction)
{
  int newCol = Math::Round(pivCol + direction * (pivRow - row));
  row = Math::Round(pivRow + direction * (col - pivCol));
  col = newCol;
}

void Block::Translate(int dRow, int dCol)
{
  row += dRow;
  col += dCol;
}

void Block::SetRenderer(SDL_Renderer *renderer)
{
  Block::renderer = renderer;
}

void Block::SetSize(int size)
{
  Block::size = size;
}
