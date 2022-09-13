#!/bin/bash
g++ -o -no-pie -pg ../src/Main.cpp ../src/Histogram.cpp ../src/KMeans.cpp ../src/Quantization.cpp ../src/Utils.cpp -lsfml-graphics -lsfml-window -lsfml-system
./a.out ../src/img.jpg 16
gprof -E -b a.out gmon.out > analysis.out




