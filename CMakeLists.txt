cmake_minimum_required(VERSION 3.26)

project (derivatives-pricing-joshi
         DESCRIPTION "Exercises and personal notes for the book 'C++ Design Patterns and Derivatives Pricing' by Mark Joshi"
         LANGUAGES CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}) 

add_subdirectory(chapter-01)
add_subdirectory(chapter-02)
add_subdirectory(chapter-03)
add_subdirectory(chapter-04)