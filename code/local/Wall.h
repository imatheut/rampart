#ifndef RAMPART_WALL_H
#define RAMPART_WALL_H

#include <gf/Entity.h>
#include <gf/Vector.h>
#include <gf/RenderTarget.h>
#include "TextureLoader.h"
#include "Map.h"

namespace rampart {
    class Wall : public gf::Entity {
    public:

        Wall(gf::Vector2f coord);
        
        void placeWall(gf::Vector2f coord); // set wall position

        gf::Vector2f getPosition();



        virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;


    private:    
        TextureLoader m_texture_loader;
        gf::Texture* m_tileset;

        gf::Vector2f m_position;

    };
}



#endif // RAMPART_WALL_H