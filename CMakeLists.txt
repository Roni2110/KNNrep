cmake_minimum_required(VERSION 3.17)
project(KNNrep)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(KNNrep
        main.cpp Knn.cpp Knn.h DistanceClass.cpp DistanceClass.h)
