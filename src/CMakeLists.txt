set(_src_root_path ${CMAKE_CURRENT_SOURCE_DIR})
file(
    GLOB_RECURSE source_files
    LIST_DIRECTORIES false
    "${_src_root_path}/*.cpp"
)

add_executable(${CMAKE_PROJECT_NAME} ${source_files})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/3rdparty/common_library)
target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_11)
target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -Wall)

target_link_libraries(${CMAKE_PROJECT_NAME} 
    lmcomm 
    pthread
)
