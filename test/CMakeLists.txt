cmake_minimum_required(VERSION 3.16)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true Test*.cpp)

add_executable(test_${PROJECT_NAME}
    ${SOURCES}
)

target_link_libraries(test_${PROJECT_NAME} gtest_main gmock_main observer)
set_target_properties(test_${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

include(GoogleTest)
gtest_discover_tests(test_${PROJECT_NAME})

if(RUN_TESTS)
    run_tests(run-test_${PROJECT_NAME} test_${PROJECT_NAME})
endif()