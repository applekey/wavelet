cmake_minimum_required(VERSION 2.8.9)
project (wave)

file(GLOB wave_SRC
    "*.h"
    "*.cpp"
)

add_executable(wave ${wave_SRC})
