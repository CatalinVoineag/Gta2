#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
  private:
    Vector2f m_Position;
    Sprite m_Sprite;
    Texture m_Texture;
    Vector2f m_Resolution;

  public:
    Player();

    void spawn(IntRect world, Vector2f resolution);

    void update(float elapsedTime, Vector2i mousePosition);

    Sprite getSprite();

    Vector2f getCenter();
};
