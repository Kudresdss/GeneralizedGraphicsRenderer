# CMakeList.txt : CMake project for GeneralizedGraphicsRenderer, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("GeneralizedGraphicsRenderer")


find_package(OpenGL REQUIRED)

include(FetchContent)
FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG master)

#set(GLFW_BUILD_DOCS OFF)
#set(GLFW_BUILD_TESTS OFF)
#set(GLFW_BUILD_EXAMPLES OFF)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# Add source to this project's executable.
add_executable (GeneralizedGraphicsRenderer "GeneralizedGraphicsRenderer.cpp" "GeneralizedGraphicsRenderer.h")

target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL glfw)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GeneralizedGraphicsRenderer PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
