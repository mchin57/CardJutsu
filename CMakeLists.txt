cmake_minimum_required(VERSION 3.21)
project(CardJutsu)

set(CMAKE_CXX_STANDARD 14)

add_executable(CardJutsu main.cpp card.cpp card.h hand.cpp hand.h Deck.cpp Deck.h utils.cpp utils.h)
