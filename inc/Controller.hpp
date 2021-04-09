#pragma once
#include "Config.hpp"

class Controller
{
public:
  /**
   * Constructs controller.
   */
  Controller(class Game *game);

  /**
   * Destructs controller.
   */
  ~Controller();

  void Initialize();

  bool IsFallingFast();

  /**
   * Restarts controller.
   */
  void Restart();

  /**
   * Runs controller (updates user inputs)
   */
  void Run(int ticksChange);

private:
  bool isFallingFast = false;

  int const ticksA = Config::Controller::ticksA;         // reqd ms b/w rots
  int ticksA_running = 0;                                // running ms b/w rots
  int const ticksX = Config::Controller::ticksX;         // reqd ms b/w moves
  int ticksX_running = 0;                                // running ms b/w moves
  int const ticksYFast = Config::Controller::ticksYFast; // reqd ms b/w drops
  int ticksYSlow = Config::Controller::ticksYSlow;       // reqd ms b/w drops
  int ticksY_running = 0;                                // running ms b/w drops

  class Game *game;             // pointer to the game
  class Model *model = nullptr; // pointer to the model
  class View *view = nullptr;   // pointer to the view
};
