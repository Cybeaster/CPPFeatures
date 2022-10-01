project(CPPFeatures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CUDA_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED)


add_executable(exec
main.cpp
main.hpp
Cpp11/CoreLanguageFeatures/Preprocessor/Derectives.hpp
)
