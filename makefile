all:
	gcc -c src/main.c -o obj/main.o -Iinc
	gcc -c src/param.c -o obj/param.o -Iinc
	gcc obj/*.o -o bin/main
	
.PHONY: clean
clean:
	rm -rf obj/*.o bin/main