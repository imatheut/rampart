#ifndef RAMPART_MAP_H
#define RAMPART_MAP_H

#include <gf/Entity.h>
#include <gf/ResourceManager.h>
#include <gf/Texture.h>
#include <gf/Vector.h>


namespace rampart {

  class Map : public gf::Entity {
  public:
  
    bool loadTile(const std::string& tileset , const std::vector<std::vector<int>>& tiles);
    bool setPosition(gf::Vector2u position);
    gf::Vector2u getPosition() const;

    //virtual void update(gf::Time time) override;
    virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;

  private:
    
    const int C_TILE_SIZE = 32;
    gf::Texture* m_tileset;
    std::vector<std::vector<int>> m_tiles;
    
    gf::RectF m_rect;
    gf::Vector2u m_position;

  
      

  };

}


#endif // RAMPART_MAP_H