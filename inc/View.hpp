#pragma once
#include "Config.hpp"
#include "SDL_mixer.h"
#include "SDL.h"

class View
{
public:
  /**
   * Constructs view.
   */
  View(class Game *game);

  /**
   * Destructs view.
   */
  ~View();

  void Drop();
  void GameOver();
  void HitHard();
  void HitSoft();
  void MusicPauseToggle();
  void MusicPlay();
  void MusicStop();
  void Pause();
  void Remove();
  void Remove4();
  void Rotate();
  void Select();
  void Start();
  void Whoosh();

  /**
   * Initializes the view.
   * @return success
   */
  bool Initialize();

  /**
   * Resizes window to fit game exactly.
   */
  void Resize();

  /**
   * Runs the view (draws all).
   */
  void Run();

private:
  int boardDimX = Config::Model::boardDimX; // model units
  int boardDimY = Config::Model::boardDimY; // model units

  Color const &colorBg = Config::View::colorBackground; // background color

  class Game *game;   // pointer to the game
  class Model *model; // pointer to the model

  Mix_Music *music = nullptr;

  Mix_Chunk *drop = nullptr;
  Mix_Chunk *gameOver = nullptr;
  Mix_Chunk *hitHard = nullptr;
  Mix_Chunk *hitSoft = nullptr;
  Mix_Chunk *pause = nullptr;
  Mix_Chunk *remove = nullptr;
  Mix_Chunk *remove4 = nullptr;
  Mix_Chunk *rotate = nullptr;
  Mix_Chunk *select = nullptr;
  Mix_Chunk *start = nullptr;
  Mix_Chunk *whoosh = nullptr;

  SDL_Renderer *renderer = nullptr; // to be determined
  SDL_Window *window = nullptr;     // to be determined

  int blockSize = 0;     // px to be determined
  int windowDimX = 0;    // px to be determined
  int windowDimY = 0;    // px to be determined
  int windowMarginX = 0; // px to be determined
  int windowMarginY = 0; // px to be determined
};
