#include "TextureLoader.h"


namespace rampart {
    gf::Texture* TextureLoader::load(const std::string& tileset) {
        gf::Texture& texture = gResourceManager().getTexture(tileset);
        texture.setSmooth();
        return &texture;
    }
}