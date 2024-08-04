set(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR}/../..)

set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
if (APPLE)
    list(APPEND CMAKE_INSTALL_RPATH @loader_path/../lib)
elseif(UNIX)
    list(APPEND CMAKE_INSTALL_RPATH $ORIGIN/../lib)
endif()

add_executable(tgt_exe_test_queue)

set_property(TARGET tgt_exe_test_queue PROPERTY OUTPUT_NAME test_queue)

target_compile_definitions(
    tgt_exe_test_queue
    PRIVATE
        $<$<CONFIG:Debug>:DEBUG>
)

target_compile_features(
    tgt_exe_test_queue
    PRIVATE
        c_std_23
)

target_compile_options(
    tgt_exe_test_queue
    PRIVATE
        -Wall
        -Wextra
        -pedantic
        $<$<CONFIG:Debug>:-g>
        $<$<CONFIG:Debug>:-O0>
        $<$<CONFIG:Release>:-Werror>
)

target_include_directories(
    tgt_exe_test_queue
    PRIVATE
        ${PROJECT_ROOT}/src
)

target_link_libraries(
    tgt_exe_test_queue
    PRIVATE
        criterion
        tgt_lib_queue
)

target_sources(
    tgt_exe_test_queue
    PRIVATE
        ${PROJECT_ROOT}/test/queue/test_queue__create.c
        ${PROJECT_ROOT}/test/queue/test_queue__destroy.c
        ${PROJECT_ROOT}/test/queue/test_queue__get_capacity.c
        ${PROJECT_ROOT}/test/queue/test_queue__get_length.c
        ${PROJECT_ROOT}/test/queue/test_queue__isempty.c
        ${PROJECT_ROOT}/test/queue/test_queue__isfull.c
        ${PROJECT_ROOT}/test/queue/test_queue__join.c
        ${PROJECT_ROOT}/test/queue/test_queue__pop.c
)

install(TARGETS tgt_exe_test_queue)
