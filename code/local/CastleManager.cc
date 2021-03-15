#include "CastleManager.h"



namespace rampart {

    void CastleManager::init() {
        m_castle.load("texture_castle.png");
    }

    /**
     *  Select the base castle base on the coord taken from mouse position translated into coord
     **/
    void CastleManager::placeTheCastle(gf::Vector2f coord) {
        m_castle.setPosition(coord);
    }


    gf::Vector2f CastleManager::getCastlePosition() const{
        return m_castle.getPosition();
    }


    Castle& CastleManager::getCastle() {
        return m_castle;
    }

    void CastleManager::render(gf::RenderTarget& target, const gf::RenderStates& states, size_t frameCount) {
        m_castle.render(target,  states);
    }
    
}