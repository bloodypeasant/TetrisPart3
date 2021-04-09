#include "Config.hpp"
#include "PieceJ.hpp"

PieceJ::PieceJ()
    : Piece(Config::Piece::J::pivRow, Config::Piece::J::pivCol)
{
  blocks.emplace_back(new Block{
      Config::Piece::J::color,
      Math::Round(pivRow - 1.0),
      Math::Round(pivCol - 1.0)});
  blocks.emplace_back(new Block{
      Config::Piece::J::color,
      Math::Round(pivRow),
      Math::Round(pivCol - 1.0)});
  blocks.emplace_back(new Block{
      Config::Piece::J::color,
      Math::Round(pivRow),
      Math::Round(pivCol)});
  blocks.emplace_back(new Block{
      Config::Piece::J::color,
      Math::Round(pivRow),
      Math::Round(pivCol + 1.0)});
}
