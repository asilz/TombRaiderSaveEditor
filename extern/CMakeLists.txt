add_subdirectory(zlib)
add_subdirectory(sdl3)
add_subdirectory(imgui)

target_link_libraries(devtool PRIVATE zlib imgui_lib)