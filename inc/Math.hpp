#pragma once
#include <vector>

namespace Math
{
  template <typename T>
  inline T Max(T optA, T optB)
  {
    return optA < optB ? optB : optA;
  }

  template <typename T>
  inline T Min(T optA, T optB)
  {
    return optB < optA ? optB : optA;
  }

  inline int Round(double d)
  {
    return (int)(d + 0.5 + (d < 0));
  }

  inline int Round(float f)
  {
    return (int)(f + 0.5F + (f < 0));
  }
}

class Random
{
public:
  static float GetFloat();
  static float GetFloat(float min, float max);
  static int GetInt(int min, int max);
  static void Initialize();
};

template <typename T>
class Matrix
{
public:
  Matrix(int numRows, int numCols, T fill);
  ~Matrix();

  T GetElementAt(int row, int col);
  Matrix<T> *RotateCCW();
  Matrix<T> *RotateCW();
  void SetElementAt(T element, int row, int col);

private:
  std::vector<std::vector<T> *> elements;
  T fill;
  int numCols;
  int numRows;
};

template <typename T>
Matrix<T>::Matrix(int numRows, int numCols, T fill)
    : numRows(numRows), numCols(numCols), fill(fill)
{
  for (int row = 0; row < numRows; ++row)
  {
    std::vector<T> *elementsRow = new std::vector<T>;
    elements.emplace_back(elementsRow);
    for (int col = 0; col < numCols; ++col)
    {
      elementsRow->emplace_back(fill);
    }
  }
}

template <typename T>
Matrix<T>::~Matrix()
{
  for (int row = 0; row < numRows; ++row)
  {
    std::vector<T> *elementsRow = elements[row];
    delete elementsRow;
    elementsRow = nullptr;
  }
}

template <typename T>
T Matrix<T>::GetElementAt(int row, int col)
{
  return elements[row]->at(col);
}

template <typename T>
Matrix<T> *Matrix<T>::RotateCCW()
{
  Matrix<T> *matrix = new Matrix<T>(numCols, numRows, fill);
  for (int rowOld = 0; rowOld < numRows; ++rowOld)
  {
    for (int colOld = 0; colOld < numCols; ++colOld)
    {
      matrix->SetElementAt(
          GetElementAt(rowOld, colOld),
          numCols - colOld - 1,
          rowOld);
    }
  }
  return matrix;
}

template <typename T>
Matrix<T> *Matrix<T>::RotateCW()
{
  Matrix<T> *matrix = new Matrix<T>(numCols, numRows, fill);
  for (int rowOld = 0; rowOld < numRows; ++rowOld)
  {
    for (int colOld = 0; colOld < numCols; ++colOld)
    {
      matrix->SetElementAt(
          GetElementAt(rowOld, colOld),
          colOld,
          numRows - rowOld - 1);
    }
  }
  return matrix;
}

template <typename T>
void Matrix<T>::SetElementAt(T element, int row, int col)
{
  elements[row]->at(col) = element;
}
