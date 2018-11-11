####################################################################################
# Find Qt5
####################################################################################
 if(MSVC)# look for user-registry pointing to qtcreator
    get_filename_component(QT_BIN [HKEY_CURRENT_USER\\Software\\Classes\\Applications\\QtProject.QtCreator.cpp\\shell\\Open\\Command] PATH)# get root path so we can search for 5.3, 5.4, 5.5, etc
    string(REPLACE "/Tools" ";" QT_BIN "${QT_BIN}")
    list(GET QT_BIN 0 QT_BIN) 
	file(GLOB QT_VERSIONS "${QT_BIN}/5.*")
    list(SORT QT_VERSIONS)# assume the latest version will be last alphabetically
    list(REVERSE QT_VERSIONS)

    list(GET QT_VERSIONS 0 QT_VERSION)# fix any double slashes which seem to be common
    string(REPLACE "//""/"  QT_VERSION "${QT_VERSION}")# do some math trickery to guess folder# - qt uses (e.g.) "msvc2012"# - cmake uses (e.g.) "1800"# - see also https://cmake.org/cmake/help/v3.0/variable/MSVC_VERSION.html
	message(MSVC_VERSION " : ${MSVC_VERSION}")
	
	if(MSVC_VERSION GREATER 1999)
		message(WARNING "MSVC ${MSVC_VERSION} not yet supported.")
	elseif(MSVC_VERSION GREATER 1909)
		set(QT_MSVC 2017)    
	endif()
	
    
    message(QT_MSVC " : ${QT_MSVC}")
	if(CMAKE_SYSTEM_PROCESSOR MATCHES 64)
        set(QT_MSVC "${QT_MSVC}_64")
    endif()
    set(QT_PATH "${QT_VERSION}/msvc${QT_MSVC}")
		message(QT_PATH " : ${QT_PATH}")
	set(CMAKE_PREFIX_PATH ${QT_PATH} ${CMAKE_PREFIX_PATH})

	
endif()# use Qt_DIR approach so you can find Qt after cmake has been invoked

   
   find_package(Qt5 COMPONENTS Core Gui Widgets) # REQUIRED QUIET
   

####################################################################################
# Find Qt5
####################################################################################

#   if (Qt5_FOUND)   
#      set(QT_COMPONENTS Core Gui Widgets Xml Sql Network  OpenGL Svg Quick Qml PrintSupport Designer)
#   
#      if(UNIX)
#          if(Qt5_VERSION VERSION_GREATER "5.6.0")
#             set(QT_COMPONENTS ${QT_COMPONENTS} X11Extras WebEngineCore WebEngineWidgets WebEngine WebKitWidgets WebKit)
#          else()
#             set(QT_COMPONENTS ${QT_COMPONENTS} X11Extras WebKitWidgets WebKit)
#          endif()
#      else()
#          if(MSVC12 AND (QT_VER VERSION_GREATER "5.6.0") )
#             set(QT_COMPONENTS ${QT_COMPONENTS} WebKitWidgets WebKit)
#          else()
#             set(QT_COMPONENTS ${QT_COMPONENTS} WebEngineCore WebEngineWidgets WebEngine)
#          endif()
#      endif()
#
#      set(QT_OPTIONAL_COMPONENTS LinguistTools Help) #
#
#      find_package(Qt5 5.5.1 REQUIRED COMPONENTS ${QT_COMPONENTS} OPTIONAL_COMPONENTS ${QT_OPTIONAL_COMPONENTS} ) # REQUIRED QUIET
#   endif()

  #message(FATAL_ERROR "Qt5_FOUND" = ${Qt5_FOUND})

#  if (Qt5_FOUND)
#     message(STATUS "Configure with Qt5")
#  
#     set(QT5_FOUND TRUE)
#     
#     foreach(module ${QT_COMPONENTS} ${QT_OPTIONAL_COMPONENTS})
#        set( QT_INCLUDES ${QT_INCLUDES} ${Qt5${module}_INCLUDE_DIRS} )
#        string(TOUPPER ${module} module_up)
#        set(QT_QT${module_up}_LIBRARY ${Qt5${module}_LIBRARIES})
#     endforeach()
#
#     list(REMOVE_DUPLICATES QT_INCLUDES)
#     get_filename_component(QT_LIBRARY_DIR "${Qt5Core_DIR}/../../" ABSOLUTE)
#     if(NOT UNIX)
#      get_filename_component(QT_PLUGINS_DIR "${_qt5Core_install_prefix}/plugins" ABSOLUTE)
#     else()
#      get_filename_component(QT_PLUGINS_DIR "${_qt5Core_install_prefix}/lib/x86_64-linux-gnu/qt5/plugins" ABSOLUTE)
#     endif()
#     set(QT_USE_FILE ${CMAKE_CURRENT_LIST_DIR}/modules/UseQt5.cmake)
#
#     if (NOT UNIX)
#        set(_QtWebProcess "QtWebProcess.exe")
#        set(_QtWebEngineProcess "QtWebEngineProcess.exe")
#        set(_QtWebEngineProcess_debug "QtWebEngineProcess-debug.exe")
#        set(_QtWebEngineProcess_debug_2 "QtWebEngineProcessd.exe")
#     endif()
#
#     find_file(Qt5_QtWebProcess ${_QtWebProcess} PATHS "${_qt5Core_install_prefix}/bin" NO_DEFAULT_PATH NO_SYSTEM_ENVIRONMENT_PATH )
#     find_file(Qt5_QtWebEngineProcess ${_QtWebEngineProcess} PATHS "${_qt5Core_install_prefix}/bin" NO_DEFAULT_PATH NO_SYSTEM_ENVIRONMENT_PATH )
#     find_file(Qt5_QtWebEngineProcess_DBG ${_QtWebEngineProcess_debug} PATHS "${_qt5Core_install_prefix}/bin" NO_DEFAULT_PATH NO_SYSTEM_ENVIRONMENT_PATH )
#     
#     if (NOT Qt5_QtWebEngineProcess_DBG)
#        find_file(Qt5_QtWebEngineProcess_DBG ${_QtWebEngineProcess_debug_2} PATHS "${_qt5Core_install_prefix}/bin" NO_DEFAULT_PATH NO_SYSTEM_ENVIRONMENT_PATH )
#     endif()

 