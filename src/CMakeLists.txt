target_sources(devtool PRIVATE main.cpp SaveInfo.cpp Hash.cpp Linalg.cpp)
add_subdirectory(saved)
add_subdirectory(gui)
add_subdirectory(platform)