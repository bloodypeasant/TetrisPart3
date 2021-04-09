#include "Config.hpp"
#include "PieceS.hpp"

PieceS::PieceS()
    : Piece(Config::Piece::S::pivRow, Config::Piece::S::pivCol)
{
  blocks.emplace_back(new Block{
      Config::Piece::S::color,
      Math::Round(pivRow - 1.0),
      Math::Round(pivCol)});
  blocks.emplace_back(new Block{
      Config::Piece::S::color,
      Math::Round(pivRow - 1.0),
      Math::Round(pivCol + 1.0)});
  blocks.emplace_back(new Block{
      Config::Piece::S::color,
      Math::Round(pivRow),
      Math::Round(pivCol - 1.0)});
  blocks.emplace_back(new Block{
      Config::Piece::S::color,
      Math::Round(pivRow),
      Math::Round(pivCol)});
}
