#pragma once

struct Color
{
  Color(int r, int g, int b);

  static Color const black;
  static Color const blue;
  static Color const cyan;
  static Color const gray;
  static Color const green;
  static Color const magenta;
  static Color const orange;
  static Color const red;
  static Color const yellow;
  static Color const white;

  int r;
  int g;
  int b;
};
