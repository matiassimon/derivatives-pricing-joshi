add_executable (chapter-03-0
                payoff-2.cpp
                simple-mc-2.cpp
                simple-mc-main-3.cpp
                ${CMAKE_SOURCE_DIR}/chapter-01/random-1.cpp)

add_executable (chapter-03-1
                payoff-2.cpp
                simple-mc-2.cpp
                simple-mc-main-4.cpp
                ${CMAKE_SOURCE_DIR}/chapter-01/random-1.cpp)

add_executable (chapter-03-2
                payoff-2.cpp
                double-digital.cpp
                simple-mc-2.cpp
                simple-mc-main-5.cpp
                ${CMAKE_SOURCE_DIR}/chapter-01/random-1.cpp)

# target_include_directories(chapter-02 PRIVATE ${CMAKE_SOURCE_DIR})