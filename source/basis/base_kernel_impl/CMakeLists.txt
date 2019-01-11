######################################################################################
######################################################################################

file(GLOB PRIVATE_HEADERS *.h)
file(GLOB PUBLIC_HEADERS ${CMAKE_SOURCE_DIR}/include/kernel/ifc/*.h)
file(GLOB SOURCES *.cpp)

list(SORT PRIVATE_HEADERS)
list(SORT SOURCES)

add_library(kernel SHARED ${PUBLIC_HEADERS} ${PRIVATE_HEADERS} ${SOURCES}) 
##set_executable_output_postfix( kernel)
#set_version_and_label( ${CURRENT_LIBRARY_NAME} )
set_target_properties( kernel PROPERTIES 
                       COMPILE_FLAGS "${ADDITION_COMPILE_FLAGS}"
)


#message(Qt5Widgets_LIBRARIES ": ${Qt5Widgets_LIBRARIES}")
set(LIBRARIES engine system)

target_link_libraries(kernel ${LIBRARIES})
