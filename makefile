all: user.c worker.c
	gcc -o user user.c
	gcc -o worker worker.c

run:
	./user
