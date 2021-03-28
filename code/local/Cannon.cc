#include "Cannon.h"
#include "Dimension.h"


namespace rampart {

    Cannon::Cannon(gf::Vector2f coord) {
        m_tileset = m_texture_loader.load("texture_cannon.png");
        m_cannon.setTexture(*m_tileset);
        m_position = {coord.x * C_TILE_DIMENSION, coord.y * C_TILE_DIMENSION};
    }

    void Cannon::rotate(gf::Vector2f mouseCoord) {
        m_cannon.setRotation(-atan2(mouseCoord.x - m_cannon.getPosition().x, mouseCoord.y - m_cannon.getPosition().y) + (180-2) / 3.14159);
    }


    void Cannon::shoot(gf::Vector2f mouseCoord) {
        m_bulletManager.addBullet('c',m_position, mouseCoord);

    }    


    void Cannon::render(gf::RenderTarget& target, const gf::RenderStates& states) {
        m_cannon.setAnchor(gf::Anchor::Center);
        m_cannon.setPosition(m_position + C_TILE_DIMENSION/2);
        target.draw(m_cannon);
        m_bulletManager.render(target, states);
    }

}