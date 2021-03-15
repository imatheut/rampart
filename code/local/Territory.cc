#include "Territory.h"
#include "Dimension.h"
#include <iostream>

namespace rampart {

    void Territory::addTerritory(Map& map, Castle& castle) {
        gf::Vector2f castlePostion = castle.getPosition();

        // first row
        map.setTile(castlePostion.y/C_TILE_DIMENSION-1, castlePostion.x/C_TILE_DIMENSION-1, 3);
        map.setTile(castlePostion.y/C_TILE_DIMENSION-1, castlePostion.x/C_TILE_DIMENSION, 3);
        map.setTile(castlePostion.y/C_TILE_DIMENSION-1, castlePostion.x/C_TILE_DIMENSION+1, 3);
        // Second row
        map.setTile(castlePostion.y/C_TILE_DIMENSION, castlePostion.x/C_TILE_DIMENSION-1, 3);
        map.setTile(castlePostion.y/C_TILE_DIMENSION, castlePostion.x/C_TILE_DIMENSION+1, 3);
        // third row
        map.setTile(castlePostion.y/C_TILE_DIMENSION+1, castlePostion.x/C_TILE_DIMENSION-1, 3);
        map.setTile(castlePostion.y/C_TILE_DIMENSION+1, castlePostion.x/C_TILE_DIMENSION, 3);
        map.setTile(castlePostion.y/C_TILE_DIMENSION+1, castlePostion.x/C_TILE_DIMENSION+1, 3);


    }
}