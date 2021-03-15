#ifndef RAMPART_CASTLE_H
#define RAMPART_CASTLE_H

#include <gf/Entity.h>
#include <gf/ResourceManager.h>
#include <gf/Texture.h>


#include "TextureLoader.h"

namespace rampart {
    class Castle : public gf::Entity {

    public:
        Castle();
        void load(const std::string& tileName);

        void setPosition(gf::Vector2f position);
        virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;
        gf::Vector2f getPosition() const;

     
    private:
        TextureLoader m_texture_loader;;
        gf::Texture* m_tileset;
        gf::Vector2f m_position; //Actual position in hte screen

    };
}


#endif // RAMPART_CASTLE_H