cmake_minimum_required(VERSION 3.28)
project(cpp_exam_925_draft LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options de compilation communes à toutes les cibles de l'examen.
# /W4 volontairement sans /WX : certains warnings font partie de la pédagogie.
add_library(exam_options INTERFACE)
if(MSVC)
  target_compile_options(exam_options INTERFACE /W4 /permissive- /Zc:__cplusplus /utf-8)
else()
  target_compile_options(exam_options INTERFACE -Wall -Wextra)
endif()

enable_testing()

add_subdirectory(common)

# Une cible exécutable <qNN_sujet> par question, chacune dans son dossier.
# Liste explicite, dans l'ordre alphabétique (= ordre des cibles dans l'IDE).
add_subdirectory(questions/q02_vec2)
add_subdirectory(questions/q04_ranges)
add_subdirectory(questions/q06_const)
add_subdirectory(questions/q08_linkage)
add_subdirectory(questions/q20_sfml_vertexarray)

add_subdirectory(tests)
