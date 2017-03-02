all: src test

test_.o:
	gcc -Wall -c test/test_builtin.c builtin.o
	gcc -Wall -c test/test_local.c local.o
	gcc -Wall -c test/test_path.c path.o
	gcc -Wall -c test/test_qotd.c qotd.o
	gcc -Wall -c test/test_parse.c parse.o

runtest.o:
	gcc -Wall -c test/runtest.c

builtin.o:
	gcc -Wall -c src/builtin.c

local.o:
	gcc -Wall -c src/local.c

path.o:
	gcc -Wall -c src/path.c

qotd.o:
	gcc -Wall -c src/qotd.c

parse.o:
	gcc -Wall -c src/parse.c

src: builtin.o local.o path.o qotd.o parse.o
	gcc -Wall -o psh src/main.c *.o

test: builtin.o local.o path.o qotd.o parse.o test_.o runtest.o
	gcc -Wall -o runtest test/test.c test_*.o runtest.o
	./runtest

clean:
	rm -f *.o psh runtest
