cmake_minimum_required(VERSION 3.5)
project(mars_interfaces VERSION 2.0.0 DESCRIPTION "This library is the base library for the MARS prject and includes the general defines, structs and classes.")


include(FindPkgConfig)

find_package(lib_manager)
lib_defaults()
define_module_info()

#This adds base-lib to the package-config as dep.

pkg_check_modules(PKGCONFIG REQUIRED
        configmaps
        data_broker
        mars_utils
        base-types
)
set(LIB_DEPS "base-lib configmaps data_broker mars_utils")

include_directories(${PKGCONFIG_INCLUDE_DIRS})
link_directories(${PKGCONFIG_LIBRARY_DIRS})
add_definitions(${PKGCONFIG_CLFAGS_OTHER})  #flags excluding the ones with -I

include_directories(src)


set(HEADERS
    src/Logging.hpp
    src/cameraStruct.h
    src/ConfigMapInterface.hpp
    src/ContactData.hpp
    src/contact_params.h
    src/ControllerData.h
    src/core_objects_exchange.h
    src/GraphicData.h
    src/JointData.h
    src/LightData.h
    src/MARSDefs.h
    src/MaterialData.h
    src/MotorData.h
    src/nodeState.h
    src/NodeData.h
    src/ContactData.hpp
    src/sensor_bases.h
    src/sim_common.h
    src/snmesh.h
    src/terrainStruct.h
    src/utils.h
    src/EnvireUtils.hpp
    src/sim/DynamicObject.hpp
    src/sim/ItemPlugin.hpp
    src/exceptions/SceneParseException.h
)

set(SOURCES
    src/sim/AbsolutePose.cpp
    src/sim/ControlCenter.cpp
    src/sim/IDManager.cpp
    src/sim/LoadCenter.cpp
    src/MaterialData.cpp
    src/NodeData.cpp
    src/JointData.cpp
    src/MotorData.cpp
    src/LightData.cpp
    src/GraphicData.cpp
    src/ControllerData.cpp
    src/utils.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_link_libraries(
        ${PROJECT_NAME}
        ${PKGCONFIG_LIBRARIES}
)


if(WIN32)
  set(LIB_INSTALL_DIR bin) # .dll are in PATH, like executables
else(WIN32)
  set(LIB_INSTALL_DIR lib)
endif(WIN32)

set(_INSTALL_DESTINATIONS
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION ${LIB_INSTALL_DIR}
	ARCHIVE DESTINATION lib
)

# Install the library
install(TARGETS ${PROJECT_NAME} ${_INSTALL_DESTINATIONS})

# Install headers into mars include directory
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})

FILE(GLOB files "src/graphics/*.h")
install(FILES ${files} DESTINATION include/${PROJECT_NAME}/graphics)
FILE(GLOB files "src/sim/*.h")
install(FILES ${files} DESTINATION include/${PROJECT_NAME}/sim)
FILE(GLOB files "src/sim/*.hpp")
install(FILES ${files} DESTINATION include/${PROJECT_NAME}/sim)
FILE(GLOB files "src/gui/*.h")
install(FILES ${files} DESTINATION include/${PROJECT_NAME}/gui)

# Prepare and install necessary files to support finding of the library
# using pkg-config
configure_file(${PROJECT_NAME}.pc.in ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc DESTINATION lib/pkgconfig)

# documentation
configure_file(${CMAKE_SOURCE_DIR}/doc/Doxyfile.in ${CMAKE_BINARY_DIR}/doc/Doxyfile @ONLY)
add_custom_target(doc
  COMMAND doxygen ${CMAKE_BINARY_DIR}/doc/Doxyfile
)


