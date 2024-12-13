CC = clang
FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
INC = -Iinc
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)

all: libmx.a

libmx.a: $(OBJ)
	ar rcs libmx.a $(OBJ)

obj/%.o: src/%.c | obj
	$(CC) $(FLAGS) $(INC) -c $< -o $@

obj:
	mkdir obj

clean:
	rm -r obj

uninstall:
	rm -r obj libmx.a

reinstall:
	make uninstall
	make