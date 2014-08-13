include (${project_cmake_dir}/FindSSE.cmake)

if (SSE2_FOUND)
  set (CMAKE_C_FLAGS_ALL "-msse -msse2 ${CMAKE_C_FLAGS_ALL}")
  if (NOT APPLE)
    set (CMAKE_C_FLAGS_ALL "-mfpmath=sse ${CMAKE_C_FLAGS_ALL}")
  endif()
endif()

if (SSE3_FOUND)
  set (CMAKE_C_FLAGS_ALL "-msse3 ${CMAKE_C_FLAGS_ALL}")
endif()
if (SSSE3_FOUND)
  set (CMAKE_C_FLAGS_ALL "-mssse3 ${CMAKE_C_FLAGS_ALL}")
endif()

if (ENABLE_SSE4)
  message(STATUS "\nSSE4 will be enabled if system supports it.\n")
  if (SSE4_1_FOUND)
    set (CMAKE_C_FLAGS_ALL "-msse4.1 ${CMAKE_C_FLAGS_ALL}")
  endif()
  if (SSE4_2_FOUND)
    set (CMAKE_C_FLAGS_ALL "-msse4.2 ${CMAKE_C_FLAGS_ALL}")
  endif()
else()
  message(STATUS "\nSSE4 disabled.\n")
endif()

