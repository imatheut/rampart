#ifndef RAMPART_SHIP_H
#define RAMPART_SHIP_H

#include <gf/Entity.h>
#include <gf/Vector.h>
#include <gf/RenderTarget.h>
#include "TextureLoader.h"
#include <gf/Sprite.h>
namespace rampart {
    class Ship : public gf::Entity{
    public:
        Ship(gf::Vector2f coord);


        virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;


    private:
        TextureLoader m_texture_loader;
        gf::Texture* m_tileset;
        gf::Sprite m_ship;

        gf::Vector2f m_position;
    
    };
}


#endif // RAMPART_SHIP_H