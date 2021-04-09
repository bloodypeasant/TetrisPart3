#include "Config.hpp"
#include "PieceL.hpp"

PieceL::PieceL()
    : Piece(Config::Piece::L::pivRow, Config::Piece::L::pivCol)
{
  blocks.emplace_back(new Block{
      Config::Piece::L::color,
      Math::Round(pivRow - 1.0),
      Math::Round(pivCol + 1.0)});
  blocks.emplace_back(new Block{
      Config::Piece::L::color,
      Math::Round(pivRow),
      Math::Round(pivCol - 1.0)});
  blocks.emplace_back(new Block{
      Config::Piece::L::color,
      Math::Round(pivRow),
      Math::Round(pivCol)});
  blocks.emplace_back(new Block{
      Config::Piece::L::color,
      Math::Round(pivRow),
      Math::Round(pivCol + 1.0)});
}
