######################################################################################
######################################################################################

file(GLOB PRIVATE_HEADERS *.h)
file(GLOB PUBLIC_HEADERS ${CMAKE_SOURCE_DIR}/include/gui_basis/*.h)
file(GLOB SOURCES *.cpp)
file(GLOB FORM_FILES *.ui)

list(SORT PRIVATE_HEADERS)
list(SORT PUBLIC_HEADERS)
list(SORT SOURCES)


qt5_wrap_cpp(MOC_OUT ${PUBLIC_HEADERS} )
qt5_wrap_ui(UI_OUT ${FORM_FILES})


add_library(gui_basis SHARED ${_WIN32} ${PRIVATE_HEADERS} ${PUBLIC_HEADERS} ${SOURCES} ${MOC_OUT} ${UI_OUT}) 
##set_executable_output_postfix( gui_basis)
#set_version_and_label( ${CURRENT_LIBRARY_NAME} )
set_target_properties( gui_basis PROPERTIES 
                       COMPILE_FLAGS "${ADDITION_COMPILE_FLAGS}"
                       LINK_FLAGS "${ADDITION_LINK_FLAGS}"
                       ENABLE_EXPORTS FALSE
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

message(Qt5Widgets_LIBRARIES ": ${Qt5Widgets_LIBRARIES}")
set(LIBRARIES ${Qt5Widgets_LIBRARIES} )

target_link_libraries(gui_basis ${LIBRARIES})
