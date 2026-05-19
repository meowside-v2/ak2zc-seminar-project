cmake_minimum_required(VERSION 3.10.0)
project(cv2-pr2-calc VERSION 0.1.0 LANGUAGES C)

add_executable(cv2-pr2-calc main.c
    io.h
    io.c
    calculator.c
    calculator.h)

