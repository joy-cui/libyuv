## For more information about using CMake with Android Studio, read the
## documentation: https://d.android.com/studio/projects/add-native-code.html
#
## Sets the minimum version of CMake required to build the native library.
#
#cmake_minimum_required(VERSION 3.18.1)
#
## Declares and names the project.
#
#project("libyuv")
#
#set(baseCppPath "src/main/cpp")
#SET ( ly_src_dir ${baseCppPath})
##SET ( ly_head_dir ${baseCppPath}/include)
#MESSAGE("=====message===ly_src_dir: ${ly_src_dir}")
#FILE ( GLOB_RECURSE ly_source_files ${ly_src_dir}/*.cc )
#LIST ( SORT         ly_source_files )
#
#FILE(GLOB_RECURSE ly_unittest_sources ${ly_tst_dir}/*.cc)
#LIST(SORT ly_unittest_sources)
#
##设置生成的so动态库最后输出的路径
#set(ProjectRoot ${CMAKE_SOURCE_DIR}/../../../)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ProjectRoot}/libs/${ANDROID_ABI})
#
#
## Creates and names a library, sets it as either STATIC
## or SHARED, and provides the relative paths to its source code.
## You can define multiple libraries, and CMake builds them for you.
## Gradle automatically packages shared libraries with your APK.
##include_directories(${ly_head_dir})
#
#
#
#MESSAGE("test=====message=== ${CMAKE_SOURCE_DIR}/include =====${ly_source_files}")
#
#add_library( # Sets the name of the library.
#        libyuv
#
#        # Sets the library as a shared library.
#        SHARED
#        ${ly_source_files}
#        # Provides a relative path to your source file(s).
#        libyuv_utils.cpp
#        native-lib.cpp
#        Log.cpp
#        )
#
#
##关联头文件
#target_include_directories(
#        libyuv
#        PRIVATE
#        ${CMAKE_SOURCE_DIR}/libyuv
#)
#
## Searches for a specified prebuilt library and stores the path as a
## variable. Because CMake includes system libraries in the search path by
## default, you only need to specify the name of the public NDK library
## you want to add. CMake verifies that the library exists before
## completing its build.
##if(ANDROID_ABI STREQUAL arm64-v8a)
##    set_target_properties(xxx PROPERTIES COMPILE_FLAGS -mfpu=neon)
##endif()
#find_library( # Sets the name of the path variable.
#        log-lib
#
#        # Specifies the name of the NDK library that
#        # you want CMake to locate.
#        log)
#
## Specifies libraries CMake should link to your target library. You
## can link multiple libraries, such as libraries you define in this
## build script, prebuilt third-party libraries, or system libraries.
#
#target_link_libraries( # Specifies the target library.
#        libyuv
#
#        # Links the target library to the log library
#        # included in the NDK.
#        ${log-lib})



# CMakeLists for libyuv
# Originally created for "roxlu build system" to compile libyuv on windows
# Run with -DTEST=ON to build unit tests
cmake_minimum_required(VERSION 3.18.1)
project("source")
#PROJECT ( YUV C CXX )   # "C" is required even for C++ projects
#CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
#OPTION( TEST "Built unit tests" OFF )

SET ( ly_base_dir   ${PROJECT_SOURCE_DIR} )
SET ( ly_src_dir    ${ly_base_dir}/source )
SET ( ly_inc_dir    ${ly_base_dir}/include )
#SET ( ly_tst_dir    ${ly_base_dir}/unit_test )
SET ( ly_lib_name   yuv )
#SET ( ly_lib_static ${ly_lib_name} )
SET ( ly_lib_shared ${ly_lib_name} )

FILE ( GLOB_RECURSE ly_source_files ${ly_src_dir}/*.cc )
LIST ( SORT         ly_source_files )

#FILE ( GLOB_RECURSE ly_unittest_sources ${ly_tst_dir}/*.cc )
#LIST ( SORT         ly_unittest_sources )


##设置生成的so动态库最后输出的路径
set(ProjectRoot ${CMAKE_SOURCE_DIR}/../../../)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ProjectRoot}/libs/${ANDROID_ABI})


INCLUDE_DIRECTORIES( BEFORE ${ly_inc_dir} )

# this creates the static library (.a)
#ADD_LIBRARY             ( ${ly_lib_static} STATIC ${ly_source_files} )

# this creates the shared library (.so)
add_library(
        ${ly_lib_shared}
        SHARED
        ${ly_source_files}
        libyuv_utils.cpp
        native-lib.cpp
        native_utils.cpp
        Log.cpp
)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        ${ly_lib_shared}

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})


#add_library( # Sets the name of the library.
#        libyuv
#
#        # Sets the library as a shared library.
#        SHARED
#        ${ly_source_files}
#        # Provides a relative path to your source file(s).
#        libyuv_utils.cpp
#        native-lib.cpp
#        Log.cpp
#        )


SET_TARGET_PROPERTIES   ( ${ly_lib_shared} PROPERTIES OUTPUT_NAME "${ly_lib_name}" )
SET_TARGET_PROPERTIES   ( ${ly_lib_shared} PROPERTIES PREFIX "lib" )

# this creates the conversion tool
#ADD_EXECUTABLE         ( yuvconvert ${ly_base_dir}/util/yuvconvert.cc )
#TARGET_LINK_LIBRARIES  ( yuvconvert ${ly_lib_static} )


INCLUDE ( FindJPEG )
if (JPEG_FOUND)
    include_directories( ${JPEG_INCLUDE_DIR} )
    target_link_libraries( yuvconvert ${JPEG_LIBRARY} )
    add_definitions( -DHAVE_JPEG )
endif()

if(TEST)
    find_library(GTEST_LIBRARY gtest)
    if(GTEST_LIBRARY STREQUAL "GTEST_LIBRARY-NOTFOUND")
        set(GTEST_SRC_DIR /usr/src/gtest CACHE STRING "Location of gtest sources")
        if(EXISTS ${GTEST_SRC_DIR}/src/gtest-all.cc)
            message(STATUS "building gtest from sources in ${GTEST_SRC_DIR}")
            set(gtest_sources ${GTEST_SRC_DIR}/src/gtest-all.cc)
            add_library(gtest STATIC ${gtest_sources})
            include_directories(${GTEST_SRC_DIR})
            include_directories(${GTEST_SRC_DIR}/include)
            set(GTEST_LIBRARY gtest)
        else()
            message(FATAL_ERROR "TEST is set but unable to find gtest library")
        endif()
    endif()

    add_executable(libyuv_unittest ${ly_unittest_sources})
    target_link_libraries(libyuv_unittest ${ly_lib_name} ${GTEST_LIBRARY})
    find_library(PTHREAD_LIBRARY pthread)
    if(NOT PTHREAD_LIBRARY STREQUAL "PTHREAD_LIBRARY-NOTFOUND")
        target_link_libraries(libyuv_unittest pthread)
    endif()
    if (JPEG_FOUND)
        target_link_libraries(libyuv_unittest ${JPEG_LIBRARY})
    endif()

    if(NACL AND NACL_LIBC STREQUAL "newlib")
        target_link_libraries(libyuv_unittest glibc-compat)
    endif()

    find_library(GFLAGS_LIBRARY gflags)
    if(NOT GFLAGS_LIBRARY STREQUAL "GFLAGS_LIBRARY-NOTFOUND")
        target_link_libraries(libyuv_unittest gflags)
        add_definitions(-DLIBYUV_USE_GFLAGS)
    endif()
endif()


# install the conversion tool, .so, .a, and all the header files
#INSTALL ( PROGRAMS ${CMAKE_BINARY_DIR}/yuvconvert         DESTINATION bin )
#INSTALL ( TARGETS ${ly_lib_static}                        DESTINATION lib )
#INSTALL ( TARGETS ${ly_lib_shared} LIBRARY                DESTINATION lib RUNTIME DESTINATION bin )
INSTALL ( DIRECTORY ${PROJECT_SOURCE_DIR}/include/     DESTINATION include )

# create the .deb and .rpm packages using cpack
#INCLUDE ( CM_linux_packages.cmake )
