#include "Bullet.h"
#include "Dimension.h"

#include <gf/Clock.h>
#include <iostream>

namespace rampart {
    Bullet::Bullet(char team, const gf::Vector2f& positionOriginal, const gf::Vector2f& positionTarget) {
        m_tileset = m_texture_loader.load("texture_bullet.png");
        m_bullet.setTexture(*m_tileset);

        m_positionOriginal = positionOriginal;
        m_positionTarget = positionTarget * C_TILE_DIMENSION; // converting back to pixel
    }



    bool Bullet::move() {
        gf::Vector2f direction;

        direction = m_positionTarget - m_positionOriginal;
        m_positionOriginal += direction * 0.008;
        m_bullet.setScale({0.9, 0.9});
        m_bullet.rotate(1);

        // since target's position and bullet's position are floating point we have to convert it to int
        // to ignore the small difference between those two vectors
        return static_cast<gf::Vector2i>(m_positionTarget) == static_cast<gf::Vector2i>(m_positionOriginal+1);

    }

    void Bullet::render(gf::RenderTarget& target, const gf::RenderStates& states){
        m_bullet.setAnchor(gf::Anchor::Center);
        m_bullet.setPosition(m_positionOriginal + C_TILE_DIMENSION/2);    
        move();    
        target.draw(m_bullet);
    }
}