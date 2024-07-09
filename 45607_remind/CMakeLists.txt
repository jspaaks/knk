cmake_minimum_required(VERSION 3.21...3.28)
project(project LANGUAGES C)

list(APPEND CMAKE_INSTALL_RPATH $ORIGIN $ORIGIN/../lib)

add_executable(program)

target_compile_definitions(
    program
    PRIVATE
        $<$<CONFIG:Debug>:DEBUG>
)
target_compile_features(
    program
    PRIVATE
        c_std_23
)
target_compile_options(
    program
    PRIVATE
        -Wall
        -Wextra
        -pedantic
        $<$<CONFIG:Debug>:-g>
        $<$<CONFIG:Debug>:-O0>
        $<$<CONFIG:Release>:-Werror>
)
target_include_directories(
    program
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/include/vstring
)
target_sources(
    program
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/main.c
)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set_property(CACHE CMAKE_INSTALL_PREFIX PROPERTY VALUE "${CMAKE_BINARY_DIR}/dist")
endif()

install(TARGETS program)
