cmake_minimum_required(VERSION 3.13)
project("RotatingTriangle")

add_executable(${PROJECT_NAME} src/main.c)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) 

add_subdirectory(extern/glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)


add_subdirectory(extern/glad)
target_link_libraries(${PROJECT_NAME} PUBLIC glad)

target_include_directories(${PROJECT_NAME} PUBLIC extern/)
target_include_directories(${PROJECT_NAME} PUBLIC extern/glad/include)