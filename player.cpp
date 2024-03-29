#include "player.h"
#include <cmath>

Player::Player() {
  m_Texture.loadFromFile("graphics/player_character_idle.png");
  m_Sprite.setTexture(m_Texture);

  m_Sprite.setOrigin(25.5, 37.5);
}

void Player::spawn(IntRect world, Vector2f resolution) {
  m_Position.x = world.width / 2;
  m_Position.y = world.height / 2;

  m_Resolution = resolution;
}

void Player::update(float elapsedTime, Vector2i mousePosition) {
	if (m_UpPressed) {
		m_Position.y -= m_Speed * elapsedTime;
	}

	if (m_DownPressed) {
		m_Position.y += m_Speed * elapsedTime;
	}

	if (m_RightPressed) {
		m_Position.x += m_Speed * elapsedTime;
	}

	if (m_LeftPressed) {
		m_Position.x -= m_Speed * elapsedTime;
	}


	float angle = atan2(
    mousePosition.y - m_Resolution.y / 2,
    mousePosition.x - m_Resolution.x / 2
  );
  angle = angle * (180 / 3.141);

  if (angle < 0) {
    angle = 360 - (-angle);
  }

  m_Sprite.setRotation(angle);
  m_Sprite.setPosition(m_Position);
}

Sprite Player::getSprite() {
  return m_Sprite;
}

Vector2f Player::getCenter() {
  return m_Position;
}

void Player::moveLeft() {
	m_LeftPressed = true;
}

void Player::moveRight() {
	m_RightPressed = true;
}

void Player::moveUp() {
	m_UpPressed = true;
}

void Player::moveDown() {
	m_DownPressed = true;
}

void Player::stopLeft() {
	m_LeftPressed = false;
}

void Player::stopRight() {
	m_RightPressed = false;
}

void Player::stopUp() {
	m_UpPressed = false;
}

void Player::stopDown() {
	m_DownPressed = false;
}
