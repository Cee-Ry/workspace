#!/bin/bash

mkdir -p $HOME/.local/bin

echo "Compiling..."
g++ -std=c++23 -Iinclude src/*.cpp -o ./workspace -O3

echo "Installing..."
mv ./workspace $HOME/.local/bin/workspace

echo "DONE!"
