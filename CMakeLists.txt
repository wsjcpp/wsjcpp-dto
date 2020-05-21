cmake_minimum_required(VERSION 3.0)

project(wsjcpp-dto C CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/src.wsjcpp/CMakeLists.txt)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${wsjcpp-dto_SOURCE_DIR})

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "src")

list (APPEND WSJCPP_SOURCES "src/main.cpp")
list (APPEND WSJCPP_SOURCES "src/wsjcpp_dto.h")
list (APPEND WSJCPP_SOURCES "src/wsjcpp_dto.cpp")

#### BEGIN_WSJCPP_APPEND
#### END_WSJCPP_APPEND

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable (wsjcpp-dto ${WSJCPP_SOURCES})

target_link_libraries(wsjcpp-dto ${WSJCPP_LIBRARIES})

install(
    TARGETS
        wsjcpp-dto
    RUNTIME DESTINATION
        /usr/bin
)

