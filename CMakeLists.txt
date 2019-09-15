cmake_minimum_required(VERSION 3.1)

project("TDT4200 assignment 1" VERSION 1.0.0 LANGUAGES C)

#Set the output to the bin folder where cmake was executed
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable("bitmap"
	${PROJECT_SOURCE_DIR}/src/main.c
	${PROJECT_SOURCE_DIR}/src/bitmap.c
)