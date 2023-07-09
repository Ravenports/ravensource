cmake_minimum_required(VERSION 3.16)
project(ossp-uuid)

SET(CMAKE_SKIP_BUILD_RPATH  TRUE)

set (xxsrcs
	${CMAKE_SOURCE_DIR}/tinystr.cpp
	${CMAKE_SOURCE_DIR}/tinyxmlerror.cpp
	${CMAKE_SOURCE_DIR}/tinyxml.cpp
	${CMAKE_SOURCE_DIR}/tinyxmlparser.cpp
)

include_directories(
	${CMAKE_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)

add_library(tinyxml_static ${xxsrcs})
add_library(tinyxml SHARED ${xxsrcs})

set_target_properties(tinyxml PROPERTIES
	VERSION   3.0.0
	SOVERSION 3)

install(TARGETS tinyxml
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libtinyxml_static.a
	RENAME libtinyxml.a
	DESTINATION lib)

install(FILES
	${CMAKE_SOURCE_DIR}/tinystr.h
 	${CMAKE_SOURCE_DIR}/tinyxml.h
 	DESTINATION include
)
