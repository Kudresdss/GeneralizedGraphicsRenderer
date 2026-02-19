set(SRC
src/*.h
src/*.cpp
)

add_library(Core STATIC)

target_sources(Core	PRIVATE ${SRC})

target_link_libraries glfw
