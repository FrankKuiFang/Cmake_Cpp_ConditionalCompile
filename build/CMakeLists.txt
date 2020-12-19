
if(CMAKE_GENERATOR MATCHES Ninja)
	# this is for Android Studio
	cmake_minimum_required(VERSION 3.6.0)
else()
	cmake_minimum_required(VERSION 3.8.0)
endif()

# Build with clang
IF (UNIX)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdeclspec -std=gnu++14 -stdlib=libc++ -Wno-inconsistent-missing-override -I/usr/include/libcxxabi")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
ENDIF()

# top project
project(Solutions)

# This is to make the debug build of Cybertron Foundation being compatible with Unreal debug build.
IF (MSVC)
	#string(REPLACE "/MT" "/MD" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
	string(REPLACE "/MDd" "/MD" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
	add_definitions(-D_ITERATOR_DEBUG_LEVEL=0)
ENDIF()

set(THREADS_PREFER_PTHREAD_FLAG ON)

# Global settings：：
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")
# macros
set(PATH_ROOT ${CMAKE_CURRENT_LIST_DIR}/..)
set(SOURCE_CODE_PATH ${CMAKE_CURRENT_LIST_DIR}/../source)

function(SetDefaultTargetProperties target)
	set_target_properties(${target} PROPERTIES
		CXX_STANDARD 14
	)
	set_target_properties(${target} PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
		LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
		RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
	)
endfunction()

add_subdirectory(${SOURCE_CODE_PATH} solution)


