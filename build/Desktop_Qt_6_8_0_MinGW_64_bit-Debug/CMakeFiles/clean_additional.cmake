# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Xchat_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Xchat_autogen.dir\\ParseCache.txt"
  "Xchat_autogen"
  )
endif()
