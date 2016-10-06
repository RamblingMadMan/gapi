find_package(OpenGL)

if(UNIX)
set(MOVE_SCRIPT ./move.sh)
elseif(WIN32)
set(MOVE_SCRIPT move.bat)
endif()

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_LIST_DIR}/functions.cpp
	COMMAND spec_parser
	COMMAND ${MOVE_SCRIPT}
	WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../spec_parser
)

add_library(
	gapi SHARED
	context.cpp
	functions.cpp
)

target_link_libraries(gapi ${OPENGL_LIBRARIES})
