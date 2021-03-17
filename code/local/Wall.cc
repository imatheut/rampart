#include "Wall.h"
#include "Dimension.h"
#include <gf/Sprite.h>


namespace rampart {

    Wall::Wall(gf::Vector2f coord) {
        m_tileset = m_texture_loader.load("texture_wall.png");

        // Translatting the coord into the real pixel posisiton
        m_position = {coord.x * C_TILE_DIMENSION, coord.y * C_TILE_DIMENSION};
    }

    void Wall::placeWall(gf::Vector2f coord) {
        m_position = {coord.x * C_TILE_DIMENSION, coord.y * C_TILE_DIMENSION};
    }



    void Wall::render(gf::RenderTarget& target, const gf::RenderStates& states) {
        gf::Sprite sprite;
        sprite.setTexture(*m_tileset);

        sprite.setPosition(m_position);
        target.draw(sprite);
    }
}