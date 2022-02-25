ifeq ($(GPP11), TRUE)
	cc := g++11
else
	cc := g++
endif

cflags = -Wall -std=c++14 -O3

source = src/main.cpp

all: src/main.cpp
	$(cc) $(cflags) $(source) -o "bin/out"
	"bin/out" < input/a.txt > output/a_an_example.out.txt
	"bin/out" < input/b.txt > output/b_basic.out.txt
	"bin/out" < input/c.txt > output/c_coarse.out.txt
	"bin/out" < input/d.txt > output/d_difficult.out.txt
	"bin/out" < input/e.txt > output/e_elaborate.out.txt
	"bin/out" < input/f.txt > output/f_elaborate.out.txt

