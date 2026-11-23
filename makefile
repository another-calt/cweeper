
run:
	g++ main.cpp -o cweep && ./cweep

# run: main.o
# 	gcc -std=gnu11 -O3 main.o -o cweep

# main.o:
# 	gcc -std=gnu11 -s -O2 main.c -c

clean:
	rm cweep *.o