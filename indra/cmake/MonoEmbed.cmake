# -*- cmake -*-

include(Prebuilt)
use_prebuilt_binary(libmono)

SET(GLIB_2_0 glib-2.0)

if (WINDOWS)
    SET(MONO_LIB mono) 
else (WINDOWS)
    SET(MONO_LIB mono)
    SET(M_LIBRARIES m)
    SET(GTHREAD_2_0 gthread-2.0)
endif(WINDOWS)


IF (DARWIN)

  FIND_LIBRARY(MONO_LIBRARY NAMES Mono)
  # Find_file doesnt work as expected. Hardcode relative to Mono.framework. 
  #FIND_FILE(GLIB_CONFIG glibconfig.h ${MONO_LIBRARY})
  #FIND_FILE(MONO_GLIB_LIBRARY glib.h ${MONO_LIBRARY})
  SET(MONO_GLIB_LIBRARY ${MONO_LIBRARY}/Headers/glib-2.0/)
  SET(GLIB_CONFIG ${MONO_LIBRARY}/Libraries/glib-2.0/include/)
  SET(MONO_LIB_DIRECTORY ${MONO_LIBRARY}/Libraries)

  IF (MONO_LIBRARY AND MONO_GLIB_LIBRARY AND GLIB_CONFIG)
    MESSAGE(STATUS "Found Mono for embedding")
    INCLUDE_DIRECTORIES(${MONO_GLIB_LIBRARY} ${GLIB_CONFIG})
    LINK_DIRECTORIES(${MONO_LIB_DIRECTORY})
  ELSE (MONO_LIBRARY AND MONO_GLIB_LIBRARY AND GLIB_CONFIG)
    MESSAGE(FATAL_ERROR "Mono not found for embedding")   
    MESSAGE(${MONO_LIBRARY})
    MESSAGE(${MONO_GLIB_LIBRARY})
    MESSAGE(${GLIB_CONFIG})
  ENDIF (MONO_LIBRARY AND MONO_GLIB_LIBRARY AND GLIB_CONFIG)

ELSE (DARWIN)

  SET(MONO_INCLUDE_DIR ${LIBS_PREBUILT_DIR}/include)  
  SET(GLIB_2_0_PLATFORM_INCLUDE_DIR
    ${LIBS_PREBUILT_DIR}/include/glib-2.0)
  SET(GLIB_2_0_INCLUDE_DIR ${LIBS_PREBUILT_DIR}/include/glib-2.0)

  INCLUDE_DIRECTORIES(
    ${MONO_INCLUDE_DIR} 
    ${GLIB_2_0_PLATFORM_INCLUDE_DIR} 
    ${GLIB_2_0_INCLUDE_DIR})
    
ENDIF (DARWIN) 

SET(MONO_LIBRARIES 
    ${MONO_LIB} 
    ${M_LIBRARIES} 
    ${GLIB_2_0}
    ${GTHREAD_2_0} 
)
