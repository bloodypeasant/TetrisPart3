#include "Config.hpp"
#include "PieceT.hpp"

PieceT::PieceT()
    : Piece(Config::Piece::T::pivRow, Config::Piece::T::pivCol)
{
  blocks.emplace_back(new Block{
      Config::Piece::T::color,
      Math::Round(pivRow - 1.0),
      Math::Round(pivCol)});
  blocks.emplace_back(new Block{
      Config::Piece::T::color,
      Math::Round(pivRow),
      Math::Round(pivCol - 1.0)});
  blocks.emplace_back(new Block{
      Config::Piece::T::color,
      Math::Round(pivRow),
      Math::Round(pivCol)});
  blocks.emplace_back(new Block{
      Config::Piece::T::color,
      Math::Round(pivRow),
      Math::Round(pivCol + 1.0)});
}
