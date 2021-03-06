cmake_minimum_required(VERSION 3.8)
project("map-compiler")

if( NOT CMAKE_BUILD_TYPE )
    set( CMAKE_BUILD_TYPE Debug CACHE STRING "Debug" FORCE )
endif()

if (MSVC)
    set(RELEASE_FLAGS "/MP /Zc:wchar_t /O2 /sdl /W3 /Ot /Gm- /GS /GL /Gy /WX- /Zc:forScope /Gd /Oi /MD")
	if (CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${RELEASE_FLAGS}")
	endif()
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${RELEASE_FLAGS}")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /GS /Zc:wchar_t /Zi /Od /D \"NDEBUG\" /WX- /Zc:forScope /RTC1 /Gd /MDd")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"WIN32\" /D \"_CONSOLE\" /D \"_MBCS\" /EHsc /wd\"4312\" /wd\"4267\" /wd\"4703\" /wd\"4996\" /fp:fast /Zc:inline /errorReport:prompt /nologo")
else()
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -Wall -march=native")
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")

add_subdirectory("src")

if(MSVC)
	set_target_properties(mapcompiler PROPERTIES LINK_FLAGS /STACK:8000000)
endif(MSVC)

add_subdirectory("third_party/picomodel")
add_subdirectory("third_party/table-builder")
add_subdirectory("third_party/lodepng")
add_subdirectory("third_party/jpeg-compressor")

add_dependencies(mapcompiler picomodel)
add_dependencies(mapcompiler libtablebuilder)
add_dependencies(mapcompiler liblodepng)
add_dependencies(mapcompiler libjpegd)
