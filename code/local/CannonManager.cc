#include "CannonManager.h"



namespace rampart {
    void CannonManager::addCannon(gf::Vector2f coord) {
        if(m_cannons.size() > 2) {
            return;
        }
        m_cannons.push_back(Cannon(coord));
    }

    void CannonManager::rotateCannons(gf::Vector2f mouseCoord){

        for(auto &cannon : m_cannons) {
            cannon.rotate(mouseCoord);
        }
    }


    void CannonManager::shoot(gf::Vector2f mouseCoord) {
        for(auto &cannon : m_cannons) {
            cannon.shoot(mouseCoord);
        }
    }


    size_t CannonManager::getSize() {
        return m_cannons.size();
    }

    void CannonManager::render(gf::RenderTarget& target, const gf::RenderStates& states) {
        for(auto &cannon : m_cannons) {
            cannon.render(target, states);
        }
    }
}