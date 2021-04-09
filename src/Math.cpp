#include "Math.hpp"
#include <stdlib.h>
#include <time.h>

float Random::GetFloat()
{
  return rand() / (float)(RAND_MAX);
}

float Random::GetFloat(float min, float max)
{
  return min + GetFloat() * (max - min);
}

int Random::GetInt(int min, int max)
{
  return min + (int)(GetFloat() * (1 + max - min));
}

void Random::Initialize()
{
  srand(time(NULL));
}
