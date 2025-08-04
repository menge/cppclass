set(SOURCE_FILES driver.cpp
                 tests_hw01.cpp
                 tests_hw02.cpp
                 tests_hw03.cpp
                 tests_hw04.cpp
                 tests_hw05.cpp
                 tests_hw06.cpp
                 tests_hw07.cpp
                 tests_hw08.cpp
                 tests_hw09.cpp
   )
set(HW_LIBS hw01
            hw02
            hw03
            hw04
            hw05
            hw06
            hw07
            hw08
            hw09
   )

add_executable(test_homework ${SOURCE_FILES})
target_link_libraries(test_homework
                      gtest_main
                      ${HW_LIBS}
                     )
add_test(NAME test_hw COMMAND test_homework)
