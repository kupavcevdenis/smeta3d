######################################################################################
######################################################################################

file(GLOB PRIVATE_HEADERS *.h)
file(GLOB PUBLIC_HEADERS ${CMAKE_SOURCE_DIR}/include/render/engine/ifc/*.h)
file(GLOB PRIVATE_GL_SYSTEM_HEADERS gl_render_system/*.h)
file(GLOB SOURCES_GL_SYSTEM_HEADERS gl_render_system/*.cpp)
file(GLOB SOURCES *.cpp)

list(SORT PRIVATE_HEADERS)
list(SORT SOURCES)


add_library(engine SHARED ${PUBLIC_HEADERS} ${PRIVATE_HEADERS} ${PRIVATE_GL_SYSTEM_HEADERS} ${SOURCES_GL_SYSTEM_HEADERS} ${SOURCES}) 
##set_executable_output_postfix( kernel)
#set_version_and_label( ${CURRENT_LIBRARY_NAME} )

include_directories(${CMAKE_SOURCE_DIR}/source/render/engine)


set_target_properties( engine PROPERTIES 
                       COMPILE_FLAGS "${ADDITION_COMPILE_FLAGS}"
)


#message(Qt5Widgets_LIBRARIES ": ${Qt5Widgets_LIBRARIES}")
set(LIBRARIES glew )

target_link_libraries(engine ${LIBRARIES})
