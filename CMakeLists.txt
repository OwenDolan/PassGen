CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(PASSGEN)

ADD_EXECUTABLE(PassGen
    src/passgen.cpp   
    src/generator.cpp 
    src/encrypt.cpp
)