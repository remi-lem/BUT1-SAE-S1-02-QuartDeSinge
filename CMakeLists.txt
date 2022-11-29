cmake_minimum_required(VERSION 3.23)
project(BUT1_SAE_S1_02)
set(CMAKE_CXX_STANDARD 14)

add_executable(BUT1_SAE_S1_02 main.cpp joueurs.cpp dico.cpp manche.cpp manche.h)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "..")
