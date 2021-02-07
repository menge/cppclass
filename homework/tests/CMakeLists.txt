set(SOURCE_FILES driver.cpp)

add_executable(test_homework ${SOURCE_FILES})
target_link_libraries(test_homework gtest_main)
add_test(NAME test_hw COMMAND test_homework)
