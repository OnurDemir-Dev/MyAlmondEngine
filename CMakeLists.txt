
if(NOT DEFINED ENGINE_DIR)
    set(ENGINE_DIR ${MyAlmondEngine_Dir})
endif()

set(RESOURCES_DIR ${ENGINE_DIR}/src/resources)

set(BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(EXECUTE_DIR ${EXECUTABLE_OUTPUT_PATH})


# Include directories for third-party libraries
include_directories(${ENGINE_DIR}/thirdparty/include ${ENGINE_DIR}/src)

# Link directories for third-party libraries
link_directories(${ENGINE_DIR}/thirdparty/libs ${ENGINE_DIR}/thirdparty/bin)


# Add source files directory
include(${ENGINE_DIR}/src/CMakeLists.txt)

# Use a more explicit way to collect source files
file(GLOB_RECURSE ENGINE_SOURCES ${ENGINE_DIR}/src/*.cpp)
# Remove main.cpp from ENGINE_SOURCES
list(FILTER ENGINE_SOURCES EXCLUDE REGEX "main.cpp")

#TODO: Comments will rmeove
#file(COPY ${ENGINE_DIR}/assets DESTINATION ${EXECUTE_DIR})
file(COPY ${ENGINE_DIR}/src/resources DESTINATION ${EXECUTE_DIR}/src)

include(${ENGINE_DIR}/thirdparty/include/glm/CMakeLists.txt)


# Create the main executable
add_executable(${PROJECT_NAME} ${GAME_SOURCES} ${ENGINE_SOURCES})

#Uncommon if you want without console
#if (WIN32)
#    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
#endif()

# Specify include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Specify libraries to link against
target_link_libraries(${PROJECT_NAME} PRIVATE glad glfw3 opengl32)

