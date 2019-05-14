# Install script for directory: C:/Users/Admin/Desktop/LABS/All-labs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/All-labs")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Admin/Desktop/LABS/All-labs/Vector/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/VectorLib/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/VectorTest/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/gtest/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/ExceptionLib/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/Stack/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/StackLib/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/StackTest/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/Queue/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/QueueLib/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/QueueTest/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/List/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/ListLib/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/ListTest/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/ArrList/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/ArrListLib/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/ArrListTest/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/MultiStack/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/MultiStackLib/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/MultiStackTest/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/Polinom/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/PolinomLib/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/PolinomTest/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/StackList/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/StackListLib/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/StackListTest/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/Polish/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/PolishLib/cmake_install.cmake")
  include("C:/Users/Admin/Desktop/LABS/All-labs/PolishTest/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/Admin/Desktop/LABS/All-labs/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
