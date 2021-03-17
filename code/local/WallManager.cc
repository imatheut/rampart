#include "WallManager.h"


namespace rampart {

    void WallManager::addWall(gf::Vector2f coord) {
        m_walls.push_back(Wall(coord));
    }

     void WallManager::initializeWall(gf::Vector2f castleCoord) {
        // first row
        float coordX = castleCoord.x;
        float coordY = castleCoord.y-2;
        m_walls.push_back(Wall({coordX-2, coordY}));
        m_walls.push_back(Wall({coordX-1, coordY}));
        m_walls.push_back(Wall({coordX,   coordY}));
        m_walls.push_back(Wall({coordX+1, coordY}));
        m_walls.push_back(Wall({coordX+2, coordY}));

    
        // second row
        coordY = castleCoord.y-1;
        m_walls.push_back(Wall({coordX-2, coordY}));
        m_walls.push_back(Wall({coordX+2, coordY}));


        // third row
        coordY = castleCoord.y;
        m_walls.push_back(Wall({coordX-2, coordY}));
        m_walls.push_back(Wall({coordX+2, coordY}));

        // fourth row
        coordY = castleCoord.y+1;
        m_walls.push_back(Wall({coordX-2, coordY}));
        m_walls.push_back(Wall({coordX+2, coordY}));


        //fith/last row 

        coordX = castleCoord.x;
        coordY = castleCoord.y+2;
        m_walls.push_back(Wall({coordX-2, coordY}));
        m_walls.push_back(Wall({coordX-1, coordY}));
        m_walls.push_back(Wall({coordX,   coordY}));
        m_walls.push_back(Wall({coordX+1, coordY}));
        m_walls.push_back(Wall({coordX+2, coordY}));

     }


     void WallManager::render(gf::RenderTarget& target, const gf::RenderStates& states) {
        for(auto &wall : m_walls) {
            wall.render(target, states);
        }
    }
}