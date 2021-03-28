cmake_minimum_required(VERSION 3.10)

project(RAMPART
  VERSION 0.1.0
)

include(GNUInstallDirs)

find_package(gf REQUIRED COMPONENTS graphics)

set(RAMPART_DATA_DIR "${CMAKE_INSTALL_PREFIX}/share/games/rampart")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/code/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h @ONLY)


add_executable(rampart
  code/rampart.cc
  code/local/Map.cc
  code/local/MapManager.cc
  code/local/Castle.cc
  code/local/Engine.cc
  code/local/Singletons.cc
  code/local/TextureLoader.cc
  code/local/CastleManager.cc
  code/local/Wall.cc
  code/local/WallManager.cc
  code/local/Territory.cc
  code/local/TerritoryManager.cc
  code/local/Cannon.cc
  code/local/CannonManager.cc
  code/local/Bullet.cc
  code/local/BulletManager.cc
)

target_include_directories(rampart
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/code
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(rampart
  PRIVATE
    gf::graphics
)

install(
  TARGETS rampart
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

install(
  DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/data/rampart"
  DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/games"
)
