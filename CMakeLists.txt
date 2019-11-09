cmake_minimum_required (VERSION 3.0)
project(tinyui4sfml)

set(CMAKE_BUILD_TYPE Release)

#######################################
# Inclusion and libraries
#######################################

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules/)

find_package(SFML COMPONENTS network graphics window system REQUIRED)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	find_package(X11 REQUIRED)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

include_directories(
	${SFML_INCLUDE_DIR}
	Properties
	Elements
	InterfaceManager
	Examples/sfml/
	Examples/sfml/Screen/
)

#######################################
# Variable settings
#######################################

set(HAL
  Examples/sfml/Screen/Screen.h
  Examples/sfml/Screen/Screen.cpp
)

set(APP
  Examples/sfml/main.cpp
)

set(TINY_UI
  Properties/Position.h
  Properties/Size.h
  Properties/Color.h
  Properties/Moveable.h
  Properties/Moveable.cpp
  Properties/Resizeable.h
  Properties/Resizeable.cpp
  Properties/Colorable.h
  Properties/Colorable.cpp
  Elements/Box.h
  Elements/Box.cpp
  Elements/TextBox.h
  Elements/TextBox.cpp
  Elements/Button.h
  Elements/Button.cpp
  Elements/ProgressBar.h
  Elements/ProgressBar.cpp
  Elements/Widget.h
  Elements/Widget.cpp
  Elements/View.h
  Elements/View.cpp
  Widgets/Weekendar.h
  Widgets/Weekendar.cpp
  Painter/Painter.h
  Painter/Painter.cpp
  InterfaceManager/InterfaceManager.h
  InterfaceManager/InterfaceManager.cpp
)

#######################################
# Compilation and linking
#######################################

add_executable(tinyui4sfml
	${HAL}
	${TINY_UI}
	${APP}
)

target_link_libraries(tinyui4sfml ${SFML_LIBRARIES} ${X11_LIBRARIES})
