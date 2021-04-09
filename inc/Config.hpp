#pragma once
#include "Color.hpp"

struct Config
{

  struct Controller
  {
    static int constexpr ticksA = 150;          // milliseconds b/w rotations
    static int constexpr ticksX = 75;           // milliseconds b/w moves
    static int constexpr ticksYFast = 0;        // milliseconds b/w drops
    static int constexpr ticksYSlow = 500;      // milliseconds b/w drops
    static int constexpr ticksResizeMax = 3000; // max time to wait for resize
  };

  struct Game
  {
    static int constexpr ticksMax = 50; // maximum game time b/w animations
    static int constexpr ticksMin = 16; // minimum real time b/w animations
  };

  struct Media
  {
    inline static char const *drop = "media/drop.mp3";
    inline static char const *gameOver = "media/game-over.mp3";
    inline static char const *hitHard = "media/hit-hard.mp3";
    inline static char const *hitSoft = "media/hit-soft.mp3";
    inline static char const *music = "media/music-1.ogg";
    inline static char const *pause = "media/pause.mp3";
    inline static char const *remove = "media/remove.mp3";
    inline static char const *remove4 = "media/remove4.mp3";
    inline static char const *rotate = "media/rotate.mp3";
    inline static char const *select = "media/select.mp3";
    inline static char const *start = "media/start.mp3";
    inline static char const *whoosh = "media/whoosh.mp3";
  };

  struct Model
  {
    static int constexpr boardDimX = 12; // num cols, including walls
    static int constexpr boardDimY = 22; // num rows, including walls

    static int constexpr panelDimX = 6; // num cols needed in side panel
    static int constexpr panelDimY = 4; // num rows needed in side panel
  };

  struct Piece
  {
    struct I
    {
      inline static Color const &color = Color::cyan;
      static double constexpr pivRow = 1.5;
      static double constexpr pivCol = Config::Model::boardDimX / 2.0 - 0.5;
    };

    struct J
    {
      inline static Color const &color = Color::blue;
      static double constexpr pivRow = 2.0;
      static double constexpr pivCol = Config::Model::boardDimX / 2.0 - 1.0;
    };

    struct L
    {
      inline static Color const &color = Color::orange;
      static double constexpr pivRow = 2.0;
      static double constexpr pivCol = Config::Model::boardDimX / 2.0 - 1.0;
    };

    struct O
    {
      inline static Color const &color = Color::yellow;
      static double constexpr pivRow = 2.5;
      static double constexpr pivCol = Config::Model::boardDimX / 2.0 - 0.5;
    };

    struct S
    {
      inline static Color const &color = Color::green;
      static double constexpr pivRow = 2.0;
      static double constexpr pivCol = Config::Model::boardDimX / 2.0 - 1.0;
    };

    struct T
    {
      inline static Color const &color = Color::magenta;
      static double constexpr pivRow = 2.0;
      static double constexpr pivCol = Config::Model::boardDimX / 2.0 - 1.0;
    };

    struct Z
    {
      inline static Color const &color = Color::red;
      static double constexpr pivRow = 2.0;
      static double constexpr pivCol = Config::Model::boardDimX / 2.0 - 1.0;
    };
  };

  struct View
  {
    inline static Color const &colorBackground = Color::black;
    static int constexpr windowDimX = 1024;
    static int constexpr windowDimY = 768;
    inline static char const *title = "Tetris"; // window's title
  };
};
