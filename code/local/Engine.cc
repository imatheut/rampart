#include "Engine.h"
#include "Dimension.h"
#include <gf/Event.h>
#include <gf/Text.h>
#include <gf/Texture.h>
#include <gf/Sprite.h>
#include <gf/Font.h>
#include <gf/Sleep.h>
#include <gf/Time.h>
#include <iostream>
namespace rampart {


    void Engine::initGame() {
        m_mapManager.generateMap();
        m_castleManager.init();
        m_frameCount = 0;
    }   

    void Engine::draw(gf::RenderWindow& window, const gf::RenderStates& states) {
        m_mapManager.render(window, states, m_frameCount);
        if(isCastleSelected) {
            m_castleManager.render(window, states, m_frameCount);
            m_territoryManager.render(window, states);
            m_wallManager.render(window,states);
            m_cannonManager.render(window, states);
        }
    }

    void Engine::shoot(gf::Vector2f cursorPos) {
        gf::Vector2i coord = {(uint16_t)cursorPos.x/C_TILE_DIMENSION, (uint16_t)cursorPos.y/C_TILE_DIMENSION};
        if(m_canShoot) {
            m_cannonManager.shoot(coord);
        }
        if(m_cannonManager.getSize() == 3) {
            m_canShoot = true;
        }
    }


   

    void Engine::selectCastle(gf::Vector2f cursorPos) {
        // Translating cursor position into coordinate x and y    
        gf::Vector2i coord = {(uint16_t)cursorPos.x/C_TILE_DIMENSION, (uint16_t)cursorPos.y/C_TILE_DIMENSION};
        if(isCastleSelected) {
            // check if in the territory' zone
            if(m_territoryManager.isTerritoryHere(coord)) {
                m_cannonManager.addCannon(coord);
            }
            return;
        }

        
        if(m_mapManager.isCastleAt(coord)) {
            m_castleManager.placeTheCastle(coord);
            m_territoryManager.addTerritory(coord);
            m_wallManager.initializeWall(coord);
            isCastleSelected = true;
        }       
        
    }


    void Engine::newGame(gf::RenderWindow& window, const gf::RenderStates& states) {}



    void Engine::gameIntro(gf::RenderWindow& window) {

        // title
        gf::Font& titleFont = gResourceManager().getFont("bones.ttf");
        gf::Text titleGame("%RAMPART%", titleFont, 100);
        titleGame.setColor(gf::Color::Black);
        titleGame.setPosition({ 100, 100 });


        // powered by
        gf::Font& poweredFont = gResourceManager().getFont("blkchcry.ttf");
        gf::Text powered("Powered by", poweredFont, 50);
        powered.setPosition({100, 480});

        // logos gf
        gf::Sprite logo_gf(*m_texture_loader.load("gf_logo.png"));
        logo_gf.setScale({0.5f, 0.5f});
        logo_gf.setPosition({500,500});
        // logos cpp
        gf::Sprite logo_cpp(*m_texture_loader.load("cpp_logo.png"));
        logo_cpp.setScale({0.1f, 0.1f});
        logo_cpp.setPosition({400,500});


     
        window.clear(gf::Color::White);
        window.draw(titleGame);
        window.draw(powered);
        window.draw(logo_cpp);
        window.draw(logo_gf);
        window.display();


        gf::sleep(gf::milliseconds(3000));

        
    }



    void Engine::gameTrasition(gf::RenderWindow& window, const gf::RenderStates& states, const uint8_t& gameState) {
        switch(gameState) {
        case 1: 
            break;
        case 2:
            break;
        case 3:
            break;        
        
        default:
            break;
        }
    }
    

    void Engine::rotateCannons(gf::Vector2f cursorPos) {
        m_cannonManager.rotateCannons(cursorPos);
    }

    void Engine::update() {
        ++m_frameCount;
    }
}