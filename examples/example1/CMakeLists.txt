
include_directories( ${LIBBOULETTE_SOURCE_DIR}/include )
message( "Bouboub: ${LIBBOULETTE_SOURCE_DIR}/include" )

#Find OpenCL
find_package( OpenCL REQUIRED )
if( OPENCL_FOUND )
include_directories( ${OPENCL_INCLUDE_DIRS} )
set( DEPS "${DEPS};${OPENCL_LIBRARIES}" )
message("PITAING")
endif( OPENCL_FOUND )

#Find OpenGL
find_package( OpenGL REQUIRED )
if( OPENGL_FOUND )
message("Found OpenGL : ${OPENGL_LIBRARIES}")
set( DEPS "${DEPS};${OPENGL_LIBRARIES}" )
endif()

#Find GLEW
find_package( GLEW REQUIRED )
if( GLEW_FOUND )
message( "Found GLEW" )
endif()

add_executable( example1 main.cc camera.cc )
target_link_libraries( example1 boulette ${DEPS} GL GLU glut GLEW )
