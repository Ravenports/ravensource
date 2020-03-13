cmake_minimum_required(VERSION 3.16)
project(pgplot)
enable_language(Fortran)

SET(CMAKE_SKIP_BUILD_RPATH  TRUE)

add_subdirectory(drivers)
add_subdirectory(pgdispd)
add_subdirectory(fonts)
add_subdirectory(src)
add_subdirectory(sys)
add_subdirectory(examples)

install(FILES rgb.txt DESTINATION share/doc/pgplot)
