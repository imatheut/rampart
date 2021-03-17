#ifndef RAMPART_CANNON_H
#define RAMPART_CANNON_H

#include <gf/Entity.h>
#include <gf/Vector.h>
#include <gf/RenderTarget.h>
#include "TextureLoader.h"
#include <gf/Sprite.h>
namespace rampart {
    class Cannon : public gf::Entity{
    public:
        Cannon(gf::Vector2f coord);


        void rotate(gf::Vector2f mouseCoord);

        virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;


    private:
        TextureLoader m_texture_loader;
        gf::Texture* m_tileset;
        gf::Sprite m_cannon;

        gf::Vector2f m_position;
    
    };
}


#endif // RAMPART_CANNON_H