#!/bin/bash


if [ -d "build" ]; then
  rm -r build
fi

mkdir build

cd build

cmake ..

if [ -f "../compile_commands.json" ]; then
  rm ../compile_commands.json
fi

cp compile_commands.json ../compile_commands.json 
