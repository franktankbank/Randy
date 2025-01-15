add_executable(randy
    randy.cpp
    phone.cpp
    version.cpp
)
target_include_directories(randy
    PRIVATE ${CMAKE_BINARY_DIR}/include
)
target_link_libraries(randy CLI11::CLI11)

if(("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin") AND ("${CMAKE_BUILD_TYPE}" STREQUAL "Release"))
    add_custom_command(
        TARGET randy POST_BUILD
        COMMAND strip -u -r -S -x "$<TARGET_FILE:randy>"
    VERBATIM)
endif()
