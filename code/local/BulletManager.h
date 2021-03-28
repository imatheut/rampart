#ifndef RAMPART_BULLET_MANAGER_H
#define RAMPART_BULLET_MANAGER_H

#include <gf/Entity.h>
#include <gf/Vector.h>
#include <gf/RenderTarget.h>
#include "TextureLoader.h"
#include <gf/Sprite.h>

#include "Bullet.h"

namespace rampart {
    class BulletManager : public gf::Entity{
    public:
        void addBullet(char team, gf::Vector2f positionOriginal, gf::Vector2f positionTarget);

        
        void move();

        virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;


    private:
        std::vector<Bullet> m_bullets;
    
    };
}


#endif // RAMPART_BULLET_MANAGER_H