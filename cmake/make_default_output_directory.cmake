##################################################################
#
# Create variables for configurations of output directory (LIBRARY, ARCHIVE, RUNTIME)
# Usage: make_default_output_directory(BUILD_DIR )
#
##################################################################
macro( make_default_output_directory BUILD_DIR )

   if( CMAKE_CONFIGURATION_TYPES )
      set(_conf_types ${CMAKE_CONFIGURATION_TYPES})
   elseif(CMAKE_BUILD_TYPE)
      set(_conf_types ${CMAKE_BUILD_TYPE})
   endif()

   if (UNIX)
     set( _lib bin )
   else()
     set( _lib lib )
   endif()

   foreach(_conf_type ${_conf_types})
      string(TOUPPER ${_conf_type} _conf_type_up)
      if (UNIX)
        string(REPLACE "//" "/" _build_dir_and_conf_type ${BUILD_DIR} )  # В UNIX конфигурации одиночный
      else()
        string(REPLACE "//" "/" _build_dir_and_conf_type ${BUILD_DIR}/${_conf_type} )  # ${BUILD_DIR}/${_conf_type}
      endif()
      set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${_conf_type_up} ${_build_dir_and_conf_type}/${_lib} )
      set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${_conf_type_up} ${_build_dir_and_conf_type}/lib )
      set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${_conf_type_up} ${_build_dir_and_conf_type}/bin )

      # build path for output runtime
      list (APPEND RUNTIME_OUTPUT_PATH ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_${_conf_type_up}} )
      list (APPEND RUNTIME_OUTPUT_PATH_${_conf_type_up} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_${_conf_type_up}} )
      list(REMOVE_DUPLICATES RUNTIME_OUTPUT_PATH_${_conf_type_up})
      set (RUNTIME_OUTPUT_PATH_${_conf_type_up} ${RUNTIME_OUTPUT_PATH_${_conf_type_up}} CACHE INTERNAL "" FORCE )
   endforeach()

   list(REMOVE_DUPLICATES RUNTIME_OUTPUT_PATH)
   set (RUNTIME_OUTPUT_PATH ${RUNTIME_OUTPUT_PATH} CACHE INTERNAL "" FORCE )

   unset(_conf_type)
   unset(_conf_types)
   unset(_conf_type_up)
endmacro( make_default_output_directory )
