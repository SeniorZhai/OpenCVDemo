cmake_minimum_required(VERSION 3.4.1)

add_library(
             native-lib
             SHARED
             src/main/cpp/native-lib.cpp )

add_library(opencv_java SHARED IMPORTED)
set_target_properties(
    opencv_java
    PROPERTIES IMPORTED_LOCATION
    ${CMAKE_SOURCE_DIR}/src/main/jniLibs/armeabi/libopencv_java.so
)
include_directories(
    ${CMAKE_SOURCE_DIR}/src/main/jniLibs/include
)
find_library(
              log-lib
              log )

target_link_libraries(
                       native-lib
                       opencv_java
                       ${log-lib} )