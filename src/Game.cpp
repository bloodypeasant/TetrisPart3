#include <iostream>
#include "Game.hpp"

using std::cout;

Game::Game()
    : model(this), view(this), controller(this)
{
  cout << "Game::Game()\n";
  controller.Initialize();
  model.Initialize();
  if (view.Initialize())
  {
    while (isPlayingAgain)
    {
      Restart();
    }
  }
}

Game::~Game()
{
  cout << "Game::~Game()\n";
}

Controller *Game::GetController()
{
  return &controller;
}

Model *Game::GetModel()
{
  return &model;
}

View *Game::GetView()
{
  return &view;
}

// bool Game::Initialize()
// {
//   cout << "Game::Initialize()\n";
//   model.Initialize();
//   controller.Initialize();
//   return view.Initialize();
// }

void Game::QuitPlaying()
{
  cout << "Game::QuitPlaying()\n";
  isPlayingAgain = isRunning = false;
}

void Game::Restart()
{
  cout << "Game::Restart()\n";
  isRunning = true;
  model.Restart();
  //view.Restart();
  controller.Restart();
  Run();
}

void Game::Run()
{
  cout << "Game::Run()\n";
  ticksPrior = SDL_GetTicks();
  while (isRunning)
  {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksPrior + ticksMin))
      ;
    Uint32 ticksChange = SDL_GetTicks() - ticksPrior;
    if (ticksChange > ticksMax)
    {
      ticksChange = ticksMax;
    }
    controller.Run(ticksChange);
    view.Run();
    ticksPrior = SDL_GetTicks();
  }
}

void Game::StopRunning()
{
  cout << "Game::StopRunning()\n";
  isRunning = false;
  view.MusicStop();
}
