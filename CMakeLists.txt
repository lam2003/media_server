cmake_minimum_required(VERSION 3.17)
project(media_server 
    LANGUAGES CXX)


set(SERVER_VERSION "MediaServer v0.0.1")
set(BUILD_MEDIA_SERVER_WITH_DEBUG true)set(CMAKE_SKIP_BUILD_RPATH TRUE)                 
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)          
set(CMAKE_INSTALL_RPATH "")                       
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)    
set(BUILD_STATIC_LIBS ON)
set(BUILD_SHARED_LIBS OFF)

    # 加入git版本文件
find_package(Git)
execute_process(COMMAND ${GIT_EXECUTABLE} describe --abbrev=6 --dirty --always --tags
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE  GIT_REPO_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(COMMAND ${GIT_EXECUTABLE} log -1 --format=%cd --date=short
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE  GIT_REPO_DATE
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(COMMAND ${GIT_EXECUTABLE} log -1 --format=%H
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE  GIT_REPO_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(COMMAND ${GIT_EXECUTABLE} log -1 --format=%ce
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE  REPO_AUTHOR_EMAIL
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
file(WRITE ${PROJECT_SOURCE_DIR}/src/common/version.h
    "#ifndef MEDIA_SERVER_VERSION_H\n#define MEDIA_SERVER_VERSION_H\n#define SERVER_VERSION \"${SERVER_VERSION}\"\n#define REPO_VERSION \"${GIT_REPO_VERSION}\"\n#define REPO_DATE \"${GIT_REPO_DATE}\"\n#define REPO_HASH \"${GIT_REPO_HASH}\"\n#define REPO_AUTHOR_EMAIL \"${REPO_AUTHOR_EMAIL}\"\n#endif\n"
)

if(BUILD_MEDIA_SERVER_WITH_DEBUG)
    message("################################ build with debug ################################")
    add_definitions(-DMEDIA_SERVER_DEBUG)
    add_compile_options(-g3 -O0)
    add_link_options(-rdynamic)
endif()

add_subdirectory(3rdparty/common_library)
add_subdirectory(src)