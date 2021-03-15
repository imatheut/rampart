#ifndef RAMPART_ENGINE_H
#define RAMPART_ENGINE_H

#include <gf/RenderWindow.h>


#include "MapManager.h"
#include "CastleManager.h"
#include "Territory.h"


namespace rampart {
    class Engine {

    public:

        virtual void initGame(gf::Vector2i mapSize);
        void drawMap(gf::RenderWindow& window, const gf::RenderStates& states);
        void update(); // void param for now

        void selectCastle(gf::Vector2f cursorPos);

        void newGame(gf::RenderWindow& window, const gf::RenderStates& states, gf::Vector2i mapSize);




    private:
        MapManager m_mapManager;
        CastleManager m_castleManager;
        Territory m_territory;



        size_t m_frameCount;

   

        bool isCastleSelected = false;

    };
}


#endif // RAMPART_ENGINE_H