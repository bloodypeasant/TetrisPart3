#include "Color.hpp"

Color::Color(int r, int g, int b)
    : r(r), g(g), b(b)
{
}

Color const Color::black{0, 0, 0};
Color const Color::blue{0, 0, 255};
Color const Color::cyan{0, 255, 255};
Color const Color::gray{128, 128, 128};
Color const Color::green{0, 255, 0};
Color const Color::magenta{255, 0, 255};
Color const Color::orange{255, 128, 0};
Color const Color::red{255, 0, 0};
Color const Color::yellow{255, 255, 0};
Color const Color::white{255, 255, 255};
