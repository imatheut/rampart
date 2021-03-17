#include "CannonManager.h"



namespace rampart {
    void CannonManager::addCannon(gf::Vector2f coord) {
        m_cannons.push_back(Cannon(coord));
    }

    void CannonManager::rotateCannons(gf::Vector2f mouseCoord){

        for(auto &cannon : m_cannons) {
            cannon.rotate(mouseCoord);
        }
        // for(size_t i = 0; i < guns.size(); i++) {
        //     cannon.at(i).setRotation(-atan2(mouse.x - guns.at(i).getPos().x, mouse.y - guns.at(i).getPos().y) * 180 / 3.14159);
        // }
    }


    void CannonManager::render(gf::RenderTarget& target, const gf::RenderStates& states) {
        for(auto &cannon : m_cannons) {
            cannon.render(target, states);
        }
    }
}