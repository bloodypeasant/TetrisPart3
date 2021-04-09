#include "Config.hpp"
#include "PieceO.hpp"

PieceO::PieceO()
    : Piece(Config::Piece::O::pivRow, Config::Piece::O::pivCol)
{
  blocks.emplace_back(new Block{
      Config::Piece::O::color,
      Math::Round(pivRow - 0.5),
      Math::Round(pivCol - 0.5)});
  blocks.emplace_back(new Block{
      Config::Piece::O::color,
      Math::Round(pivRow - 0.5),
      Math::Round(pivCol + 0.5)});
  blocks.emplace_back(new Block{
      Config::Piece::O::color,
      Math::Round(pivRow + 0.5),
      Math::Round(pivCol - 0.5)});
  blocks.emplace_back(new Block{
      Config::Piece::O::color,
      Math::Round(pivRow + 0.5),
      Math::Round(pivCol + 0.5)});
}
