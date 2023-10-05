add_executable (chapter-05-0
                simple-mc-7.hpp
                simple-mc-7.cpp
                mc-statistics.hpp
                mc-statistics.cpp
                stats-main-1.cpp
                ${CMAKE_SOURCE_DIR}/chapter-01/random-1.cpp
                ${CMAKE_SOURCE_DIR}/chapter-04/payoff-3.cpp
                ${CMAKE_SOURCE_DIR}/chapter-04/payoff-bridge.cpp
                ${CMAKE_SOURCE_DIR}/chapter-04/vanilla-3.cpp
                ${CMAKE_SOURCE_DIR}/chapter-04/parameters.cpp)

add_executable (chapter-05-1
                simple-mc-7.hpp
                simple-mc-7.cpp
                mc-statistics.hpp
                mc-statistics.cpp
                convergence-table.hpp
                convergence-table.cpp
                stats-main-2.cpp
                ${CMAKE_SOURCE_DIR}/chapter-01/random-1.cpp
                ${CMAKE_SOURCE_DIR}/chapter-04/payoff-3.cpp
                ${CMAKE_SOURCE_DIR}/chapter-04/payoff-bridge.cpp
                ${CMAKE_SOURCE_DIR}/chapter-04/vanilla-3.cpp
                ${CMAKE_SOURCE_DIR}/chapter-04/parameters.cpp)
