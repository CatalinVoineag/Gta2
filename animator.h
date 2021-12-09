#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Animator {
  private:
    float m_TimeSinceLastAnimation;
    float m_ElapsedTime;
    Texture m_StyleSheetTexture;

  public:
    call(String StyleSheetPath, float, TimeSinceLastAnimation, float ElapsedTime);


// We already have this update method that has delta time in it.
// Should we use this method to call to an Animator class?
// Pass to the animator class the SpriteSheet?
// Pass the numbers index numbers of the spriteSheet?
// The Animator class loads the spritesheet
// Every 1 second changes the texture of the player with the spriteSheet index
// Loops over the spritesheet to change the texture
// When getting to the end goes back to the first texture
// That's it. Co pilot do my work!

}
