set(SRCS Solution.cpp Solution.h)

add_library(myLib ${SRCS})

target_include_directories(myLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
