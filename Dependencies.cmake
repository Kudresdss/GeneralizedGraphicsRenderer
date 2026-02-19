include(FetchContent)

##################################################
##### OpenGL

find_package(OpenGL REQUIRED)

##################################################
##### GLAD

set(GLAD_LIB glad)
set(GLAD_DIR ${DEPENDENCIES_DIR}/glad)

add_library(${GLAD_LIB} STATIC)

target_sources(${GLAD_LIB} PRIVATE ${GLAD_DIR}/src/glad.c)

target_include_directories(${GLAD_LIB} PUBLIC ${GLAD_DIR}/include)

##################################################
##### GLFW
FetchContent_Declare(
	glfw
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG 7b6aead9fb88b3623e3b3725ebb42670cbe4c579 #v3.4
	GIT_PROGRESS TRUE
)

#set(GLFW_BUILD_DOCS OFF)
#set(GLFW_BUILD_TESTS OFF)
#set(GLFW_BUILD_EXAMPLES OFF)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(glfw)
