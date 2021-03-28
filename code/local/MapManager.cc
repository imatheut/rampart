#include "MapManager.h"
#include <gf/RenderTarget.h>

#include <iostream>
namespace rampart {
   

    bool MapManager::generateMap() {
        std::vector<std::vector<int>> tiles {
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
			{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
			{0,0,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
			{0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,0,0,0,0,0,0,0},
			{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
			{0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0},
			{0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
			{0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
			{0,0,0,0,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        };

        // Assigning the map structure
        m_tiles = tiles;



        m_map.loadTile("tileset1.png", m_tiles);        
        m_map2.loadTile("tileset2.png", m_tiles);  
        m_map3.loadTile("tileset3.png", m_tiles);  

       

        return false;
    }

    // getting the coord from the mousepressed position translated into coord
    bool MapManager::isCastleAt(gf::Vector2f coord) {
        bool ok = false;
        try {
            ok = m_tiles[coord.y][coord.x] == 2;
        }
        catch(const std::out_of_range& e) {
            std::cout << "Exception out of range occurred ..." << std::endl;
        }
        return ok;;
    }


    Map& MapManager::getMap() {
        return m_map;
    }

    void MapManager::render(gf::RenderTarget& target, const gf::RenderStates& states, size_t frameCount) {
        if(frameCount %100 < 30) {
            m_map.render(target, states);
        }
        else if(frameCount %100 >= 30 && frameCount % 100 < 45 || frameCount % 100 >= 60) {
            m_map2.render(target, states);
        }
        else if(frameCount % 100 >= 45 && frameCount % 100 < 60) {
            m_map3.render(target, states);
        }
        
    }

}
