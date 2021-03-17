#include "Engine.h"
#include "Dimension.h"
#include <gf/Event.h>
#include <gf/Text.h>
#include <gf/Texture.h>
#include <gf/Sprite.h>

#include <iostream>
namespace rampart {


    void Engine::initGame(gf::Vector2i mapSize) {
        m_mapManager.generateMap();
        m_castleManager.init();
        m_frameCount = 0;
    }   

    void Engine::drawMap(gf::RenderWindow& window, const gf::RenderStates& states) {
        m_mapManager.render(window, states, m_frameCount);
        if(isCastleSelected) {
            m_castleManager.render(window, states, m_frameCount);
            m_territoryManager.render(window, states);
            m_wallManager.render(window,states);
            m_cannonManager.render(window, states);
        }
    }




    void Engine::selectCastle(gf::Vector2f cursorPos) {
        // Translating cursor position into coordinate x and y    
        gf::Vector2i coord = {(uint16_t)cursorPos.x/C_TILE_DIMENSION, (uint16_t)cursorPos.y/C_TILE_DIMENSION};
        if(isCastleSelected) {
            // check if in the territory' zone
            if(m_territoryManager.isTerritoryHere(coord)) {
                m_cannonManager.addCannon(coord);
            }
            return;
        }

        
        if(m_mapManager.isCastleAt(coord)) {
            m_castleManager.placeTheCastle(coord);
            m_territoryManager.addTerritory(coord);
            m_wallManager.initializeWall(coord);
            isCastleSelected = true;
        }       
        
    }


    void Engine::newGame(gf::RenderWindow& window, const gf::RenderStates& states) {}

    void Engine::gameIntro(gf::RenderWindow& window) {
        gf::Text titleGame;
    
        titleGame.setString("RAMPART");
     
        
    }



    void Engine::gameTrasition(gf::RenderWindow& window, const gf::RenderStates& states, const uint8_t& gameState) {
        switch(gameState) {
        case 1:
            // Game intro
            break;
        case 2:
            // Select castle
            break;
        case 3:
            break;        
        
        default:
            break;
        }
    }
    

    void Engine::rotateCannons(gf::Vector2f cursorPos) {
        m_cannonManager.rotateCannons(cursorPos);
    }

    void Engine::update() {
        ++m_frameCount;
    }
}