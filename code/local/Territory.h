#ifndef RAMPART_TERRITORY_H
#define RAMPART_TERRITORY_H

#include <gf/RenderTarget.h>
#include <gf/Vector.h>
#include <gf/Texture.h>
#include <gf/Entity.h>


#include "TextureLoader.h"

namespace rampart {
    class Territory : public gf::Entity{

    public:

        Territory(gf::Vector2f coord);
        void setPosition(gf::Vector2f coord);
        
        gf::Vector2f getPosition() const;
        virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;

    private:

        TextureLoader m_texture_loader;
        gf::Texture* m_tileset;
        gf::Vector2f m_position;

    };
}





#endif // RAMPART_TERRITORY_H