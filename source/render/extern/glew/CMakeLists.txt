######################################################################################
######################################################################################

file(GLOB HEADERS include/GL/*.h)
file(GLOB SOURCES src/*.c)

list(SORT HEADERS)
list(SORT SOURCES)

add_library(glew SHARED ${HEADERS} ${SOURCES}) 
##set_executable_output_postfix( kernel)
#set_version_and_label( ${CURRENT_LIBRARY_NAME} )
include_directories(./include)
set_target_properties( glew PROPERTIES 
                       COMPILE_FLAGS "${ADDITION_COMPILE_FLAGS}"
)

set(LIBRARIES ${OPENGL_gl_LIBRARY} )

target_link_libraries(glew ${LIBRARIES})
