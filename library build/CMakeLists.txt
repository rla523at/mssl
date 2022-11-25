cmake_minimum_required(VERSION 3.11)	

project(										
	mssl                       					
	VERSION 0.0                     		
	DESCRIPTION "MS String Library"      
	LANGUAGES CXX
)

add_library(									
	mssl             							
	STATIC										
	src/String_Editor.cpp									
) 

target_compile_options(							
	mssl                 						
	PRIVATE                  					
	/std:c++17              					
	/W4                   						
)

set_target_properties(
	mssl
	PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY_DEBUG		"${CMAKE_SOURCE_DIR}/lib"
		ARCHIVE_OUTPUT_NAME_DEBUG			"mssl_debug"
		ARCHIVE_OUTPUT_DIRECTORY_RELEASE	"${CMAKE_SOURCE_DIR}/lib"
		ARCHIVE_OUTPUT_NAME_RELEASE			"mssl_release"
)