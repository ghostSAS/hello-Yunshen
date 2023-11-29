cmake_minimum_required(VERSION 3.0.0)
project(nQueens VERSION 0.1.0 LANGUAGES C CXX)

# Create a list of all source files in the 'src' directory
file(GLOB SOURCES "src/*.cpp")
# file(GLOB SOURCES "src/main.cpp", "src/nQueens_solver.cpp")


set(IMGUI ../imgui-docking)
set(BACKEND ${IMGUI}/backends)
set(INCLUDE_DIR ./include)
include_directories(${IMGUI} ${BACKEND} ${INCLUDE_DIR})

file(GLOB IMGUI_SOURCES ${IMGUI}/*.cpp)

add_executable(nQueens WIN32 ${SOURCES} ${IMGUI_SOURCES} ${BACKEND}/imgui_impl_win32.cpp ${BACKEND}/imgui_impl_dx11.cpp)
# ${BACKEND}/imgui_impl_win32.cpp

# target_include_directories(nQueens PRIVATE ../imgui-master include ../imgui-master/backends ../imgui-master/examples/libs/glfw/include)
target_include_directories(nQueens PRIVATE ../imgui-docking include )

target_link_libraries(nQueens d3d11 d3dcompiler dxgi dwmapi)


# file(GLOB IMGUI_SOURCES "../imgui-master/*.cpp")
# file(GLOB BACKENDS_SOURCES "../imgui-master/backends/*.cpp")
# IMGUI_DIR = ../imgui-master
# IMGUI_SOURCES += $(IMGUI_DIR)/backends/imgui_impl_glfw.cpp $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp
# IMGUI_SOURCES += $(IMGUI_SOURCES)../imgui-master/backends/imgui_impl_glfw.cpp $(IMGUI_SOURCES)../imgui-master/backends/imgui_impl_opengl3.cpp



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# set(GCC_CXX_FLAGS ${GCC_CXX_FLAGS} "-static-libgcc -static-libstdc++ -static")
include(CPack)
