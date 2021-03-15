#ifndef RAMPART_TEXTURELOADER_H
#define RAMPART_TEXTURELOADER_H

#include <gf/Texture.h>
#include <string>


#include "Singletons.h"

namespace rampart {

    class TextureLoader {
        public:
        gf::Texture *load(const std::string& tileset);
    };
}



#endif // RAMPART_TEXTURELOADER_H