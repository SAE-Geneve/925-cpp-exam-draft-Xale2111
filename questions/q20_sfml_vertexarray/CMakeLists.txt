# Q20 est la SEULE cible qui linke SFML.
find_package(SFML COMPONENTS Graphics Window System CONFIG REQUIRED)
add_executable(q20_sfml_vertexarray main.cpp grid_vertices.cpp)
target_link_libraries(q20_sfml_vertexarray PRIVATE exam_common SFML::Graphics SFML::Window SFML::System)