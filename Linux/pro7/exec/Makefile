.PHONY:all
all:exec myprogma

exec:exec.c
	gcc -o $@ $^
myprogma:myprogma.cc
	g++ -o $@ $^ -std=c++11
.PHONY:clean
clean:
	rm -f exec myprogma