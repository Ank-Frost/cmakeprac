#finding and lnking crypto++ to prac.cpp

# tells CMake "don't run me if your CMake version is older than 3.10." Required, no exceptions.
cmake_minimum_required(VERSION  3.10)
# names your project
project(CmakePractice)

add_library(mymath STATIC mymath.cpp)
# creates a target called mymath, built as a static library (.a file) from mymath.cpp ---- WE R BUILDING THE LIB other cases we have the lib

add_executable(hello prac.cpp)
# creates a build target called hello (this becomes the binary's name) compiled from main.cpp.

target_link_libraries(hello PRIVATE mymath)
# tells CMake "the hello executable needs mymath at link time."
# PRIVATE means: this linking requirement is internal to hello. If something else later linked against hello itself (rare for an executable, but common for libraries), it wouldn't automatically also get mymath. You'll almost always use PRIVATE unless you're building a library whose public header exposes another library's types.

#------new
find_library(CRYPTOPP_LIB cryptopp REQUIRED)
#find crypto++ in sys lib paths and store the path in variable CRYPTOPP_LIB 
find_path(CRYPTOPP_INCLUDE_DIR cryptopp/aes.h REQUIRED)
#find_path does the same thing but for a header file, storing the parent directory (/usr/include not /usr/include/cryptopp/aes.h) in CRYPTOPP_INCLUDE_DIR.
#stores the parent directory you'd need to add to your include path

#manually feed them into target_include_directories and target_link_libraries
target_include_directories(hello PRIVATE ${CRYPTOPP_INCLUDE_DIR})
target_link_libraries(hello PRIVATE ${CRYPTOPP_LIB})

#This is the exact difference between "library has CMake support" (zlib, OpenSSL — clean find_package) vs "library doesn't" (Crypto++ in most cases — manual find_library/find_path).