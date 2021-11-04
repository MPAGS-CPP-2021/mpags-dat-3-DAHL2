# Build sub-script for MPAGSCipher library

# Declare the build of the static MPAGSCipher library
#   N.B. static means the library is contained within the
#   executable, rather than needing a separate file
add_library(MPAGSCipher STATIC
  CaesarCipher.cpp
  CaesarCipher.hpp
  CipherMode.hpp
  ProcessCommandLine.cpp
  ProcessCommandLine.hpp
  TransformChar.cpp
  TransformChar.hpp
)

target_include_directories(MPAGSCipher
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}
  )

target_compile_features(MPAGSCipher
  PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
  )