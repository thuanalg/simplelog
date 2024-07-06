# Add main.cpp file of the project root directory as a source file
project(simplelog)
set(SOURCE_LIB_FILES simplelog.c simplelog.h simplelog_config.h)
set(SOURCE_BIN_FILES_CPP main.c)

# Add executable target with source files listed in SOURCE_FILES variable

add_definitions(-DEXPORT_DLL_API_SIMPLE_LOG simpleloglib)
add_library(simpleloglib SHARED ${SOURCE_LIB_FILES})

add_executable(simple_example ${SOURCE_BIN_FILES_CPP})

target_link_libraries(simple_example 
	simpleloglib
)