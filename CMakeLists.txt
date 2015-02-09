cmake_minimum_required ( VERSION 2.8.5 )
project ( moai-admob-android )

set ( PLUGIN_ROOT ${CMAKE_CURRENT_SOURCE_DIR} )

set ( MOAI_ADMOB_ANDROID_INCLUDES 
    ${PLUGIN_ROOT}/
)

# Use all cpp files in directory as source code
file ( GLOB_RECURSE MOAI_ADMOB_ANDROID_SRC "${PLUGIN_ROOT}/*.cpp" )
file ( GLOB_RECURSE MOAI_ADMOB_ANDROID_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h" )

add_library ( moai-admob-android STATIC ${MOAI_ADMOB_ANDROID_SRC} ${MOAI_ADMOB_ANDROID_HEADERS} )
target_include_directories( moai-admob-android PUBLIC ${MOAI_ADMOB_INCLUDES})
target_link_libraries (moai-admob-android moai-core)