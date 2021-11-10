add_library(hw07 hw07.cpp)

target_include_directories(hw07 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${gtest_SOURCE_DIR}/include")
