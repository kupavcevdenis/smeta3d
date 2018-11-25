######################################################################################
######################################################################################

file(GLOB PRIVATE_HEADERS *.h)
file(GLOB SOURCES *.cpp)
file(GLOB FORM_FILES *.ui)

list(SORT PRIVATE_HEADERS)
list(SORT SOURCES)


qt5_wrap_cpp(MOC_OUT ${PRIVATE_HEADERS})
qt5_wrap_ui(UI_OUT ${FORM_FILES})

message(MOC_OUT " : ${MOC_OUT}")
message(UI_OUT " : ${UI_OUT}")

set(ADDITION_COMPILE_FLAGS "-DMY_EXE")
set(ADDITION_LINK_FLAGS "")
if(MSVC)
   set(ADDITION_COMPILE_FLAGS "${ADDITION_COMPILE_FLAGS}")
   set(ADDITION_LINK_FLAGS "${ADDITION_LINK_FLAGS} /ENTRY:mainCRTStartup" ) 
   set(_WIN32 "WIN32")
endif()

add_executable(run ${_WIN32} ${PRIVATE_HEADERS} ${SOURCES} ${MOC_OUT} ${UI_OUT}) 
##set_executable_output_postfix( my_project)
#set_version_and_label( ${CURRENT_LIBRARY_NAME} )
set_target_properties( run PROPERTIES 
                       COMPILE_FLAGS "${ADDITION_COMPILE_FLAGS}"
                       LINK_FLAGS "${ADDITION_LINK_FLAGS}"
                       ENABLE_EXPORTS FALSE
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

message(Qt5Widgets_LIBRARIES ": ${Qt5Widgets_LIBRARIES}")
set(LIBRARIES ${Qt5Widgets_LIBRARIES} gui_basis kernel)

target_link_libraries(run ${LIBRARIES})
