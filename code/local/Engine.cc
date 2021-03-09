#include "Engine.h"


namespace rampart {


    void Engine::initGame(gf::Vector2i mapSize) {
        m_mapManager.generateMap({12,12});
        m_frameCount = 0;
    }   

    void Engine::drawMap(gf::RenderWindow& window, const gf::RenderStates& states) {
        m_mapManager.render(window, states, m_frameCount);
    }

    void Engine::update() {
        ++m_frameCount;
    }
}