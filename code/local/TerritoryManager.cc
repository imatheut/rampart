#include "TerritoryManager.h"
#include "Dimension.h"
#include <iostream>
namespace rampart {

    void TerritoryManager::addTerritory(gf::Vector2f castleCoord) {
        // first row
        m_territories.push_back(Territory({castleCoord.x-1, castleCoord.y-1}));
        m_territories.push_back(Territory({castleCoord.x, castleCoord.y-1}));
        m_territories.push_back(Territory({castleCoord.x+1, castleCoord.y-1}));


        // second row
        m_territories.push_back(Territory({castleCoord.x-1, castleCoord.y}));
        m_territories.push_back(Territory({castleCoord.x+1, castleCoord.y}));


        // third row
        m_territories.push_back(Territory({castleCoord.x-1, castleCoord.y+1}));
        m_territories.push_back(Territory({castleCoord.x, castleCoord.y+1}));
        m_territories.push_back(Territory({castleCoord.x+1, castleCoord.y+1}));


    }


    bool TerritoryManager::isTerritoryHere(gf::Vector2f coord) const {
        // Translating coord to position
        gf::Vector2f position = {coord.x*C_TILE_DIMENSION, coord.y * C_TILE_DIMENSION};
        for(auto const &c : m_territories) {
            if(position == c.getPosition()) {
                return true;
            }
        }
     
        
        return false;
    }



    void TerritoryManager::render(gf::RenderTarget& target, const gf::RenderStates& states) {
        for(auto &territory : m_territories) {
            territory.render(target, states);
        }
    }
}