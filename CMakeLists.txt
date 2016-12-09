cmake_minimum_required( VERSION 2.8.12 )

project( taocp_exercises )

include( ExternalProject )

find_package( Boost 1.60.0 COMPONENTS system filesystem regex iostreams unit_test_framework REQUIRED ) 

enable_testing( )
add_definitions( -DBOOST_TEST_DYN_LINK ) 

if( ${CMAKE_CXX_COMPILER_ID} STREQUAL 'MSVC' )
	add_compile_options( -D_WIN32_WINNT=0x0601 ) 
else( )
	find_package( Threads REQUIRED )
	if( THREADS_HAVE_PTHREAD_ARG )
		set( COMPILER_SPECifIC_LIBS, "-lpthread" )
	endif( )
	if( ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "AppleClang" )
		add_compile_options(-std=c++14 -Weverything -march=native -g -Wno-c++98-compat -Wfatal-errors -Wno-covered-switch-default -Wno-padded -Wno-exit-time-destructors -Wno-c++98-compat-pedantic -Wno-unused-parameter -Wno-missing-noreturn -Wno-missing-prototypes -Wno-disabled-macro-expansion)
	elseif( ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" )
		add_compile_options(-std=c++14 -Wall -march=native -ggdb -Wno-deprecated-declarations)
	endif()
endif( )

include_directories( SYSTEM ${Boost_INCLUDE_DIRS} )
link_directories( ${Boost_LIBRARY_DIRS} )

set( HEADER_FOLDER "include" )
set( SOURCE_FOLDER "src" )
set( TEST_FOLDER "tests" )

include_directories( ${HEADER_FOLDER} )

set( HEADER_FILES
)

set( SOURCE_FILES
)

add_executable( s1_1_E_euclid_gcd_bin ${SOURCE_FOLDER}/s1_1_E_euclid_gcd.cpp )
target_link_libraries( s1_1_E_euclid_gcd_bin ${Boost_LIBRARIES} )

