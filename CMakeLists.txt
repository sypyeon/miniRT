cmake_minimum_required(VERSION 3.13)
project(miniRT)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -g")
add_subdirectory(libft)
include(ExternalProject)
ExternalProject_Add(minilibx-linux
        SOURCE_DIR ${PROJECT_SOURCE_DIR}/minilibx-linux
        CONFIGURE_COMMAND "" # No configure step needed for a simple Makefile project
        BUILD_COMMAND make -C <SOURCE_DIR> # Or specify the exact make command
        INSTALL_COMMAND "" # No install step needed if not installing artifacts
        # Add other options as needed, e.g., for dependencies or build artifacts
)
set(SOURCE_FILES
        src/check_parse.c
        src/main.c
        src/rt_err_msg.c
        src/rt_file_format.c
        src/rt_file_validate.c
        src/rt_free_utils.c
        src/rt_min_vec.c
        src/rt_set_vec.c
        src/rt_set_vector.c
        src/rt_strcmp.c
        src/rt_strtod.c
        src/rt_tab_to_space.c
        src/rt_vec_calculate.c
        src/rt_vec_init.c
        src/rt_vec_length.c
        src/rt_vec_multiply_divide.c
        src/rt_vec_plus_minus.c
)
add_executable(miniRT ${SOURCE_FILES})
add_dependencies(miniRT minilibx-linux)
add_library(minilibx STATIC IMPORTED)
set_property(TARGET minilibx PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/minilibx-linux/libmlx.a)
add_library(x11 STATIC IMPORTED)
set_property(TARGET x11 PROPERTY IMPORTED_LOCATION /System/Volumes/Data/opt/homebrew/Cellar/libx11/1.8.12/lib/libX11.a)
add_library(xext STATIC IMPORTED)
set_property(TARGET xext PROPERTY IMPORTED_LOCATION /System/Volumes/Data/opt/homebrew/Cellar/libxext/1.3.6/lib/libXext.a)
target_link_libraries(miniRT libft m x11 xext minilibx)
