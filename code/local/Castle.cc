#include "Castle.h"
#include "Dimension.h"

#include <gf/Sprite.h>
#include <gf/RenderTarget.h>
#include <iostream>
namespace rampart {
    Castle::Castle() {

    }

    void Castle::load(const std::string& tileName) {
        m_tileset = m_texture_loader.load(tileName);
    }

    // array indexing coord ex: 1,1 
    void Castle::setPosition(gf::Vector2f coord) {
        // Translating the coordinate given into the real position in pixel
        m_position.x = coord.x * C_TILE_DIMENSION;
        m_position.y = coord.y * C_TILE_DIMENSION;
    }

    gf::Vector2f Castle::getPosition() const{
        return m_position;
    }


    void Castle::render(gf::RenderTarget& target, const gf::RenderStates& states) {
        gf::Sprite sprite;
        sprite.setTexture(*m_tileset);
     
        sprite.setPosition(m_position);
        target.draw(sprite);
    }



    
    
}