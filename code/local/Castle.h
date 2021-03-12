#ifndef RAMPART_CASTLE_H
#define RAMPART_CASTLE_H

#include <gf/RenderWindow.h>




namespace rampart {
    class Castle {

    public:
        Castle();

        void setPosition(gf::Vector2f position);

        gf::Vector2f getPosition();

     
    private:

        gf::Vector2f m_position;

    };
}


#endif // RAMPART_CASTLE_H