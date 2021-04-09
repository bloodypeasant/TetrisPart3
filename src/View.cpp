#include <iostream>
#include "Block.hpp"
#include "Game.hpp"
#include "Math.hpp"
#include "View.hpp"

using std::cout;

View::View(Game *game)
    : game(game)
{
  cout << "View::View()\n";
}

// TODO:  Set pointers to NULL or nullptr
View::~View()
{
  cout << "View::~View()\n";
  Mix_FreeMusic(music);

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  Mix_Quit();
  //IMG_Quit();
  SDL_Quit();
}

void View::Drop()
{
  Mix_PlayChannel(-1, drop, 0);
}

void View::GameOver()
{
  Mix_PlayChannel(-1, gameOver, 0);
}

void View::HitHard()
{
  Mix_PlayChannel(-1, hitHard, 0);
}

void View::HitSoft()
{
  Mix_PlayChannel(-1, hitSoft, 0);
}

bool View::Initialize()
{
  cout << "View::Initialize()\n";
  model = game->GetModel();

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
  {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return false;
  }

  window = SDL_CreateWindow(
      Config::View::title,
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      Config::View::windowDimX, Config::View::windowDimY,
      SDL_WINDOW_RESIZABLE);
  if (!window)
  {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return false;
  }

  renderer = SDL_CreateRenderer(
      window,
      -1,
      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer)
  {
    SDL_Log("Failed to create renderer: %s", SDL_GetError());
    return false;
  }

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
  {
    SDL_Log("Failed to initialize mixer: %s", Mix_GetError());
    return false;
  }
  music = Mix_LoadMUS(Config::Media::music);
  if (music == NULL)
  {
    SDL_Log("Failed to load music.");
    return false;
  }
  drop = Mix_LoadWAV(Config::Media::drop);
  if (drop == NULL)
  {
    SDL_Log("Failed to load drop.");
    return false;
  }
  gameOver = Mix_LoadWAV(Config::Media::gameOver);
  if (gameOver == NULL)
  {
    SDL_Log("Failed to load gameOver.");
    return false;
  }
  hitHard = Mix_LoadWAV(Config::Media::hitHard);
  if (hitHard == NULL)
  {
    SDL_Log("Failed to load hitHard.");
    return false;
  }
  hitSoft = Mix_LoadWAV(Config::Media::hitSoft);
  if (hitSoft == NULL)
  {
    SDL_Log("Failed to load hitSoft.");
    return false;
  }
  pause = Mix_LoadWAV(Config::Media::pause);
  if (pause == NULL)
  {
    SDL_Log("Failed to load pause.");
    return false;
  }
  remove = Mix_LoadWAV(Config::Media::remove);
  if (remove == NULL)
  {
    SDL_Log("Failed to load remove.");
    return false;
  }
  remove4 = Mix_LoadWAV(Config::Media::remove4);
  if (remove4 == NULL)
  {
    SDL_Log("Failed to load remove4.");
    return false;
  }
  rotate = Mix_LoadWAV(Config::Media::rotate);
  if (rotate == NULL)
  {
    SDL_Log("Failed to load rotate.");
    return false;
  }
  select = Mix_LoadWAV(Config::Media::select);
  if (select == NULL)
  {
    SDL_Log("Failed to load select.");
    return false;
  }
  start = Mix_LoadWAV(Config::Media::start);
  if (start == NULL)
  {
    SDL_Log("Failed to load start.");
    return false;
  }
  whoosh = Mix_LoadWAV(Config::Media::whoosh);
  if (whoosh == NULL)
  {
    SDL_Log("Failed to load whoosh.");
    return false;
  }

  Resize();
  Block::SetRenderer(renderer);
  return true;
}

void View::MusicPauseToggle()
{
  if (Mix_PausedMusic() == 1)
  {
    Mix_ResumeMusic();
  }
  else
  {
    Mix_PauseMusic();
  }
}

void View::MusicPlay()
{
  Mix_PlayMusic(music, -1);
}

void View::MusicStop()
{
  Mix_HaltMusic();
}

void View::Pause()
{
  Mix_PlayChannel(-1, pause, 0);
}

void View::Remove()
{
  Mix_PlayChannel(-1, remove, 0);
}

void View::Remove4()
{
  Mix_PlayChannel(-1, remove4, 0);
}

void View::Resize()
{
  cout << "View::Resize()\n";
  SDL_GL_GetDrawableSize(window, &windowDimX, &windowDimY);
  int gameDimX = boardDimX + Config::Model::panelDimX;
  int gameDimY = Math::Max<int>(boardDimY, Config::Model::panelDimY);
  int blockMaxDimX = windowDimX / gameDimX;
  int blockMaxDimY = windowDimY / gameDimY;
  blockSize = Math::Min<int>(blockMaxDimX, blockMaxDimY);
  windowMarginX = (windowDimX - blockSize * gameDimX) / 2;
  windowMarginY = (windowDimY - blockSize * gameDimY) / 2;
  Block::SetSize(blockSize);
}

void View::Rotate()
{
  Mix_PlayChannel(-1, rotate, 0);
}

void View::Run()
{
  SDL_SetRenderDrawColor(renderer, colorBg.r, colorBg.g, colorBg.b, 255);
  SDL_RenderClear(renderer);
  for (int row = 0; row < boardDimY; ++row)
  {
    for (int col = 0; col < boardDimX; ++col)
    {
      Block *block = model->GetBlock(row, col);
      if (block)
      {
        block->Draw();
      }
    }
  }
  model->GetPiece()->Draw();
  SDL_RenderPresent(renderer);
}

void View::Select()
{
  Mix_PlayChannel(-1, select, 0);
}

void View::Start()
{
  Mix_PlayChannel(-1, start, 0);
}

void View::Whoosh()
{
  Mix_PlayChannel(-1, whoosh, 0);
}
