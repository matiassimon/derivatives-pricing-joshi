add_executable (chapter-02
                payoff-1.cpp
                simple-mc.cpp
                simple-mc-main-2.cpp
                ${CMAKE_SOURCE_DIR}/chapter-01/random-1.cpp)

# target_include_directories(chapter-02 PRIVATE ${CMAKE_SOURCE_DIR})