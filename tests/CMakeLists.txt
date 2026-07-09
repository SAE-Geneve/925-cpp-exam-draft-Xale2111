# Tests de l'examen — NE PAS MODIFIER (les étudiants ne touchent pas à ce dossier).
find_package(GTest CONFIG REQUIRED)

# Déclare la cible de test d'une question : add_question_test(q05_lambdas [SOURCES ...] [LIBS ...])
# La cible s'appelle <question>_test, compile tests/<question>_test.cpp et est enregistrée
# dans ctest sous le nom <question>.
function(add_question_test question)
  cmake_parse_arguments(ARG "EXCLUDE_FROM_ALL" "" "SOURCES;LIBS" ${ARGN})
  set(target ${question}_test)
  add_executable(${target} ${question}_test.cpp ${ARG_SOURCES})
  if(ARG_EXCLUDE_FROM_ALL)
    set_target_properties(${target} PROPERTIES EXCLUDE_FROM_ALL ON)
  endif()
  target_link_libraries(${target} PRIVATE exam_common GTest::gtest GTest::gtest_main ${ARG_LIBS})
  target_include_directories(${target} PRIVATE "${CMAKE_SOURCE_DIR}/questions")
  if(NOT ARG_EXCLUDE_FROM_ALL)
    add_test(NAME ${question} COMMAND ${target})
  endif()
endfunction()

# Test de compilation NÉGATIF : vérifie qu'un extrait NE compile PAS.
# add_negative_compile_test(q02_vec2_no_normalized_int fichier.cpp)
# Le fichier est compilé à la volée par ctest ; le test passe si la compilation échoue.
function(add_negative_compile_test name source)
  add_test(NAME ${name}
           COMMAND ${CMAKE_COMMAND}
                   --build "${CMAKE_BINARY_DIR}"
                   --target ${name}_target)
  add_library(${name}_target OBJECT EXCLUDE_FROM_ALL "${CMAKE_CURRENT_SOURCE_DIR}/${source}")
  target_link_libraries(${name}_target PRIVATE exam_common)
  target_include_directories(${name}_target PRIVATE "${CMAKE_SOURCE_DIR}/questions")
  set_tests_properties(${name} PROPERTIES WILL_FAIL ON)
endfunction()

# Cibles de test, dans l'ordre alphabétique des questions.
# Q01 et Q08 : livrées non-compilables/non-linkables => tests EXCLUDE_FROM_ALL
# (hors « Build All » et hors ctest) ; l'échec de build = échec de la question.
add_question_test(q02_vec2)
add_negative_compile_test(q02_vec2_no_normalized_int q02_normalized_int_negative.cpp)
add_question_test(q04_ranges)
add_question_test(q06_const)
add_question_test(q08_linkage EXCLUDE_FROM_ALL
    SOURCES ${CMAKE_SOURCE_DIR}/questions/q08_linkage/team.cc
            ${CMAKE_SOURCE_DIR}/questions/q08_linkage/player.cc)

# Q20 : seule cible de test qui linke SFML (mais ne crée aucune fenêtre).
find_package(SFML COMPONENTS Graphics Window System CONFIG REQUIRED)
add_question_test(q20_sfml_vertexarray
    SOURCES ${CMAKE_SOURCE_DIR}/questions/q20_sfml_vertexarray/grid_vertices.cpp
    LIBS SFML::Graphics SFML::Window SFML::System)
