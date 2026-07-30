cmake_minimum_required(VERSION 3.22)
project(TombRaiderSaveEditor)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

if(UNIX)
    if(APPLE)
        set(TRSE_TARGET_PLATFROM macos)
    else()
        set(TRSE_TARGET_PLATFROM linux)
    endif()
else()
    set(TRSE_TARGET_PLATFROM win32)
endif()

add_executable(devtool)
add_subdirectory(src)
add_subdirectory(extern)



target_compile_options(devtool PRIVATE -Wall -Wextra)
target_include_directories(devtool PRIVATE include)

set (USE_ADDRESS_SANITIZER OFF CACHE BOOL "Should the Address Sanitizer tool be enabled?")
if (USE_ADDRESS_SANITIZER)
  target_compile_options(devtool PRIVATE -fsanitize=address)
  target_link_options(devtool PRIVATE -fsanitize=address)
endif()
