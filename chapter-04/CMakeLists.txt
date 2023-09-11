add_executable (chapter-04-0
                vanilla-1.hpp
                vanilla-1.cpp
                simple-mc-3.hpp
                simple-mc-3.cpp
                vanilla-main-1.cpp
                ${CMAKE_SOURCE_DIR}/chapter-01/random-1.cpp
                ${CMAKE_SOURCE_DIR}/chapter-03/payoff-2.cpp
                ${CMAKE_SOURCE_DIR}/chapter-03/double-digital.cpp)

add_executable (chapter-04-1
                vanilla-2.hpp
                vanilla-2.cpp
                simple-mc-4.hpp
                simple-mc-4.cpp
                vanilla-main-2.cpp
                payoff-3.hpp
                payoff-3.cpp
                ${CMAKE_SOURCE_DIR}/chapter-01/random-1.cpp)

add_executable (chapter-04-2
                vanilla-3.hpp
                vanilla-3.cpp
                simple-mc-5.hpp
                simple-mc-5.cpp
                vanilla-main-3.cpp
                payoff-3.hpp
                payoff-3.cpp
                payoff-bridge.hpp
                payoff-bridge.cpp
                ${CMAKE_SOURCE_DIR}/chapter-01/random-1.cpp)

add_executable (chapter-04-3
                vanilla-3.hpp
                vanilla-3.cpp
                parameters.hpp
                parameters.cpp
                simple-mc-6.hpp
                simple-mc-6.cpp
                vanilla-main-4.cpp
                payoff-3.hpp
                payoff-3.cpp
                payoff-bridge.hpp
                payoff-bridge.cpp
                ${CMAKE_SOURCE_DIR}/chapter-01/random-1.cpp)

# target_include_directories(chapter-02 PRIVATE ${CMAKE_SOURCE_DIR})