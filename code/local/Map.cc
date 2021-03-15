#include "Map.h"
#include "Dimension.h"
#include <gf/Sprite.h>
#include <gf/RenderTarget.h>
#include <gf/Animation.h>
#include <gf/Rect.h>

namespace rampart {

    static constexpr gf::Time FrameTime = gf::milliseconds(50);
    std::vector<std::vector<int>> Map::m_tiles;

    static void loadMultiFrameAnimation(gf::Animation& animation, const gf::Path& path) {
        gf::Texture& texture = gResourceManager().getTexture(path);
        texture.setSmooth();

       
    }
  
    bool Map::loadTile(const std::string& tileset, const std::vector<std::vector<int>>& tiles) {
        m_tileset = m_texture_loader.load(tileset);
        m_tileset_territory = m_texture_loader.load("tileset_territory.png");

        // copying the tiles vector to a new array
        m_tiles = tiles;
    
     

        return true;
    }


    bool Map::setPosition(gf::Vector2u position) {
        this->m_position = position;
        return true;
    }


    void Map::setTile(int i, int j, uint8_t content) {
        m_tiles[i][j] = content;
    }
    
    
    bool Map::isCastleAt(gf::Vector2f coord) {
        return m_tiles[coord.x][coord.y] == 2;
    }

    gf::Vector2u Map::getPosition() const{
        return m_position;
    }
   


    void Map::render(gf::RenderTarget& target, const gf::RenderStates& states) {
        gf::Vector2f rectPos = {0.0f, 0.0f};
        gf::Vector2f rectSize = {0.0f, 0.0f};


        int length = m_tiles.size();
        
        for(int i = 0; i < length; ++i) {
            float yPosIndex = C_TILE_DIMENSION * i; // Indexing each column
            
            
            for(int j = 0; j < m_tiles[i].size(); ++j) {
                gf::Texture* tileset = m_tileset;
                float xPosIndex = C_TILE_DIMENSION * j;
                switch (m_tiles[i][j]){
                case 0: 
                        rectPos = {0.0f, 0.0f};
                        rectSize = {0.5f, 0.5f };
                    break;
                case 1:
                        rectPos = {0.5f, 0.0f};
                        rectSize = { 1.0f, 0.5f};
                    break;

                case 2:
                        rectPos = {0.0f, 0.5f};
                        rectSize = {0.5f, 1.0f};
                    break; 
                case 3: 
                        rectPos = {0.0f, 0.5f};
                        rectSize = {0.5f, 1.0f};

                        tileset = m_tileset_territory;
        
                    break;           
                default:
                    break;
                }


                gf::Sprite sprite;
                sprite.setTexture(*tileset);
                
                sprite.setTextureRect(gf::RectF::fromMinMax(rectPos, rectSize));


                sprite.setPosition({xPosIndex, yPosIndex});
                target.draw(sprite);
         
            }
            
        }
        
    }

}