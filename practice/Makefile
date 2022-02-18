cc = g++
cflags = -Wall -std=c++14 -O3

source = src/main.cpp

all: src/main.cpp
	$(cc) $(cflags) $(source) -o bin/out 
	bin/out < input/a_an_example.in.txt > output/a_an_example.out.txt
	bin/out < input/b_basic.in.txt > output/b_basic.out.txt
	bin/out < input/c_coarse.in.txt > output/c_coarse.out.txt
	bin/out < input/d_difficult.in.txt > output/d_difficult.out.txt
	bin/out < input/e_elaborate.in.txt > output/e_elaborate.out.txt
