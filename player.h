#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
  private:
    Vector2f m_Position;
    IntRect m_World;
    Sprite m_Sprite;
    Texture m_Texture;
    Vector2f m_Resolution;
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_LeftPressed;
    bool m_RightPressed;
    float m_Speed = 200; // Speed in pixels per second
    float m_Width = 51;
    float m_Height = 75;

  public:
    Player();

    void spawn(IntRect world, Vector2f resolution);

    void update(float elapsedTime, Vector2i mousePosition);

    Sprite getSprite();

    void setSprite(String TexturePath);

    Vector2f getCenter();

    void moveLeft();

    void moveRight();

    void moveDown();

    void moveUp();

    void stopLeft();

    void stopRight();

    void stopUp();

    void stopDown();
};
