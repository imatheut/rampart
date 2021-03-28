#include <gf/Event.h>
#include <gf/Font.h>
#include <gf/RenderWindow.h>
#include <gf/Sprite.h>
#include <gf/Text.h>
#include <gf/Window.h>
#include <gf/EntityContainer.h>
#include <gf/Action.h>

#include "local/Singletons.h"
#include "local/Engine.h"
#include "config.h"



int main() {
  // Create the main window and the renderer
  gf::Window window("Rampart", { 800, 700});
  gf::RenderWindow renderer(window);


  gf::SingletonStorage<gf::ResourceManager> storageForResourceManager(rampart::gResourceManager);

  // actions
  gf::ActionContainer actions;
  gf::Action closeWindowAction("Close window");
  closeWindowAction.addCloseControl();
  closeWindowAction.addKeycodeKeyControl(gf::Keycode::Escape);
  actions.addAction(closeWindowAction);





  // adding ressources to rampart data directory
  rampart::gResourceManager().addSearchDir(RAMPART_DATA_DIR);

  

  rampart::Engine engine;

  
  
  engine.initGame();
  engine.gameIntro(renderer);

  // Create a graphical text to display
  gf::RenderStates states;
  renderer.clear(gf::Color::White);
  // Start the game loop
  while (window.isOpen()) {
    // Process events
    gf::Event event;
    while (window.pollEvent(event)) {
      actions.processEvent(event);

      switch (event.type) {
        case gf::EventType::MouseButtonPressed: {
          engine.selectCastle(event.mouseButton.coords);
          engine.shoot(event.mouseButton.coords);
        }
          break;
        case gf::EventType::MouseMoved : {
          engine.rotateCannons(renderer.mapCoordsToPixel(event.mouseCursor.coords));
        } 
          break; 
        default:
          break;
      }

      if (closeWindowAction.isActive()) {
        window.close();
      }
  
    }

    renderer.clear();
    engine.draw(renderer, states);
    engine.update();
    renderer.display();
  }
  return 0;
}
