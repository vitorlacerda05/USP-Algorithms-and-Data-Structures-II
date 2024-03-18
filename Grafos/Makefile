CC = gcc

tests-directory = ./test_cases

clean:
	rm -r lib/*/*.o $(program)

compile: ./main.c ./lib/adjacencygraph.c ./lib/adjacencygraph.h
	$(CC) -o main ./main.c ./lib/adjacencygraph.c

exec:
	$(CC) -o main ./main.c ./lib/adjacencygraph.c
	./main < $(tests-directory)/1.in
	./main < $(tests-directory)/2.in

generate-single-file:
	@ > single-main.c
	@ find ./lib -type f -name '*.h' -exec cat {} + >> single-main.c
	@ echo "" >> single-main.c
	@ find ./lib -type f -name '*.c' -exec cat {} + >> single-main.c
	@ echo "" >> single-main.c
	@ cat main.c >> single-main.c
	@ echo "Remember to remove the unused imports!"

test-single-main:
	$(CC) -o single-main ./single-main.c
	./main < $(tests-directory)/1.in
	./main < $(tests-directory)/2.in
	@ rm single-main
