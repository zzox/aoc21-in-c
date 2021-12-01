cc = gcc
sources = $(wildcard *.c)

mainfile = $(day)

run: clean test
	./test

test:
	@echo "Compiling"
	$(cc) $(mainfile)/main.c -o $@ $^
	@echo "Succeeded!"
	@echo "\n\n\n"

clean:
	rm -f test
