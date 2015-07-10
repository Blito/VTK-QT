cmake_minimum_required(VERSION 2.8.11)

if(POLICY CMP0020)
  cmake_policy(SET CMP0020 NEW)
endif()

project(testproject)

set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.5.0/5.5/mingw492_32/lib/cmake/Qt5Widgets")

set(VTK_DIR "C:/Simeco/lab/VTK-SFML/lib/VTK/build/release")

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

# Find includes in corresponding build directories
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED QUIET)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB UI_FILES *.ui)
file(GLOB QT_WRAP *.h)
file(GLOB CXX_FILES *.cxx)
file(GLOB CPP_FILES *.cpp)

qt5_wrap_ui(UISrcs ${UI_FILES} )
# CMAKE_AUTOMOC in ON so the MocHdrs will be automatically wrapped.
add_executable(helloworld MACOSX_BUNDLE main.cpp ${CXX_FILES} ${CPP_FILES} ${UISrcs} ${QT_WRAP})
qt5_use_modules(helloworld Core Gui)
target_link_libraries(helloworld ${VTK_LIBRARIES})

# Tell CMake to create the helloworld executable
#add_executable(helloworld WIN32 main.cpp SideBySideRenderWindowsQt.cxx)

# Use the Widgets module from Qt 5.
#target_link_libraries(helloworld Qt5::Widgets)
