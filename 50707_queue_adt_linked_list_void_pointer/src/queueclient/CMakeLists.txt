set(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR}/../..)

set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
if (APPLE)
    list(APPEND CMAKE_INSTALL_RPATH @loader_path/../lib)
elseif(UNIX)
    list(APPEND CMAKE_INSTALL_RPATH $ORIGIN/../lib)
endif()

add_executable(tgt_exe)

set_property(TARGET tgt_exe PROPERTY OUTPUT_NAME queueclient)

target_compile_definitions(
    tgt_exe
    PRIVATE
        $<$<CONFIG:Debug>:DEBUG>
)

target_compile_features(
    tgt_exe
    PRIVATE
        c_std_23
)

target_compile_options(
    tgt_exe
    PRIVATE
        -Wall
        -Wextra
        -pedantic
        $<$<CONFIG:Debug>:-g>
        $<$<CONFIG:Debug>:-O0>
        $<$<CONFIG:Release>:-Werror>
)

target_include_directories(
    tgt_exe
    PRIVATE
        ${PROJECT_ROOT}/src
)

target_link_libraries(
    tgt_exe
    PRIVATE
        criterion
        tgt_lib_queue
)

target_sources(
    tgt_exe
    PRIVATE
        ${PROJECT_ROOT}/src/queueclient/main.c
)

install(TARGETS tgt_exe)
