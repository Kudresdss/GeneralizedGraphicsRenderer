set(SRC
	src/Main.cpp
)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE ${SRC})

add_compile_definitions(
	GLFW_INCLUDE_NONE	# prevents GLFW from including OpenGL header inside glfw3.h (used when project has GLAD or similar libs)
)

target_link_libraries(${PROJECT_NAME} Core)

target_include_directories(${PROJECT_NAME} PRIVATE src)