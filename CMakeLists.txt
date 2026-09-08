# tells CMake "don't run me if your CMake version is older than 3.10." Required, no exceptions.
cmake_minimum_required(VERSION  3.10)
# names your project
project(CmakePractice)

add_library(mymath STATIC mymath.cpp)
# creates a target called mymath, built as a static library (.a file) from mymath.cpp ---- WE R BUILDING THE LIB other cases we have the lib

# creates a build target called hello (this becomes the binary's name) compiled from main.cpp.
add_executable(hello prac.cpp)
target_link_libraries(hello PRIVATE mymath)
# tells CMake "the hello executable needs mymath at link time."
# PRIVATE means: this linking requirement is internal to hello. If something else later linked against hello itself (rare for an executable, but common for libraries), it wouldn't automatically also get mymath. You'll almost always use PRIVATE unless you're building a library whose public header exposes another library's types.


