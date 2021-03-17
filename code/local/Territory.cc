#include "Territory.h"
#include "Dimension.h"
#include <iostream>

#include <gf/Sprite.h>
namespace rampart {


    Territory::Territory(gf::Vector2f coord) {
        m_tileset = m_texture_loader.load("tileset_territory.png");
        m_position = {coord.x * C_TILE_DIMENSION, coord.y * C_TILE_DIMENSION};
    }


    void Territory::setPosition(gf::Vector2f coord) {
        m_position = {coord.x * C_TILE_DIMENSION, coord.y * C_TILE_DIMENSION};
    }

    gf::Vector2f Territory::getPosition() const {
        return m_position;
    }    


    void Territory::render(gf::RenderTarget& target, const gf::RenderStates& states) {
        gf::Sprite sprite;
        sprite.setTexture(*m_tileset);

        sprite.setTextureRect(gf::RectF::fromMinMax({0.f, 0.5f}, {0.5f,1.f}));


        sprite.setPosition(m_position);
        target.draw(sprite);
    }
}