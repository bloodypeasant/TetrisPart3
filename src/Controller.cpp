#include <iostream>
#include "Controller.hpp"
#include "Game.hpp"

using std::cout;

Controller::Controller(Game *game)
    : game(game)
{
  cout << "Controller::Controller()\n";
}

Controller::~Controller()
{
  cout << "Controller::~Controller()\n";
}

void Controller::Initialize()
{
  model = game->GetModel();
  view = game->GetView();
}

bool Controller::IsFallingFast()
{
  return isFallingFast;
}

void Controller::Restart()
{
  cout << "Controller::Restart()\n";
  view->Start();
  view->MusicPlay();
  ticksA_running = ticksX_running = ticksY_running = 0;
}

void Controller::Run(int ticksChange)
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      game->QuitPlaying();
      return;
    case SDL_WINDOWEVENT:
      switch (event.window.event)
      {
      case SDL_WINDOWEVENT_RESIZED:
        view->Resize();
        break;
      }
      return;
    }
  }

  const Uint8 *keyState = SDL_GetKeyboardState(NULL);
  if (keyState[SDL_SCANCODE_ESCAPE])
  {
    game->QuitPlaying();
    return;
  }

  ticksY_running += ticksChange;
  if (keyState[SDL_SCANCODE_S] || keyState[SDL_SCANCODE_DOWN])
  {
    if (model->CanFallFast())
    {
      isFallingFast = true;
      if (ticksY_running >= ticksYFast)
      {
        model->TranslatePiece(1, 0);
        ticksY_running = 0;
      }
    }
    else
    {
      if (ticksY_running >= ticksYSlow)
      {
        model->TranslatePiece(1, 0);
        ticksY_running = 0;
      }
    }
  }
  else
  {
    model->SetCanFallFast();
    if (ticksY_running >= ticksYSlow)
    {
      model->TranslatePiece(1, 0);
      ticksY_running = 0;
    }
  }

  ticksX_running += ticksChange;
  if (keyState[SDL_SCANCODE_LEFT] && !keyState[SDL_SCANCODE_RIGHT])
  {
    if (ticksX_running >= ticksX)
    {
      model->TranslatePiece(0, -1);
      ticksX_running = 0;
    }
  }
  else if (keyState[SDL_SCANCODE_RIGHT] && !keyState[SDL_SCANCODE_LEFT])
  {
    if (ticksX_running >= ticksX)
    {
      model->TranslatePiece(0, 1);
      ticksX_running = 0;
    }
  }

  ticksA_running += ticksChange;
  if (keyState[SDL_SCANCODE_W] ||
      (keyState[SDL_SCANCODE_A] && !keyState[SDL_SCANCODE_D]))
  {
    if (ticksA_running >= ticksA)
    {
      model->RotatePiece(-1);
      ticksA_running = 0;
    }
  }
  else if (keyState[SDL_SCANCODE_UP] ||
           (keyState[SDL_SCANCODE_D] && !keyState[SDL_SCANCODE_A]))
  {
    if (ticksA_running >= ticksA)
    {
      model->RotatePiece(1);
      ticksA_running = 0;
    }
  }
}
