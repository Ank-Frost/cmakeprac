add_library(mymath STATIC mymath.cpp)
target_include_directories(mymath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Two new things here:

# No cmake_minimum_required/project() — only the top-level CMakeLists.txt needs those. Subdirectory files just add targets.

# target_include_directories(mymath PUBLIC ...) — now that mymath.h isn't next to main.cpp anymore, whoever links against mymath needs its include path too. 
# PUBLIC means: "this include path applies to mymath itself, and propagates to anything that links against mymath." 
# That's exactly what main.cpp needs — it never has to know or care where mymath.h physically lives.

