build:
	@flex main.l
	@bison -d main.y
	@g++ main.cpp main.tab.c lex.yy.c -ll

clean:
	@rm -f a.out *.tab.c *.tab.h *.yy.c
