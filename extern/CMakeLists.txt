add_subdirectory(zlib)
add_subdirectory(sdl3)


# Dear ImGui
set(IMGUI_DIR imgui)
include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends ..)

file(GLOB sources ${IMGUI_DIR}/*.cpp)

add_library(imgui_lib ${sources} ${IMGUI_DIR}/backends/imgui_impl_sdl3.cpp ${IMGUI_DIR}/backends/imgui_impl_sdlrenderer3.cpp ${IMGUI_DIR}/imgui.cpp ${IMGUI_DIR}/imgui_draw.cpp ${IMGUI_DIR}/imgui_demo.cpp ${IMGUI_DIR}/imgui_tables.cpp ${IMGUI_DIR}/imgui_widgets.cpp)
target_link_libraries(imgui_lib PUBLIC SDL3-shared)
target_include_directories(imgui_lib PUBLIC ${IMGUI_DIR})

target_link_libraries(devtool PRIVATE zlib imgui_lib)