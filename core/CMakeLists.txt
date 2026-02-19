set(CORE_LIB Core)

set(SRC
	src/Core.cpp
	src/Core.h
)

# set(DEPENDENCIES_DIR ${PROJECT_SOURCE_DIR}/dependencies)
# set(GLAD_DIR ${DEPENDENCIES_DIR}/glad)

add_library(${CORE_LIB} STATIC)

target_sources(${CORE_LIB} PRIVATE
	${SRC}
	# ${GLAD_DIR}/src/glad.c
)

add_compile_definitions(
	GLFW_INCLUDE_NONE	# prevents GLFW from including OpenGL header inside glfw3.h (used when project has GLAD or similar libs)
)

target_link_libraries(${CORE_LIB} OpenGL::GL)
target_link_libraries(${CORE_LIB} glad)
target_link_libraries(${CORE_LIB} glfw)
# target_link_libraries(${CORE_LIB} ${DEPENDENCIES_DIR}/glad)

target_include_directories(${CORE_LIB} PUBLIC src ${GLAD_DIR}/include)
# target_include_directories(${CORE_LIB} src ${DEPENDENCIES_DIR} ${GLAD_DIR}/include)
