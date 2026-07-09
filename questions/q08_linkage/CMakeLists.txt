# Q08 est livrée non-compilable (type incomplet) : exclue du « Build All ».
add_executable(q08_linkage main.cc player.cc team.cc)
set_target_properties(q08_linkage PROPERTIES EXCLUDE_FROM_ALL ON)
target_link_libraries(q08_linkage PRIVATE exam_common)
