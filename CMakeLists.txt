cmake_minimum_required(VERSION 3.12)

set(PROJ_NAME test_cef)
project(${PROJ_NAME} C CXX)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 20)

function(def_vs_filters FILE_LIST)
	foreach(source IN LISTS FILE_LIST)
	    get_filename_component(source_path "${source}" PATH)
	    string(REPLACE "${CMAKE_CURRENT_LIST_DIR}" "" source_path_relative "${source_path}")
	    string(REPLACE "/" "\\" source_path_msvc "${source_path_relative}")
	    source_group("${source_path_msvc}" FILES "${source}")
	endforeach()
endfunction(def_vs_filters)

file(GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_LIST_DIR}/src/*.h"
    "${CMAKE_CURRENT_LIST_DIR}/src/*.hpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/*.c"
    "${CMAKE_CURRENT_LIST_DIR}/include/*.h"
    "${CMAKE_CURRENT_LIST_DIR}/include/*.hpp"
)
def_vs_filters("${SRC_FILES}")
add_library(${PROJ_NAME} ${LIB_TYPE} ${SRC_FILES})
if(WIN32)
	target_compile_options(${PROJ_NAME} PRIVATE /wd4251)
	target_compile_options(${PROJ_NAME} PRIVATE /wd4996)
endif()


if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${PROJ_NAME} PRIVATE -Wno-c++11-narrowing)
endif()
target_link_libraries(${PROJ_NAME} "/home/runner/work/test_cef/test_cef/cef_binary_106.1.0+g30ad805+chromium-106.0.5249.119_linux64_minimal/libcef_dll_wrapper.a")
target_link_libraries(${PROJ_NAME} "/home/runner/work/test_cef/test_cef/cef_binary_106.1.0+g30ad805+chromium-106.0.5249.119_linux64_minimal/Release/libcef.so")

target_include_directories(${PROJ_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJ_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
