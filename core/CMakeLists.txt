set(CORE_LIB Core)

set(SOURCE_DIR Source)
set(SOURCES
	${SOURCE_DIR}/Core.cpp
	${SOURCE_DIR}/Application.cpp
	${SOURCE_DIR}/Window.cpp
)

set(UTILS_DIR Utils)

add_library(${CORE_LIB} STATIC)

target_sources(${CORE_LIB} PRIVATE
	${SOURCES}
)

add_compile_definitions(
	GLFW_INCLUDE_NONE	# prevents GLFW from including OpenGL header inside glfw3.h (used when project has GLAD or similar libs)
)

target_link_libraries(${CORE_LIB} OpenGL::GL)
target_link_libraries(${CORE_LIB} glad)
target_link_libraries(${CORE_LIB} glfw)

target_include_directories(${CORE_LIB} PUBLIC ${SOURCE_DIR} ${UTILS_DIR} ${GLAD_DIR}/include)
