#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "player.h"
#include "world.h"
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;
using std::size;

using namespace sf;

int main() {
  IntRect world = setWorldSize();

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

  // Game Tile Texture
  Texture horizontalRoadTexture;
  horizontalRoadTexture.loadFromFile("graphics/streetTileTexture.png");

  // Create background Vertex array
  VertexArray background;
  background.setPrimitiveType(Quads);
  background.resize(widthTiles * heightTiles * 4);

  createBackground(background, world);

  bool spawned = false;

  while(window.isOpen()) {
    Event event;

    while (window.pollEvent(event)) {
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Escape) {
          window.close();
        }
      }
    }

    if (Keyboard::isKeyPressed(Keyboard::W)) {
      player.moveUp();
    } else {
      player.stopUp();
    }

    if (Keyboard::isKeyPressed(Keyboard::S)) {
      player.moveDown();
    } else {
      player.stopDown();
    }

    if (Keyboard::isKeyPressed(Keyboard::A)) {
      player.moveLeft();
    } else {
      player.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::D)) {
      player.moveRight();
    } else {
      player.stopRight();
    }

    if (spawned == false) {
      player.setSprite("graphics/blood.png");
      player.spawn(world, resolution);
      spawned = true;
    }

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

    window.draw(background, &horizontalRoadTexture);

    window.draw(player.getSprite());
    window.draw(spriteCrosshair);

    window.display();
  }

  return 0;
}

