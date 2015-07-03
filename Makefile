
project_2G: driver_2G.o my_struct.o
	gcc -o project_2F my_struct.o driver_2F.o

driver_2G.o: driver_2G.c prototypes.h my_struct.h
	gcc -c -I. driver_2G.c

my_struct.o: driver_2G.c prototypes.h my_struct.h
	gcc -c -I. my_struct.c
