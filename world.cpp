#include "world.h"
#include <iostream>

using std::size;

IntRect setWorldSize() {
  IntRect world;

  world.width = widthTiles * 256;
  world.height = heightTiles * 256;

  return world;
}

void createBackground(VertexArray& background, IntRect world) {

  int currentBackroudQuadPosition = 0;

  for (int i = 0; i < size(map); i++) {
    for (int j = 0; j < size(map[j]); j++) {

      char strValue = map[i][j];

      Vector2f topLeftPosition = Vector2f(j * 256, i * 256);
      Vector2f topRighttPosition = Vector2f((j + 1) * 256, i * 256);
      Vector2f BottomRightPosition = Vector2f((j + 1) * 256, (i + 1) * 256);
      Vector2f BottomLeftPosition = Vector2f(j * 256, (i + 1) * 256);

      switch(strValue) {
        case 'x':
          break;
        case '-':
          background[currentBackroudQuadPosition].position = topLeftPosition;
          background[currentBackroudQuadPosition + 1].position = topRighttPosition;
          background[currentBackroudQuadPosition + 2].position = BottomRightPosition;
          background[currentBackroudQuadPosition + 3].position = BottomLeftPosition;

          background[currentBackroudQuadPosition].texCoords = Vector2f(0, 0);
          background[currentBackroudQuadPosition + 1].texCoords = Vector2f(256, 0);
          background[currentBackroudQuadPosition + 2].texCoords = Vector2f(256, 256);
          background[currentBackroudQuadPosition + 3].texCoords = Vector2f(0, 256);

          break;
        case 'n':
          background[currentBackroudQuadPosition].position = topLeftPosition;
          background[currentBackroudQuadPosition + 1].position = topRighttPosition;
          background[currentBackroudQuadPosition + 2].position = BottomRightPosition;
          background[currentBackroudQuadPosition + 3].position = BottomLeftPosition;

          background[currentBackroudQuadPosition].texCoords = Vector2f(1280, 0);
          background[currentBackroudQuadPosition + 1].texCoords = Vector2f(1536, 0);
          background[currentBackroudQuadPosition + 2].texCoords = Vector2f(1536, 256);
          background[currentBackroudQuadPosition + 3].texCoords = Vector2f(1280, 256);

          break;
        case '|':
          background[currentBackroudQuadPosition].position = topLeftPosition;
          background[currentBackroudQuadPosition + 1].position = topRighttPosition;
          background[currentBackroudQuadPosition + 2].position = BottomRightPosition;
          background[currentBackroudQuadPosition + 3].position = BottomLeftPosition;

          background[currentBackroudQuadPosition].texCoords = Vector2f(512, 0);
          background[currentBackroudQuadPosition + 1].texCoords = Vector2f(768, 0);
          background[currentBackroudQuadPosition + 2].texCoords = Vector2f(768, 256);
          background[currentBackroudQuadPosition + 3].texCoords = Vector2f(512, 256);

          break;
        case 'j':
          background[currentBackroudQuadPosition].position = topLeftPosition;
          background[currentBackroudQuadPosition + 1].position = topRighttPosition;
          background[currentBackroudQuadPosition + 2].position = BottomRightPosition;
          background[currentBackroudQuadPosition + 3].position = BottomLeftPosition;

          background[currentBackroudQuadPosition].texCoords = Vector2f(768, 0);
          background[currentBackroudQuadPosition + 1].texCoords = Vector2f(1024, 0);
          background[currentBackroudQuadPosition + 2].texCoords = Vector2f(1024, 256);
          background[currentBackroudQuadPosition + 3].texCoords = Vector2f(768, 256);

          break;
        case 'p':
          background[currentBackroudQuadPosition].position = topLeftPosition;
          background[currentBackroudQuadPosition + 1].position = topRighttPosition;
          background[currentBackroudQuadPosition + 2].position = BottomRightPosition;
          background[currentBackroudQuadPosition + 3].position = BottomLeftPosition;

          background[currentBackroudQuadPosition].texCoords = Vector2f(1024, 0);
          background[currentBackroudQuadPosition + 1].texCoords = Vector2f(1280, 0);
          background[currentBackroudQuadPosition + 2].texCoords = Vector2f(1280, 256);
          background[currentBackroudQuadPosition + 3].texCoords = Vector2f(1024, 256);

          break;
        case 'L':
          background[currentBackroudQuadPosition].position = topLeftPosition;
          background[currentBackroudQuadPosition + 1].position = topRighttPosition;
          background[currentBackroudQuadPosition + 2].position = BottomRightPosition;
          background[currentBackroudQuadPosition + 3].position = BottomLeftPosition;

          background[currentBackroudQuadPosition].texCoords = Vector2f(256, 0);
          background[currentBackroudQuadPosition + 1].texCoords = Vector2f(512, 0);
          background[currentBackroudQuadPosition + 2].texCoords = Vector2f(512, 256);
          background[currentBackroudQuadPosition + 3].texCoords = Vector2f(256, 256);

          break;
        case 'o':
          background[currentBackroudQuadPosition].position = topLeftPosition;
          background[currentBackroudQuadPosition + 1].position = topRighttPosition;
          background[currentBackroudQuadPosition + 2].position = BottomRightPosition;
          background[currentBackroudQuadPosition + 3].position = BottomLeftPosition;

          background[currentBackroudQuadPosition].texCoords = Vector2f(1536, 0);
          background[currentBackroudQuadPosition + 1].texCoords = Vector2f(1792, 0);
          background[currentBackroudQuadPosition + 2].texCoords = Vector2f(1792, 256);
          background[currentBackroudQuadPosition + 3].texCoords = Vector2f(1536, 256);

          break;
      }
      currentBackroudQuadPosition += 4;
    }
  }
}

