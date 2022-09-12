all:
	gcc -c src/jx_defines.c -o obj/jx_defines.o -I inc
	gcc -c src/main.c -o obj/main.o -I inc
	gcc -c src/jx_delog.c -o obj/jx_delog.o -I inc
	gcc obj/*.o -o bin/main
	
.PHONY: clean
clean:
	rm -rf obj/*.o bin/main