#include <gf/Event.h>
#include <gf/Font.h>
#include <gf/RenderWindow.h>
#include <gf/Sprite.h>
#include <gf/Text.h>
#include <gf/Window.h>
#include <gf/EntityContainer.h>


#include "local/Singletons.h"
#include "local/Engine.h"
#include "config.h"


#include <iostream>

int main() {
  // Create the main window and the renderer
  gf::Window window("Rampart", { 800, 700});
  gf::RenderWindow renderer(window);


  gf::SingletonStorage<gf::ResourceManager> storageForResourceManager(rampart::gResourceManager);

  // adding ressources to rampart data directory
  rampart::gResourceManager().addSearchDir(RAMPART_DATA_DIR);

  

  rampart::Engine engine;


  engine.initGame({12,12});

  // Create a graphical text to display
  gf::RenderStates states;
  renderer.clear(gf::Color::White);
  // Start the game loop
  while (window.isOpen()) {
    gf::EventType test = gf::EventType::MouseMoved;
   
  
    // Process events
    gf::Event event;
   // engine.testSelectCastle(event);
    while (window.pollEvent(event)) {
      switch (event.type) {
        case gf::EventType::Closed: // window close
          window.close();
          break;
        case gf::EventType::KeyPressed: {
                  auto keycode = event.key.keycode;
                  switch (keycode) {
                    case gf::Keycode::Escape:
                        window.close();
                      break; 
                    default:
                      break;
                  }
          
                }

          break;

        case gf::EventType::MouseButtonPressed: {
          engine.selectCastle(event.mouseButton.coords);
        } 
          break; 
        default:
          break;
      }
    }

    renderer.clear();
    engine.drawMap(renderer, states);
    engine.update();
    renderer.display();
  }
  return 0;
}
