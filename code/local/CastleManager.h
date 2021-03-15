#ifndef RAMPART_CASTLEMANAGER_H
#define RAMPART_CASTLEMANAGER_H

#include <gf/RenderTarget.h>


#include "Castle.h"

namespace rampart {
    class CastleManager {
    public:
        CastleManager(){}
        void init();
        void placeTheCastle(gf::Vector2f coord);
        gf::Vector2f getCastlePosition() const;

        Castle& getCastle(); 

        virtual void render(gf::RenderTarget& target, const gf::RenderStates& states, size_t frameCount);


    private:
        Castle m_castle;    
    };


}



#endif // RAMPART_CASTLEMANAGER_H