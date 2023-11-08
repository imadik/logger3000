cmake_minimum_required(VERSION 3.14)
project(Logger3000 VERSION 0.0.1 LANGUAGES C CXX)

# include(CTest)
# enable_testing()
option(LGR3K_BUILD_TESTS "Build mylib tests" ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-DDEBUG)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/source_location)

set(sources
    src/InnerLogger.cpp
    src/CommandsQueue.cpp
    src/LoggerInstance.cpp
    src/SaveMessageCommand.cpp
    src/SinkMessageCommand.cpp
    src/FormatMessageCommand.cpp
    src/AddSinkCommand.cpp
    src/DefaultFormatter.cpp
    src/DefaultFilter.cpp
    src/DefaultSink.cpp)
    
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

add_library(${CMAKE_PROJECT_NAME} ${sources})
add_library(${CMAKE_PROJECT_NAME}::${CMAKE_PROJECT_NAME} ALIAS ${CMAKE_PROJECT_NAME})

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/source_location/include)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(${CMAKE_PROJECT_NAME} source_location)

if(LGR3K_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
