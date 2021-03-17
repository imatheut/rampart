#ifndef RAMPART_WALL_MANAGER_H
#define RAMPART_WALL_MANAGER_H

#include <gf/Vector.h>


#include "Wall.h"
namespace rampart {
    class WallManager {
    public:
        void addWall(gf::Vector2f coord);

        void initializeWall(gf::Vector2f coord);

        
        void render(gf::RenderTarget& target, const gf::RenderStates& states);

    private:
        std::vector<Wall> m_walls;

    };
}



#endif // RAMPART_WALL_MANAGER_H





