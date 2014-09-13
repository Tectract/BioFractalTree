# BioFractalTree CMake Build system
# see Mozilla Public License 2.0 text file in project for usage terms

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

include_directories(
  main
  bezierDefs
)
add_subdirectory(main)
