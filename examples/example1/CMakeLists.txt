
include_directories( ${LIBBOULETTE_SOURCE_DIR}/include )
message( "Bouboub: ${LIBBOULETTE_SOURCE_DIR}/include" )

#Find OpenCL
find_package( OpenCL REQUIRED )
if( OPENCL_FOUND )
include_directories( ${OPENCL_INCLUDE_DIRS} )
set( DEPS "${DEPS};${OPENCL_LIBRARIES}" )
message("PITAING")
endif( OPENCL_FOUND )

add_executable( example1 main.cc )
target_link_libraries( example1 boulette ${OPENCL_LIBRARIES} )
