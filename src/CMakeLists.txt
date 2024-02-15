file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES} "../include/Screen.h" "Screen.cpp" "../include/Static.h" "../include/GameObject.h" "../include/Moving.h" "../include/Consts.h" "GameObject.cpp" "../include/Mouse.h" "../include/Cat.h")
