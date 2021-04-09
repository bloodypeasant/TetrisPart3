#include <iostream>
#include "Config.hpp"
#include "Game.hpp"
#include "Math.hpp"
#include "Model.hpp"
#include "PieceI.hpp"
#include "PieceJ.hpp"
#include "PieceL.hpp"
#include "PieceO.hpp"
#include "PieceS.hpp"
#include "PieceT.hpp"
#include "PieceZ.hpp"

using std::cout;

Model::Model(Game *game)
    : game(game)
{
  cout << "Model::Model()\n";
  Random::Initialize();
}

Model::~Model()
{
  cout << "Model::~Model()\n";
}

bool Model::CanFallFast()
{
  return canFallFast;
}

bool Model::Collision()
{
  std::vector<Block *> *blocks = piece->GetBlocks();
  for (auto block : *blocks)
  {
    if (board[block->GetRow()][block->GetCol()])
    {
      return true;
    }
  }
  return false;
}

Block *Model::GetBlock(int row, int col)
{
  return board[row][col];
}

Piece *Model::GetPiece()
{
  return piece;
}

bool Model::IsBlockAt(int row, int col)
{
  return board[row][col] != nullptr;
}

void Model::Initialize()
{
  controller = game->GetController();
  view = game->GetView();
}

Piece *Model::MakeRandomPiece()
{
  Piece *piece;
  switch (Random::GetInt(0, 6))
  {
  case 0:
    piece = new PieceI();
    break;
  case 1:
    piece = new PieceJ();
    break;
  case 2:
    piece = new PieceL();
    break;
  case 3:
    piece = new PieceO();
    break;
  case 4:
    piece = new PieceS();
    break;
  case 5:
    piece = new PieceT();
    break;
  default:
    piece = new PieceZ();
    break;
  }
  return piece;
}

void Model::PlacePiece()
{
  std::vector<Block *> *blocks = piece->GetBlocks();
  canFallFast = !controller->IsFallingFast();
  for (auto block : *blocks)
  {
    board[block->GetRow()][block->GetCol()] = block;
  }
  piece = MakeRandomPiece();
  if (Collision())
  {
    game->StopRunning();
  }
}

void Model::PutBlockAt(Block *block, int row, int col)
{
  board[row][col] = block;
}

void Model::Restart()
{
  cout << "Model::Restart()\n";
  int maxX = boardDimX - 1;
  int maxY = boardDimY - 1;
  for (int row = 0; row < boardDimY; ++row)
  {
    for (int col = 0; col < boardDimX; ++col)
    {
      if (row == 0 || row == maxY || col == 0 || col == maxX)
      {
        board[row][col] = new Block{Color::gray, row, col};
      }
      else
      {
        board[row][col] = nullptr;
      }
    }
  }
  piece = MakeRandomPiece();
}

void Model::RotatePiece(int direction)
{
  piece->Rotate(direction);
  view->Rotate();
}

void Model::SetCanFallFast()
{
  canFallFast = true;
}

void Model::TranslatePiece(int dRow, int dCol)
{
  piece->Translate(dRow, dCol);
  if (Collision())
  {
    if (dRow)
    {
      piece->Translate(-dRow, -dCol);
      PlacePiece();
      view->HitHard();
    }
    else if (dCol)
    {
      piece->Translate(0, -dCol);
      view->HitSoft();
    }
  }
}
