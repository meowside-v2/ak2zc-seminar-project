# CMakeList.txt : CMake project for david-knieradl_ak2zc_seminar, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("david-knieradl_ak2zc_seminar")

# Add source to this project's executable.
add_executable (david-knieradl_ak2zc_seminar "david-knieradl_ak2zc_seminar.c" "david-knieradl_ak2zc_seminar.h")
set_property(TARGET david-knieradl_ak2zc_seminar PROPERTY C_STANDARD 11)

if (CMAKE_VERSION VERSION_GREATER 3.12)
endif()

# TODO: Add tests and install targets if needed.
