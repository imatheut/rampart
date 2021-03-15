#include "Engine.h"
#include "Dimension.h"
#include <gf/Event.h>

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
            m_territory.addTerritory(m_mapManager.getMap(), m_castleManager.getCastle());
        }
    }




    void Engine::selectCastle(gf::Vector2f cursorPos) {
        if(isCastleSelected) {
            return;
        }

        // Translating cursor position into coordinate x and y    
        gf::Vector2i coord = {(uint16_t)cursorPos.x/C_TILE_DIMENSION, (uint16_t)cursorPos.y/C_TILE_DIMENSION};
        if(m_mapManager.isCastleAt(coord)) {
            m_castleManager.placeTheCastle(coord);
            isCastleSelected = true;
        }       
        
    }


    void Engine::newGame(gf::RenderWindow& window, const gf::RenderStates& states, gf::Vector2i mapSize) {}

    void Engine::update() {
        ++m_frameCount;
    }
}