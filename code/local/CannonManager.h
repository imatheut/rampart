#ifndef RAMPART_CANNON_MANAGER_H
#define RAMPART_CANNON_MANAGER_H

#include <gf/Vector.h>
#include "Cannon.h"

namespace rampart {
    class CannonManager {
    
    public:
        void addCannon(gf::Vector2f coord);

        void rotateCannons(gf::Vector2f mouseCoord);

        void render(gf::RenderTarget& target, const gf::RenderStates& states);

    private:
        std::vector<Cannon> m_cannons;
    
    };
    
  
    
}


#endif // RAMPART_CANNON_MANAGER_H