FIND_PATH(ARABICA_INCLUDE_DIR Arabica/getparam.hpp
  PATH_SUFFIXES arabica include
  PATHS
  /usr/local
  /usr
  /sw # Fink
  /opt/local # DarwinPorts
  /opt/csw # Blastwave
  /opt
  HINTS $ENV{ARABICA_SRC}
)
set(ARABICA_LIBRARY)
FIND_LIBRARY(ARABICA_LIBRARY_RELEASE
  NAMES arabica
  HINTS $ENV{ARABICA_SRC}/src/.libs/
)

FIND_LIBRARY(ARABICA_LIBRARY_DEBUG
  NAMES arabica_d arabica_debug
  HINTS $ENV{ARABICA_SRC}/src/.libs/
)

if (ARABICA_LIBRARY_RELEASE AND NOT ARABICA_LIBRARY_DEBUG)
	list(APPEND ARABICA_LIBRARY ${ARABICA_LIBRARY_RELEASE})
elseif(ARABICA_LIBRARY_DEBUG AND NOT ARABICA_LIBRARY_RELEASE)
	list(APPEND ARABICA_LIBRARY ${ARABICA_LIBRARY_DEBUG})
elseif(ARABICA_LIBRARY_DEBUG AND ARABICA_LIBRARY_RELEASE)
	list(APPEND ARABICA_LIBRARY optimized ${ARABICA_LIBRARY_RELEASE} debug ${ARABICA_LIBRARY_DEBUG})
endif()


INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Arabica DEFAULT_MSG ARABICA_LIBRARY ARABICA_INCLUDE_DIR)
MARK_AS_ADVANCED(ARABICA_LIBRARY_RELEASE ARABICA_LIBRARY_DEBUG)