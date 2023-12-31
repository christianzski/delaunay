find_package(Catch2 3 REQUIRED)

add_executable(tests test.cpp)

target_link_libraries(tests PRIVATE delaunay Catch2::Catch2WithMain)
