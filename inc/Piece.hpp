#pragma once
#include <vector>
#include "Block.hpp"
#include "Math.hpp"
#include "SDL.h"

class Piece
{
public:
  /**
   * Construct a piece at specified pivot row and column.
   * @param pivRow piece's pivot row
   * @param pivCol piece's pivot column
   */
  Piece(double pivRow, double pivCol);

  /**
   * Draw piece.
   */
  void Draw() const;

  /**
   * Get pointer to blocks.
   * @return pointer to blocks.
   */
  std::vector<Block *> *GetBlocks();

  /**
   * Rotate piece in specified direction about pivot point.
   * @param direction +1 for clockwise; -1 for counterclockwise
   */
  void Rotate(int direction);

  /**
   * Translate piece by specified number of rows and columns.
   * @param dRow vertical translation
   * @param dCol horizontal translation
   */
  void Translate(int dRow, int dCol);

protected:
  std::vector<Block *> blocks; // all blocks composing the piece
  double pivCol = 0;           // piece's pivot column
  double pivRow = 0;           // piece's pivot row
};
