cmake_minimum_required (VERSION 3.8)

project (GeneralizedGraphicsRenderer)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(DEPENDENCIES_DIR ${CMAKE_CURRENT_LIST_DIR}/Dependencies)

# Dependencies
include(Dependencies.cmake)

##################################################

# Program components
add_subdirectory(App)
add_subdirectory(core)
