#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

using namespace sf;

int main() {
  RenderWindow window(VideoMode(1000, 600), "GTA2");


  while(window.isOpen()) {
    Event event;

    while (window.pollEvent(event)) {
      if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Escape) {
          window.close();
        }
      }
    }

    window.clear(Color::Black);

    window.display();
  }

  return 0;
}
