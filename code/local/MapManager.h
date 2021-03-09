#ifndef RAMPART_MAPMANAGER_H
#define RAMPART_MAPMANAGER_H


#include <gf/Vector.h>
#include <gf/ResourceManager.h>


#include "Map.h"

namespace rampart {
    class MapManager : public gf::Entity{
       
    public:
        MapManager()
        {
 
        }
        bool generateMap(gf::Vector2u dimension);

        virtual void render(gf::RenderTarget& target, const gf::RenderStates& states, size_t frameCount);


    private:
        Map m_map, m_map2, m_map3;
        gf::Vector2u m_dimension;
        std::vector<std::vector<int>> m_tiles;
    };
    
}





#endif //RAMPART_MAPMANAGER_H