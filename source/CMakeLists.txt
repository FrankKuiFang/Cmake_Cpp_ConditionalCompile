
include_directories("${SOURCE_CODE_PATH}/Factory")

IF (WIN32)
    add_definitions(-D_WIN32_WINNT=0x0501)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
ELSE()
    #set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} -Xlinker -unresolved-symbols=ignore-in-shared-libs")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Xlinker -unresolved-symbols=ignore-in-shared-libs")
ENDIF()

add_definitions(-DNOMINMAX)

file(GLOB solution_files "Base.hpp" "main.cpp" "Factory/*.*pp")
#message(${solution_files})

file(GLOB_RECURSE util_files ${CYBERTRON_PATH_VEHICLEDYNAMIC}/Source/util/*.hpp ${CYBERTRON_PATH_VEHICLEDYNAMIC}/Source/util/*.cpp) 

IF (WITH_CHINA)
    file(GLOB china_files "China/*.*pp")
    set(solution_files ${solution_files} ${china_files})
ENDIF()

IF (WITH_EURO)
    file(GLOB euro_files "Euro/*.*pp")
    set(solution_files ${solution_files} ${euro_files})
ENDIF()

IF (WITH_JAPAN)
    file(GLOB japan_files "Japan/*.*pp")
    set(solution_files ${solution_files} ${japan_files})
ENDIF()


set(BUILD_ROOT_DIR ${PATH_ROOT}/build/build)

add_executable(Solutions ${solution_files})
	
source_group(TREE ${SOURCE_CODE_PATH} FILES ${solution_files})

SetDefaultTargetProperties(Solutions)

IF (MSVC)
    SET_PROPERTY(TARGET Solutions PROPERTY FOLDER "ManagementTools")
ENDIF()

