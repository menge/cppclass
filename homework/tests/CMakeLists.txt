set(SOURCE_FILES driver.cpp
                 tests_hw01.cpp
                 tests_hw02.cpp
   )
set(HW_LIBS hw01
            hw02
   )

add_executable(test_homework ${SOURCE_FILES})
target_link_libraries(test_homework
                      gtest_main
                      ${HW_LIBS}
                     )
add_test(NAME test_hw COMMAND test_homework)
