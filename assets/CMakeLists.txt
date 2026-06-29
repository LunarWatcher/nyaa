set(ASSETS
    tilesets/tiles.png
    tilesets/tiles.json

    creatures/creatures.png
    creatures/creatures.json

    fonts/Licenses.md
    fonts/dejavu.ttf

    splash.png
)
foreach(ASSET IN LISTS ASSETS)
    message(STATUS "Copying ${ASSET}")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${ASSET} ${CMAKE_BINARY_DIR}/assets/${ASSET} COPYONLY)
endforeach()
