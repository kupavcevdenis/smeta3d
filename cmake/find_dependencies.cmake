
   if(EXISTS "/opt/mcst/lcc-home" AND DEFINED ENV{QTDIR})
      set(CMAKE_PREFIX_PATH "$ENV{QTDIR}/bin" ${CMAKE_PREFIX_PATH})
   endif()

   ############
   # Find Qt5
   find_package(Qt5 5.5.1 QUIET COMPONENTS Core) # REQUIRED QUIET

   if (Qt5_FOUND)   
      set(QT_COMPONENTS Core Gui Widgets Xml Sql Network  OpenGL Svg Quick Qml PrintSupport Designer)
   
      if(UNIX)
          if(Qt5_VERSION VERSION_GREATER "5.6.0")
             set(QT_COMPONENTS ${QT_COMPONENTS} X11Extras WebEngineCore WebEngineWidgets WebEngine WebKitWidgets WebKit)
          else()
             set(QT_COMPONENTS ${QT_COMPONENTS} X11Extras WebKitWidgets WebKit)
          endif()
      else()
          if(MSVC12 AND (QT_VER VERSION_GREATER "5.6.0") )
             set(QT_COMPONENTS ${QT_COMPONENTS} WebKitWidgets WebKit)
          else()
             set(QT_COMPONENTS ${QT_COMPONENTS} WebEngineCore WebEngineWidgets WebEngine)
          endif()
      endif()

      set(QT_OPTIONAL_COMPONENTS LinguistTools Help) #

      find_package(Qt5 5.5.1 REQUIRED COMPONENTS ${QT_COMPONENTS} OPTIONAL_COMPONENTS ${QT_OPTIONAL_COMPONENTS} ) # REQUIRED QUIET
   endif()

#  message(FATAL_ERROR "Qt5_FOUND" = ${Qt5_FOUND})

   if (Qt5_FOUND)
      message(STATUS "Configure with Qt5")
   
      set(QT5_FOUND TRUE)
      
      foreach(module ${QT_COMPONENTS} ${QT_OPTIONAL_COMPONENTS})
         set( QT_INCLUDES ${QT_INCLUDES} ${Qt5${module}_INCLUDE_DIRS} )
         string(TOUPPER ${module} module_up)
         set(QT_QT${module_up}_LIBRARY ${Qt5${module}_LIBRARIES})
      endforeach()

      list(REMOVE_DUPLICATES QT_INCLUDES)
      get_filename_component(QT_LIBRARY_DIR "${Qt5Core_DIR}/../../" ABSOLUTE)
      if(NOT UNIX)
       get_filename_component(QT_PLUGINS_DIR "${_qt5Core_install_prefix}/plugins" ABSOLUTE)
      else()
       get_filename_component(QT_PLUGINS_DIR "${_qt5Core_install_prefix}/lib/x86_64-linux-gnu/qt5/plugins" ABSOLUTE)
      endif()
      set(QT_USE_FILE ${CMAKE_CURRENT_LIST_DIR}/modules/UseQt5.cmake)

      if (NOT UNIX)
         set(_QtWebProcess "QtWebProcess.exe")
         set(_QtWebEngineProcess "QtWebEngineProcess.exe")
         set(_QtWebEngineProcess_debug "QtWebEngineProcess-debug.exe")
         set(_QtWebEngineProcess_debug_2 "QtWebEngineProcessd.exe")
      endif()

      find_file(Qt5_QtWebProcess ${_QtWebProcess} PATHS "${_qt5Core_install_prefix}/bin" NO_DEFAULT_PATH NO_SYSTEM_ENVIRONMENT_PATH )
      find_file(Qt5_QtWebEngineProcess ${_QtWebEngineProcess} PATHS "${_qt5Core_install_prefix}/bin" NO_DEFAULT_PATH NO_SYSTEM_ENVIRONMENT_PATH )
      find_file(Qt5_QtWebEngineProcess_DBG ${_QtWebEngineProcess_debug} PATHS "${_qt5Core_install_prefix}/bin" NO_DEFAULT_PATH NO_SYSTEM_ENVIRONMENT_PATH )
      
      if (NOT Qt5_QtWebEngineProcess_DBG)
         find_file(Qt5_QtWebEngineProcess_DBG ${_QtWebEngineProcess_debug_2} PATHS "${_qt5Core_install_prefix}/bin" NO_DEFAULT_PATH NO_SYSTEM_ENVIRONMENT_PATH )
      endif()

 