#pragma once
#include "Color.hpp"
#include "SDL.h"

class Block
{
public:
  /**
   * Set renderer simultaneously for all blocks.
   */
  static void SetRenderer(SDL_Renderer *renderer);

  /**
   * Set pixel size simultaneously for all blocks.
   * @param size length and width of block in pixels
   */
  static void SetSize(int size);

  /**
   * Construct a block.
   * @param color reference to block's color
   * @param row vertical position
   * @param col horizontal position
   */
  Block(Color const &color, int row, int col);

  /**
   * Draw block.
   */
  void Draw();

  /**
   * Gets block's column.
   * @return column
   */
  int GetCol();

  /**
   * Gets block's row.
   * @return row
   */
  int GetRow();

  /**
   * Rotate block in specified direction around pivot point.
   * @param pivRow pivot point's vertical component
   * @param pivCOl pivot point's horizontal component
   * @param direction +1 for clockwise; -1 for counterclockwise
   */
  void Rotate(double pivRow, double pivCol, int direction);

  /**
   * Translate block by specified number of rows and columns.
   * @param dRow number of rows to translate vertically
   * @param dCol number of columns to translate horizontally
   */
  void Translate(int dRow, int dCol);

  static SDL_Renderer *renderer; // renderer for drawing
  static int size;               // length and width of block in pixels

private:
  Color const &color; // reference to block's color
  int col;            // horizontal position
  int row;            // vertical position
};
