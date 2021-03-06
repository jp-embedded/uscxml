############################################################
# Actual files of core library
############################################################

file(GLOB_RECURSE USCXML_INTERPRETERS
	interpreter/*.cpp
	interpreter/*.h
)
source_group("Interpreter" FILES ${USCXML_INTERPRETERS})
list (APPEND USCXML_FILES ${USCXML_INTERPRETERS})


file(GLOB_RECURSE USCXML_MESSAGES
	messages/*.cpp
	messages/*.h
)
source_group("Interpreter" FILES ${USCXML_MESSAGES})
list (APPEND USCXML_FILES ${USCXML_MESSAGES})


file(GLOB_RECURSE USCXML_DEBUG
	debug/*.cpp
	debug/*.h
)
source_group("Interpreter" FILES ${USCXML_DEBUG})
list (APPEND USCXML_FILES ${USCXML_DEBUG})


file(GLOB_RECURSE USCXML_MISC
  util/*.cpp
  util/*.hpp
  util/*.c
	util/*.h
)

# Add URL.mm for MacOS / iOS
if(APPLE OR IOS)
	file(GLOB USCXML_APPLE util/*.mm)
	list (APPEND USCXML_MISC ${USCXML_APPLE})
	find_library(FOUNDATION_FRAMEWORK Foundation)
	list (APPEND USCXML_CORE_LIBS ${FOUNDATION_FRAMEWORK})
endif()

source_group("Interpreter" FILES ${USCXML_MISC})
list (APPEND USCXML_FILES ${USCXML_MISC})


file(GLOB USCXML_SERVER
	server/*.cpp
	server/*.h
)
source_group("Interpreter" FILES ${USCXML_SERVER})
list (APPEND USCXML_FILES ${USCXML_SERVER})


file(GLOB USCXML_CORE
  ${CMAKE_SOURCE_DIR}/contrib/src/jsmn/jsmn.c
  ${CMAKE_SOURCE_DIR}/contrib/src/evws/evws.c
  ${CMAKE_SOURCE_DIR}/contrib/src/uriparser/src/*.c
	*.cpp
	*.h
)
source_group("Interpreter" FILES ${USCXML_CORE})
list (APPEND USCXML_FILES ${USCXML_CORE})

file(GLOB USCXML_PLUGINS
	plugins/*.cpp
	plugins/*.h
)

source_group("Interpreter" FILES ${USCXML_PLUGINS})
list (APPEND USCXML_FILES ${USCXML_PLUGINS})

file(GLOB_RECURSE USCXML_TRANSFORM
	transform/*.cpp
	transform/*.h
)
source_group("Interpreter" FILES ${USCXML_TRANSFORM})
list (APPEND USCXML_TRANSFORM_FILES ${USCXML_TRANSFORM})

if (BUILD_AS_PLUGINS)
	file(GLOB_RECURSE PROMELA_PARSER
		plugins/datamodel/promela/parser/*.cpp
		plugins/datamodel/promela/PromelaParser.cpp
	)
	list (APPEND USCXML_TRANSFORM_FILES ${PROMELA_PARSER})
	
endif()

add_subdirectory(plugins/datamodel)
add_subdirectory(plugins/element)
add_subdirectory(plugins/invoker)
add_subdirectory(plugins/ioprocessor)

SET(WITH_IOPROC_HTTP_TIMEOUT ${WITH_IOPROC_HTTP_TIMEOUT} PARENT_SCOPE)
SET(USCXML_INVOKERS ${USCXML_INVOKERS} PARENT_SCOPE)
SET(USCXML_IOPROCESSORS ${USCXML_IOPROCESSORS} PARENT_SCOPE)
SET(USCXML_ELEMENTS ${USCXML_ELEMENTS} PARENT_SCOPE)
SET(USCXML_DATAMODELS ${USCXML_DATAMODELS} PARENT_SCOPE)
# SET(USCXML_LANGUAGE_BINDINGS ${USCXML_LANGUAGE_BINDINGS} PARENT_SCOPE)
#
# set(USCXML_INCLUDE_DIRS ${USCXML_INCLUDE_DIRS} PARENT_SCOPE)
# set(USCXML_OPT_LIBS ${USCXML_OPT_LIBS} PARENT_SCOPE)
set(USCXML_FILES ${USCXML_FILES} PARENT_SCOPE)
set(USCXML_TRANSFORM_FILES ${USCXML_TRANSFORM_FILES} PARENT_SCOPE)
set(USCXML_CORE_LIBS ${USCXML_CORE_LIBS} PARENT_SCOPE)
# SET(PLUMA ${PLUMA} PARENT_SCOPE)