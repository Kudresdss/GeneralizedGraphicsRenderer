set(SOURCE_DIR Source)
set(SOURCES
	${SOURCE_DIR}/Main.cpp
)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

add_compile_definitions(
	GLFW_INCLUDE_NONE	# prevents GLFW from including OpenGL header inside glfw3.h (used when project has GLAD or similar libs)
)

target_link_libraries(${PROJECT_NAME} Core)

target_include_directories(${PROJECT_NAME} PRIVATE ${SOURCE_DIR})