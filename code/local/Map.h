#ifndef RAMPART_MAP_H
#define RAMPART_MAP_H

#include <gf/Entity.h>
#include <gf/ResourceManager.h>
#include <gf/Texture.h>
#include <gf/Vector.h>

#include "TextureLoader.h"
namespace rampart {

  class Map : public gf::Entity {
  public:
  
    bool loadTile(const std::string& tileset , const std::vector<std::vector<int>>& tiles);
    bool setPosition(gf::Vector2u position);
    gf::Vector2u getPosition() const;

    // Change the content of the tile at i j index position 
    // content : 0 = water, 1 = ground, 2 = castle, ...
    void setTile(int i, int j, uint8_t content);

    bool isCastleAt(gf::Vector2f coord);
    
    //virtual void update(gf::Time time) override;
    virtual void render(gf::RenderTarget& target, const gf::RenderStates& states) override;
     

  private:
    TextureLoader m_texture_loader;
    gf::Texture* m_tileset;
    gf::Texture* m_tileset_territory;
    static std::vector<std::vector<int>> m_tiles;
    
    gf::RectF m_rect;
    gf::Vector2u m_position;

  
   

  };

}


#endif // RAMPART_MAP_H