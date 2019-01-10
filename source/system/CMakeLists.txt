######################################################################################
######################################################################################

file(GLOB PRIVATE_HEADERS *.h)
file(GLOB PUBLIC_HEADERS ${CMAKE_SOURCE_DIR}/include/system/*.h)
file(GLOB PUBLIC_IFC_HEADERS ${CMAKE_SOURCE_DIR}/include/system/ifc/*.h)
file(GLOB SOURCES *.cpp)

list(SORT PRIVATE_HEADERS)
list(SORT SOURCES)

add_library(system SHARED ${PUBLIC_HEADERS} ${PUBLIC_IFC_HEADERS} ${PRIVATE_HEADERS} ${SOURCES}) 
##set_executable_output_postfix( kernel)
#set_version_and_label( ${CURRENT_LIBRARY_NAME} )
set_target_properties( system PROPERTIES 
                       COMPILE_FLAGS "${ADDITION_COMPILE_FLAGS}"
)


include_directories(${Boost_INCLUDE_DIR})

#message(Qt5Widgets_LIBRARIES ": ${Qt5Widgets_LIBRARIES}")
#set(LIBRARIES engine)

#target_link_libraries(system ${LIBRARIES})
