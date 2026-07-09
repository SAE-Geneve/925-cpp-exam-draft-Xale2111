# Bibliothèque commune de l'examen — LECTURE SEULE pour les étudiants.
add_library(exam_common STATIC
    counters.cpp
    texture_api.cpp
    gpu_buffer.cpp
)
target_include_directories(exam_common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(exam_common PUBLIC exam_options)
