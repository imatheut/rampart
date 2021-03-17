#ifndef RAMPART_TERRITORY_MANAGER_H
#define RAMPART_TERRITORY_MANAGER_H


#include "Territory.h"

#include <gf/Vector.h>

namespace rampart {
    class TerritoryManager {
    public:
        void addTerritory(gf::Vector2f castleCoord);

        bool isTerritoryHere(gf::Vector2f coord) const;

        void render(gf::RenderTarget& target, const gf::RenderStates& states);

    private:
        std::vector<Territory> m_territories;

    };
}


#endif // RAMPART_TERRITORY_MANAGER_H



