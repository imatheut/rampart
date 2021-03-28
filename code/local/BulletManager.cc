#include "BulletManager.h"

#include <iostream>
namespace rampart {
    void BulletManager::addBullet(char team, gf::Vector2f positionOriginal, gf::Vector2f positionTarget) {
        m_bullets.push_back(Bullet('c',positionOriginal, positionTarget));
    }


    void BulletManager::move() {
        for(size_t i = 0; i < m_bullets.size(); ++i) {
            if(m_bullets[i].move()) {
                m_bullets.erase(m_bullets.begin()+i);
                break;
            }
        }
       
    }


    void BulletManager::render(gf::RenderTarget& target, const gf::RenderStates& states) {
        for(auto &bullet : m_bullets) {
            bullet.render(target, states);
        }
        move();
    }


}