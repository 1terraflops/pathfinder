CC = clang
FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
INC = -Iinc -Ilibmx/inc
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
LIB = libmx/libmx.a

all: pathfinder

pathfinder: $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(INC) $(OBJ) $(LIB) -o pathfinder

obj/%.o: src/%.c | obj
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(LIB):
	make -C libmx

obj:
	mkdir obj

clean:
	rm -r obj

uninstall:
	rm -r obj pathfinder libmx/obj libmx/libmx.a

reinstall:
	make uninstall
	make