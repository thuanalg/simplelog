# Add main.cpp file of the project root directory as a source file
project(simplelog_project)
set(SOURCE_LIB_FILES simplelog.c simplelog.h simplelog_config.h)
set(SOURCE_BIN_FILES main.c)

# Add executable target with source files listed in SOURCE_FILES variable

add_compile_definitions(EXPORT_DLL_API_SIMPLE_LOG simpleloglib)
add_compile_definitions(_CRT_SECURE_NO_WARNINGS simpleloglib)
add_library(simpleloglib SHARED ${SOURCE_LIB_FILES})

add_compile_definitions(_CRT_SECURE_NO_WARNINGS simple_example)

add_executable(simple_example ${SOURCE_BIN_FILES})

target_link_libraries(simple_example 
	simpleloglib
)