#ifndef RAMPART_BULLET_H
#define RAMPART_BULLET_H

#include <gf/Entity.h>
#include <gf/Vector.h>
#include <gf/RenderTarget.h>
#include "TextureLoader.h"
#include <gf/Sprite.h>
namespace rampart {
    class Bullet : public gf::Entity{
    public:
        Bullet(char team, const gf::Vector2f& positionOriginal, const gf::Vector2f& positionTarget); // team c = cannon, s = ship
        bool move(); // return true if the bullet reach the target
     

        virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;


    private:
        TextureLoader m_texture_loader;
        gf::Texture* m_tileset;
        gf::Sprite m_bullet;

        gf::Vector2f m_positionOriginal;
        gf::Vector2f m_positionTarget;
        gf::Vector2f m_direction;

    
    };
}


#endif // RAMPART_BULLET_H