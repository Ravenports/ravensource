cmake_minimum_required(VERSION 3.16)
project(ossp-uuid)

SET(CMAKE_SKIP_BUILD_RPATH  TRUE)

set (libsrcs
	${CMAKE_SOURCE_DIR}/uuid.c
	${CMAKE_SOURCE_DIR}/uuid_md5.c
	${CMAKE_SOURCE_DIR}/uuid_sha1.c
	${CMAKE_SOURCE_DIR}/uuid_prng.c
	${CMAKE_SOURCE_DIR}/uuid_mac.c
	${CMAKE_SOURCE_DIR}/uuid_time.c
	${CMAKE_SOURCE_DIR}/uuid_ui64.c
	${CMAKE_SOURCE_DIR}/uuid_ui128.c
	${CMAKE_SOURCE_DIR}/uuid_str.c
)

set (xxsrcs ${CMAKE_SOURCE_DIR}/uuid++.cc)
set (uuidsrc ${CMAKE_SOURCE_DIR}/uuid_cli.c)

include_directories(
	${CMAKE_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)

add_library(uuid_static ${libsrcs})
add_library(uuidxx_static ${libsrcs} ${xxsrcs})

add_library(uuid SHARED ${libsrcs})
add_library(uuid++ SHARED ${libsrcs} ${xxsrcs})

add_executable(cli_uuid ${uuidsrc})

target_compile_definitions(uuid_static PUBLIC HAVE_CONFIG_H)
target_compile_definitions(uuidxx_static PUBLIC HAVE_CONFIG_H)
target_compile_definitions(uuid PUBLIC DHAVE_CONFIG_H)
target_compile_definitions(uuid++ PUBLIC HAVE_CONFIG_H)
target_compile_definitions(cli_uuid PUBLIC HAVE_CONFIG_H)

set_target_properties(uuid uuid++ PROPERTIES
	VERSION   16.0.22
	SOVERSION 16)

target_link_libraries(cli_uuid uuid_static)

# installation

install(TARGETS uuid uuid++
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/ossp
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libuuidxx_static.a
	RENAME libuuid++.a
	DESTINATION lib/ossp)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libuuid_static.a
	RENAME libuuid.a
	DESTINATION lib/ossp)

install(FILES ${CMAKE_SOURCE_DIR}/uuid.1
	DESTINATION share/man/man1)

install(FILES ${CMAKE_SOURCE_DIR}/uuid-config.1
	DESTINATION share/man/man1)

install(FILES ${CMAKE_SOURCE_DIR}/uuid++.3
	RENAME ossp-uuid++.3
	DESTINATION share/man/man3)

install(FILES ${CMAKE_SOURCE_DIR}/uuid.3
	RENAME ossp-uuid.3
	DESTINATION share/man/man3)

install(FILES ${CMAKE_SOURCE_DIR}/uuid.pc
	RENAME ossp-uuid.pc
	DESTINATION lib/pkgconfig)

install(FILES ${CMAKE_SOURCE_DIR}/uuid++.hh
 	${CMAKE_SOURCE_DIR}/uuid.h
 	DESTINATION include/ossp)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/cli_uuid RENAME uuid DESTINATION bin)
install(PROGRAMS ${CMAKE_SOURCE_DIR}/uuid-config DESTINATION bin)
