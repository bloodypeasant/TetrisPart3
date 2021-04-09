#include <iostream>
#include "Game.hpp"
#include "Piece.hpp"

using std::cout;

Piece::Piece(double pivRow, double pivCol)
    : pivCol(pivCol), pivRow(pivRow)
{
}

void Piece::Draw() const
{
  for (auto block : blocks)
  {
    block->Draw();
  }
}

std::vector<Block *> *Piece::GetBlocks()
{
  return &blocks;
}

void Piece::Rotate(int direction)
{
  for (auto block : blocks)
  {
    block->Rotate(pivRow, pivCol, direction);
  }
}

void Piece::Translate(int dRow, int dCol)
{
  for (auto block : blocks)
  {
    block->Translate(dRow, dCol);
  }
  pivCol += dCol;
  pivRow += dRow;
}
