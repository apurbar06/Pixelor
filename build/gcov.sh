#!/bin/bash
g++ -fprofile-arcs -ftest-coverage ../src/Main.cpp ../src/Histogram.cpp ../src/KMeans.cpp ../src/Quantization.cpp ../src/Utils.cpp -lsfml-graphics -lsfml-window -lsfml-system
./a.out ../src/img.jpg 16
gcov -b -c Main.cpp
gcov -b -c Utils.cpp
gcov -b -c Quantization.cpp
gcov -b -c KMeans.cpp
gcov -b -c Histogram.cpp