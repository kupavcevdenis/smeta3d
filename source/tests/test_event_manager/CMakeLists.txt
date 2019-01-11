######################################################################################
######################################################################################

file(GLOB PRIVATE_HEADERS *.h)
file(GLOB SOURCES *.cpp)

list(SORT PRIVATE_HEADERS)
list(SORT SOURCES)



#set(ADDITION_COMPILE_FLAGS "-DMY_EXE")
#set(ADDITION_LINK_FLAGS "")
#if(MSVC)
#   set(ADDITION_COMPILE_FLAGS "${ADDITION_COMPILE_FLAGS}")
#   set(ADDITION_LINK_FLAGS "${ADDITION_LINK_FLAGS} /ENTRY:mainCRTStartup" ) 
#   set(_WIN32 "WIN32")
#endif()

add_executable(test_event_manager ${_WIN32} ${PRIVATE_HEADERS} ${SOURCES}) 
##set_executable_output_postfix( my_project)
#set_version_and_label( ${CURRENT_LIBRARY_NAME} )
set_target_properties( test_event_manager PROPERTIES 
                       COMPILE_FLAGS "${ADDITION_COMPILE_FLAGS}"
                       LINK_FLAGS "${ADDITION_LINK_FLAGS}"
                       ENABLE_EXPORTS FALSE
)

include_directories(${Boost_INCLUDE_DIR})

set(LIBRARIES system)

target_link_libraries(test_event_manager ${LIBRARIES})
