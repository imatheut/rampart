#ifndef RAMPART_ENGINE_H
#define RAMPART_ENGINE_H

#include <gf/RenderWindow.h>
#include <gf/Vector.h>

#include "MapManager.h"
#include "CastleManager.h"
#include "TerritoryManager.h"
#include "WallManager.h"
#include "CannonManager.h"

namespace rampart {
    class Engine {

    public:

        virtual void initGame(gf::Vector2i mapSize);
        void drawMap(gf::RenderWindow& window, const gf::RenderStates& states);
        void update(); 

        void rotateCannons(gf::Vector2f cursorPos); 

        void selectCastle(gf::Vector2f cursorPos);

        void newGame(gf::RenderWindow& window, const gf::RenderStates& states);


        void gameIntro(gf::RenderWindow& window);

        void gameTrasition(gf::RenderWindow& window, const gf::RenderStates& states, const uint8_t& gameState);


    private:
        MapManager m_mapManager;
        CastleManager m_castleManager;
        TerritoryManager m_territoryManager;
        CannonManager m_cannonManager;

        WallManager m_wallManager;

        size_t m_frameCount;

   

        bool isCastleSelected = false;

    };
}


#endif // RAMPART_ENGINE_H