cmake_minimum_required(VERSION 3.30)
project(Randy VERSION 1.0 LANGUAGES CXX)
set(CMAKE_BUILD_TYPE Release)
if("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3 -march=native -mtune=native -flto -funroll-loops -ffast-math -fstrict-aliasing -fomit-frame-pointer")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-O1")
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 -march=native /Qvec /EHsc")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")
endif()
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CLI11_PRECOMPILED ON)
set(CMAKE_INSTALL_DO_STRIP TRUE)
configure_file(RandyConfig.h.in ${CMAKE_BINARY_DIR}/include/RandyConfig.h)
if(NOT DEFINED CLI11_DIR)
    set(CLI11_DIR "$CMAKE_SOURCE_DIR/cli11" CACHE STRING "CLI11 git submodule")
endif()

add_subdirectory(CLI11)

include_directories(${CLI11_DIR}/include)
include_directories(include)

add_subdirectory(src)
install(TARGETS randy DESTINATION bin)
install(FILES README.md LICENSE DESTINATION share/doc/Randy)
# Packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_PACKAGE_VERSION_MAJOR "${RANDY_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${RANDY_VERSION_MINOR}")
set(CPACK_PACKAGE_VENDOR "Frank Froggins")
set(CPACK_STRIP_FILES TRUE)
set(CPACK_GENERATOR "TXZ")
set(CPACK_SOURCE_GENERATOR "TXZ")
set(CPACK_SOURCE_IGNORE_FILES
    \\.git/
    build/
    bin/
    ".*~$"
    compile_commands.json
)
set(CPACK_VERBATIM_VARIABLES YES)
include(CPack)
