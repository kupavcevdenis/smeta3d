######################################################################################
#                                                                                    #
#        Smeta3d Project                                                             #
#                                                                                    #
#                                                                                    #
#  All rights reserved.                                                              #
#  Welcome to the CMake build                                                        #
######################################################################################

cmake_minimum_required(VERSION 2.8.1 FATAL_ERROR)
cmake_policy(VERSION 2.8.1)

######################################################################################
set(CMAKE_VERBOSE_MAKEFILE false)           # high verbosity setting in make files and VS
set(CMAKE_USE_RELATIVE_PATHS true)          # Use relative paths
set(CMAKE_SUPPRESS_REGENERATION false)      # hide CMakeLists.txt
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true) # Allow empty endif() and such with CMake 2.4.

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "Predefined (Cmake) targets folder" )

######################################################################
# Just debug / release since that's all that's included in SDK
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" )

#####################################################################
# Setup version build 
set(SMT3D_VERSION_MAJOR 1)     #Version MAJOR
set(SMT3D_VERSION_MINOR 0)     #Version MINOR 
set(SMT3D_VERSION_PATCH 0)     #Version PATCH
set(SMT3D_VERSION_NAME  "Summer")  #Version NAME
set(SMT3D_VERSION_SUFFIX "devel")   #Version SUFFIX

set( SMT3D_VERSION ${SMT3D_VERSION_MAJOR}.${SMT3D_VERSION_PATCH} )
set( PROJECT_NAME_SMT3D smeta3d-${SMT3D_VERSION_SUFFIX}-${SMT3D_VERSION} )

set( CURRENT_VERSION ${SMT3D_VERSION} )
set( CURRENT_VERSION_MAJOR ${SMT3D_VERSION_MAJOR} )

message(STATUS "Configure Root project: ${PROJECT_NAME_SMT3D}")
project( ${PROJECT_NAME_SMT3D} )

set(SMT3D_SRC_DIR ${${PROJECT_NAME_SMT3D}_SOURCE_DIR})
set(SMT3D_BUILD_DIR ${${PROJECT_NAME_SMT3D}_BINARY_DIR})

set( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake"
                       "${CMAKE_MODULE_PATH}" )

					   
enable_language(C)
enable_language(CXX)

include(make_default_output_directory)

make_default_output_directory( ${PROJECT_BINARY_DIR} ) 		

##   set(WINVER "0x0501" CACHE STRING "WINVER version (see MSDN documentation)") #Windows XP and newer
   add_definitions(-DPSAPI_VERSION=1) #compatibility Windows XP for build in Windows 7

   # Replace /INCREMENTAL:NO[YES] by /INCREMENTAL:NO.
   string(REGEX REPLACE "/INCREMENTAL[0-Y]*" "" CMAKE_EXE_LINKER_FLAGS_DEBUG    "${CMAKE_EXE_LINKER_FLAGS_DEBUG}" ) 
   string(REGEX REPLACE "/INCREMENTAL[0-Y]*" "" CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS_DEBUG}" ) 
   string(REGEX REPLACE "/INCREMENTAL[0-Y]*" "" CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_MODULE_LINKER_FLAGS_DEBUG}" ) 

   set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /INCREMENTAL:NO")
   set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} /INCREMENTAL:NO")
   set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_MODULE_LINKER_FLAGS_DEBUG} /INCREMENTAL:NO")

if (MSVC_VERSION GREATER 1599)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP") # Multi-processor Compilation
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8) # x64
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WIN64")
   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_WIN64")
endif()

   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zm300") #error C3859: virtual memory range for PCH exceeded
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /EHa /fp:except-") #high warning level with C++ and SEH exceptions
   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Oi") # Enable intrinsics on MSVC in debug mode
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj") # increases the number of sections that an object file can contain.

   if (CMAKE_SIZEOF_VOID_P EQUAL 8) #x64
      set( GLOB_LINKER_FLAGS "${GLOB_LINKER_FLAGS} /MACHINE:X64" )
   else()
      set( GLOB_LINKER_FLAGS "${GLOB_LINKER_FLAGS} /MACHINE:X86 /LARGEADDRESSAWARE" )
   endif()
		
include(find_dependencies)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory( "source/run" "source/run" ) #Library's location
add_subdirectory( "source/kernel" "source/kernel" ) #Library's location
add_subdirectory( "source/gui_basis" "source/gui_basis" ) #Library's location
###################################################################
## determine if we are compiling for a 32bit or 64bit system
## it's did not work ???
#if(CMAKE_SIZEOF_VOID_P EQUAL 8)
#	set(MSVS_PLATFORM_X64 TRUE)
#endif()
#
#if(MSVS_PLATFORM_X64)
#	set( GLOB_LINKER_FLAGS "${GLOB_LINKER_FLAGS} /MACHINE:X64" )
#	message("----------------------------- use MS VS x64 ----------------------------")
#else()
#    set( GLOB_LINKER_FLAGS "${GLOB_LINKER_FLAGS} /MACHINE:X86 /LARGEADDRESSAWARE" )
#	message("----------------------------- use MS VS x86 ----------------------------")
#endif()
#
#if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
#    # We don't want to install in default system location, install is really for the SDK, so call it that
#    set( CMAKE_INSTALL_PREFIX "${IRIS_PLUGINS_BUILD_DIR}/${PROJECT_NAME_IRIS_PLUGINS}" CACHE PATH "EIMS install prefix" FORCE )
#endif ()
#
#if(MSVS_PLATFORM_X64)
#	set(3DSMAX_INSTALL_PATH $ENV{ADSK_3DSMAX_x64_2012} CACHE STRING "" FORCE)
#else()
#	set(3DSMAX_INSTALL_PATH $ENV{ADSK_3DSMAX_x32_2012} CACHE STRING "" FORCE)
#endif()
#
#set(3DSMAX_INSTALL_PATH "C:\\Program Files (x86)\\Autodesk\\3ds Max 2012")
#
#######################################################################################
#if (MSVC_VERSION GREATER 1499 AND MSVC_VERSION LESS 1600)
#
#	# default installation path for 3ds Max SDK
#	set(3DSMAX_SDK_2010_SDK_PATH  "C:/Program Files/Autodesk/3ds Max 2010 SDK/")
#	
#	# system environment for install 3ds max
#	#   3DSMAX_2011_SDK_PATH - x86 or 3DSMAX_2011x64_PATH  - x64 build IDE: Visual C++ 9.0
#	#   ADSK_3DSMAX_SDK_2012 - x86 or ADSK_3DSMAX_x64_2012 - x64 build IDE: Visual C++ 9.0
#	
#	if(!3DSMAX_XXXX_SDK_PATH)
#		message( "!!!Please set 3dsMax version!!!" )
#		return()
#	endif()
#	
#	find_path(3DSMAX10_SDK_INCLUDE_DIR NAMES max.h HINTS ${3DSMAX_SDK_2010_SDK_PATH} PATH_SUFFIXES "maxsdk/include")
#	find_path(3DSMAX11_SDK_INCLUDE_DIR NAMES max.h HINTS ${3DSMAX_2011_SDK_PATH} PATH_SUFFIXES "maxsdk/include")
#	find_path(3DSMAX12_SDK_INCLUDE_DIR NAMES max.h HINTS ${3DSMAX_INSTALL_PATH} PATH_SUFFIXES "maxsdk/include")
#	
#	if(3DSMAX10_SDK_INCLUDE_DIR)
#		set( 3DSMAX10 3dsMax2010 )
#		list( APPEND CUSTOM_BUILD_TYPES ${3DSMAX10} )
#		message("3DSMAX10_SDK_INCLUDE_DIR-FOUND")
#	else()
#		message( "${3DSMAX10_SDK_INCLUDE_DIR}" )
#	endif()
#
#	if(3DSMAX11_SDK_INCLUDE_DIR)
#		set( 3DSMAX11 3dsMax2011 )
#		list( APPEND CUSTOM_BUILD_TYPES ${3DSMAX11} )
#		message("3DSMAX11_SDK_INCLUDE_DIR-FOUND")
#	else()
#		message( "${3DSMAX11_SDK_INCLUDE_DIR}" )
#	endif()
#
#	if(3DSMAX12_SDK_INCLUDE_DIR)
#		set( 3DSMAX12 3dsMax2012 )
#		list( APPEND CUSTOM_BUILD_TYPES ${3DSMAX12} )
#		message("3DSMAX12_SDK_INCLUDE_DIR-FOUND")
#	else()
#		message( "${3DSMAX12_SDK_INCLUDE_DIR}" )
#	endif()
#	
#	list(LENGTH CUSTOM_BUILD_TYPES CUSTOM_BUILD_TYPES_NUM_ELEM)
#	if(NOT CUSTOM_BUILD_TYPES_NUM_ELEM) # есть ли в списке найденные пути к версиям 3ds Max SDK
#		message( "not found 3ds Max SDK in default installation path for this version of MS Visual Studio" )
#		return()
#	endif()
#	
#	#set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
#	#set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "Configurations" FORCE) #"${CUSTOM_BUILD_TYPES}"
#	set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE) 
#	
#	include(${CMAKE_SOURCE_DIR}/cmake/configuration_3ds_max.cmake)	
#	
#endif()
#
#
#######################################################################################
## find 3ds Max sdk
#set( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" )
#find_package(3DSMAX_SDK)
#
#######################################################################################
##
##if(NOT 3DSMAX_SDK_FOUND)
#	#message("----------------------------- 3DSMAX_SDK not found ----------------------------")
#	#return()
##endif()
#
#
#######################################################################################
## Create the IrisExportUtility library for 3ds max.
#add_subdirectory(export)
#add_subdirectory(import)
#add_subdirectory(utility)
#
#
#
####################################################################
##                          install
#
#install(FILES "${IRIS_PLUGINS_SRC_DIR}/scripts/IrisMenu.ms" DESTINATION "Scripts/Startup" CONFIGURATIONS Release)
##install(FILES "IrisExport.dle" DESTINATION "plugins" CONFIGURATIONS Release)
#if(MSVS_PLATFORM_X64)
#	install(FILES "${IRIS_PLUGINS_BUILD_DIR}/export/${CMAKE_CONFIGURATION_TYPES}/IrisExport.dle" DESTINATION "plugins" CONFIGURATIONS Release)
#	install(FILES "${IRIS_PLUGINS_BUILD_DIR}/import/${CMAKE_CONFIGURATION_TYPES}/IrisImport.dli" DESTINATION "plugins" CONFIGURATIONS Release)
#	install(FILES "${IRIS_PLUGINS_BUILD_DIR}/utility/${CMAKE_CONFIGURATION_TYPES}/IrisExportUtility.dlu" DESTINATION "plugins" CONFIGURATIONS Release)
#else()
#	install(FILES "${IRIS_PLUGINS_BUILD_DIR}/export/${CMAKE_CONFIGURATION_TYPES}/IrisExport.dle" DESTINATION "plugins" CONFIGURATIONS Release)
#	install(FILES "${IRIS_PLUGINS_BUILD_DIR}/import/${CMAKE_CONFIGURATION_TYPES}/IrisImport.dli" DESTINATION "plugins" CONFIGURATIONS Release)
#	install(FILES "${IRIS_PLUGINS_BUILD_DIR}/utility/${CMAKE_CONFIGURATION_TYPES}/IrisExportUtility.dlu" DESTINATION "plugins" CONFIGURATIONS Release)
#endif()
#
#
####################################################################
## Provide CPack packaging target
#set(CPACK_PACKAGE_NAME "iris 3ds Max plugins")
#set(CPACK_PACKAGE_VERSION ${IRIS_PLUGINS_VERSION})
#set(CPACK_PACKAGE_VERSION_MAJOR ${IRIS_PLUGINS_VERSION_MAJOR})
#set(CPACK_PACKAGE_VERSION_MINOR ${IRIS_PLUGINS_VERSION_MINOR})
#set(CPACK_PACKAGE_VERSION_PATCH ${IRIS_PLUGINS_VERSION_PATCH})
#set(CPACK_PACKAGE_VENDOR "JSC RPA RusBITech")
#set(CPACK_PACKAGE_CONTACT "<kvi@rusbitech.ru>")
#set(CPACK_NSIS_URL_INFO_ABOUT "www.rusbitech.ru")
#set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Plugins reflect 3d")
#set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES\\\\Autodesk\\\\")
#set(CPACK_PACKAGE_INSTALL_DIRECTORY "${PROJECT_NAME_IRIS_PLUGINS}")
#set(CPACK_RESOURCE_FILE_LICENSE "${IRIS_PLUGINS_SRC_DIR}/LICENSE.TXT")
#set(CPACK_NSIS_DISPLAY_NAME ${PROJECT_NAME_IRIS_PLUGINS})
#
##set(CPACK_INSTALL_CMAKE_PROJECTS "${WS3D_BINARY_DIR}" "WS3D" "ALL" "/")
##set(CPACK_PACKAGE_ICON "${WS3D_SRC_DIR}\\\\ws3dlogo.gif")
##set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS "WriteRegStr \\\${WriteEnvStr_RegKey} \\\"WS3D_HOME\\\" $INSTDIR")
#
#include(CPack)
###################################################################	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	