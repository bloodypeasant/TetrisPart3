#pragma once
#include "Config.hpp"
#include "Controller.hpp"
#include "Model.hpp"
#include "SDL.h" // for timer's Uint32
#include "View.hpp"

class Game
{
public:
  /**
   * Constructs a game.
   */
  Game();

  /**
   * Destructs a game.
   */
  ~Game();

  /**
   * Gets pointer tocontroller.
   * @return pointer to controller
   */
  Controller *GetController();

  /**
   * Gets pointer to model.
   * @return pointer to model
   */
  Model *GetModel();

  /**
   * Gets pointer to view.
   * @return pointer to view
   */
  View *GetView();

  /**
   * Quits the game fully and closes window.
   */
  void QuitPlaying();

  /**
   * Restarts the game; doesn't re-initialize.
   */
  void Restart();

  /**
   * Stops running the current game only.
   */
  void StopRunning();

  // private:
  //   /**
  //    * Initializes the game; no need to repeat on restart.
  //    */
  //   bool Initialize();

  /**
   * Runs the current game loop.
   */
  void Run();

  Model model;           // game's model
  View view;             // game's view
  Controller controller; // game's controller

  bool isPlayingAgain = true;                     // loops new games
  bool isRunning = false;                         // loops same game
  Uint32 const ticksMax = Config::Game::ticksMax; // max game time b/w frames
  Uint32 const ticksMin = Config::Game::ticksMin; // min real time b/w frames
  Uint32 ticksPrior = 0;                          // absolute game time
};
