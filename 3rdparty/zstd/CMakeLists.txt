option(ZSTD_BUILD_PROGRAMS "BUILD PROGRAMS" OFF)
option(ZSTD_BUILD_SHARED "BUILD SHARED LIBRARIES" OFF)
option(ZSTD_BUILD_STATIC "BUILD STATIC LIBRARIES" ON)
option(ZSTD_BUILD_TESTS "BUILD TESTS" OFF)
option(ZSTD_USE_STATIC_RUNTIME "LINK TO STATIC RUN-TIME LIBRARIES" ON)

add_subdirectory(zstd/build/cmake EXLUDE_FROM_ALL)
add_library(3rdparty_zstd INTERFACE)
target_link_libraries(3rdparty_zstd INTERFACE libzstd_static)
