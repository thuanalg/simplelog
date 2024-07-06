# Add main.cpp file of the project root directory as a source file
project(simplelog)
set(SOURCE_LIB_FILES simplelog.c simplelog.h)
set(SOURCE_BIN_FILES_CPP main.c)

# Add executable target with source files listed in SOURCE_FILES variable
#add_executable(simple_example ${SOURCE_FILES})
#add_executable(siimple_cppexample ${SOURCE_FILES_CPP})
add_compile_definitions(EXPORT_DLL_API_SIMPLE_LOG simpleloglib)
add_library(simpleloglib SHARED ${SOURCE_LIB_FILES})

add_executable(simple_example ${SOURCE_BIN_FILES_CPP})

target_link_libraries(simple_example 
	simpleloglib
)