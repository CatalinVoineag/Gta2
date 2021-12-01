#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using std::size;

const  char map[4][9] = {
  {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
  {'p', '-', '-', '-', '-', 'n', 'x', 'x', 'x'},
  {'|', 'o', 'o', 'o', 'o', '|', 'x', 'x', 'x'},
  {'L', '-', '-', '-', '-', 'j', 'x', 'x', 'x'}
};

const int widthTiles = size(map[0]);
const  int heightTiles = size(map);

void createBackground(VertexArray& backround, IntRect world);

IntRect setWorldSize();
