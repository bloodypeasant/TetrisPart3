#include "Config.hpp"
#include "PieceI.hpp"

PieceI::PieceI()
    : Piece(Config::Piece::I::pivRow, Config::Piece::I::pivCol)
{
  blocks.emplace_back(new Block{
      Config::Piece::I::color,
      Math::Round(pivRow - 0.5),
      Math::Round(pivCol - 1.5)});
  blocks.emplace_back(new Block{
      Config::Piece::I::color,
      Math::Round(pivRow - 0.5),
      Math::Round(pivCol - 0.5)});
  blocks.emplace_back(new Block{
      Config::Piece::I::color,
      Math::Round(pivRow - 0.5),
      Math::Round(pivCol + 0.5)});
  blocks.emplace_back(new Block{
      Config::Piece::I::color,
      Math::Round(pivRow - 0.5),
      Math::Round(pivCol + 1.5)});
}
