cmake_minimum_required(VERSION 2.6)
project(grocking)

set(APP_NAME grocking)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)
#set( CMAKE_BUILD_TYPE RELEASE )
set(CMAKE_BUILD_TYPE DEBUG)

set(GAME_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src SRC)

set(LIBS)

add_executable(${APP_NAME} ${SRC})

target_link_libraries(${APP_NAME}
        ${LIBS})

if (WIN32) #disable console mode for VC++
    set_target_properties(${APP_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif (WIN32)

