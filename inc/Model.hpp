#pragma once
#include "Block.hpp"
#include "Config.hpp"
#include "Piece.hpp"

class Model
{
public:
  /**
   * Constructs model.
   */
  Model(class Game *game);

  /**
   * Destructs model.
   */
  ~Model();

  bool CanFallFast();

  /**
   * Gets pointer to block at specified position.
   * @param row vertical position
   * @param col horizontal position
   * @returns pointer to block
   */
  Block *GetBlock(int row, int col);

  /**
   * Gets pointer to piece being dropped.
   * @return pointer to piece
   */
  Piece *GetPiece();

  void Initialize();

  /**
   * Restarts model.
   */
  void Restart();

  /**
   * Rotate piece in specified direction about pivot point.
   * @param direction +1 for clockwise; -1 for counterclockwise
   */
  void RotatePiece(int direction);

  void SetCanFallFast();

  /**
   * Translate piece by specified number of rows and columns.
   * @param dRow vertical translation
   * @param dCol horizontal translation
   */
  void TranslatePiece(int dRow, int dCol);

private:
  /**
   * Determines if piece is colliding with any blocks.
   * @return whether collision
   */
  bool Collision();

  /**
   * Determines if block is at specified position on board.
   * @param row vertical position
   * @param col horizontal position
   * @returns whether present
   */
  bool IsBlockAt(int row, int col);

  /**
   * Makes a random piece.
   * @return pointer to newly created piece
   */
  Piece *MakeRandomPiece();

  /**
   * Places piece in board.
   */
  void PlacePiece();

  /**
   * Places block on board at specified position.
   * @param block pointer to block being placed
   * @param row vertical position
   * @param col horizontal position
   */
  void PutBlockAt(Block *block, int row, int col);

  class Game *game; // pointer to the game
  class Controller *controller;
  class View *view; // pointer to the view;

  Block *board[Config::Model::boardDimY]
              [Config::Model::boardDimX];   // board
  int boardDimX = Config::Model::boardDimX; // board's width
  int boardDimY = Config::Model::boardDimY; // board's height
  bool canFallFast = true;
  Piece *piece = nullptr; // piece that is falling
};
