#!/bin/bash
g++ ../src/Main.cpp ../src/Histogram.cpp ../src/KMeans.cpp ../src/Quantization.cpp ../src/Utils.cpp -lsfml-graphics -lsfml-window -lsfml-system
./a.out ../src/img.jpg 16