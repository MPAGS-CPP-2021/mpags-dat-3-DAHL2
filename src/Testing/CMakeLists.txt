# Sub-scripts for MPAGSCipher library tests

# Create interface library for Catch
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(Catch INTERFACE cxx_noexcept)

# Hello world test
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# First Catch-based test
add_executable(testCatch testCatch.cpp)
target_link_libraries(testCatch Catch)
add_test(NAME test-catch COMMAND testCatch)

# Test TransformChar
add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar MPAGSCipher Catch)
add_test(NAME test-transformchar COMMAND testTransformChar)