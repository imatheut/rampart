#ifndef ENGINE_H
#define ENGINE_H

#include <gf/RenderWindow.h>

#include "MapManager.h"




namespace rampart {
    class Engine {

    public:

        virtual void initGame(gf::Vector2i mapSize);
        void drawMap(gf::RenderWindow& window, const gf::RenderStates& states);
        void update(); // void param for now




    private:

        MapManager m_mapManager;
        size_t m_frameCount;

    };
}


#endif //