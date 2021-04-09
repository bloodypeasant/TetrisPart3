#include "Config.hpp"
#include "PieceZ.hpp"

PieceZ::PieceZ()
    : Piece(Config::Piece::Z::pivRow, Config::Piece::Z::pivCol)
{
  blocks.emplace_back(new Block{
      Config::Piece::Z::color,
      Math::Round(pivRow - 1.0),
      Math::Round(pivCol - 1.0)});
  blocks.emplace_back(new Block{
      Config::Piece::Z::color,
      Math::Round(pivRow - 1.0),
      Math::Round(pivCol)});
  blocks.emplace_back(new Block{
      Config::Piece::Z::color,
      Math::Round(pivRow),
      Math::Round(pivCol)});
  blocks.emplace_back(new Block{
      Config::Piece::Z::color,
      Math::Round(pivRow),
      Math::Round(pivCol + 1.0)});
}
