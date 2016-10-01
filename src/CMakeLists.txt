find_package(OpenGL)

add_custom_command(
	OUTPUT ${CMAKE_SOURCE_DIR}/src/functions.cpp
	COMMAND ${CMAKE_SOURCE_DIR}/spec_parser/compile.sh
	COMMAND ${CMAKE_SOURCE_DIR}/spec_parser/replace.sh
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/spec_parser
)

add_library(
	gapi SHARED
	context.cpp
	functions.cpp
)

target_include_directories(gapi PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(gapi ${OPENGL_LIBRARIES})
