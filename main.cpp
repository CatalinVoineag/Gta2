#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "player.h"
#include <cmath>
#include <iostream>

using namespace sf;

int main() {
  IntRect world;
  world.width = 1000;
  world.height = 1000;

	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

  // Game window
  RenderWindow window(
    VideoMode(resolution.x, resolution.y),
    "GTA2"
  );

  // View that will follow the player
  View mainView(FloatRect(0, 0, resolution.x, resolution.y));

  // Where is the mouse in
  // relation to world coordinates
  Vector2f mouseWorldPosition;
  // Where is the mouse in
  // relation to screen coordinates
  Vector2i mouseScreenPosition;

  Player player;

  Clock clock;

  // Crosshair, hide mouse pointer and replace with crosshair
  window.setMouseCursorVisible(false);
  Sprite spriteCrosshair;
  Texture textureCrosshair;
  textureCrosshair.loadFromFile("graphics/crosshair.png");
  spriteCrosshair.setTexture(textureCrosshair);

  while(window.isOpen()) {
    Event event;

    while (window.pollEvent(event)) {
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Escape) {
          window.close();
        }
      }
    }

    player.spawn(world, resolution);

    // Update the frame
    Time dt = clock.restart();

    // Make decimal fraction of 1 from delta time
    float dtAsSeconds = dt.asSeconds();

    // Where is the mouse pointer?
    mouseScreenPosition = Mouse::getPosition();

    // Convert mouse position to world coordinates of mainView
    mouseWorldPosition = window.mapPixelToCoords(
      Mouse::getPosition(),
      mainView
    );

    // Set crosshair to the mouse world location
    spriteCrosshair.setPosition(mouseWorldPosition);

    // Update the player
    player.update(dtAsSeconds, Mouse::getPosition());

    // Make the view centre around the player
    mainView.setCenter(player.getCenter());

    window.clear();

    window.setView(mainView);

    window.draw(player.getSprite());
    window.draw(spriteCrosshair);

    window.display();
  }

  return 0;
}
