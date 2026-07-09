# Vérifie qu'un fichier ne contient plus de const_cast. Usage :
#   cmake -DCHECKED_FILE=<chemin> -P check_no_const_cast.cmake
file(READ "${CHECKED_FILE}" contents)
string(FIND "${contents}" "const_cast" found)
if(NOT found EQUAL -1)
  message(FATAL_ERROR "const_cast encore présent dans ${CHECKED_FILE}")
endif()
