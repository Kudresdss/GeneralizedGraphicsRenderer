cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("GeneralizedGraphicsRenderer")

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(DEPENDENCIES_DIR ${CMAKE_CURRENT_LIST_DIR}/dependencies)

# Dependencies
include(Dependencies.cmake)

##### GLAD

set(GLAD_DIR ${DEPENDENCIES_DIR}/glad)

##################################################

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "src/GeneralizedGraphicsRenderer.cpp" "src/GeneralizedGraphicsRenderer.h" ${GLAD_DIR}/src/glad.c)


target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL glfw)
target_include_directories(${PROJECT_NAME} PRIVATE ${DEPENDENCIES_DIR} ${GLAD_DIR}/include)



# Program components
# add_subdirectory(app)
# add_subdirectory(core)
