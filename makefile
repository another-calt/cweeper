run: 
	gcc -std=gnu11 -O2 main.c -o cweep && ./cweep

clean:
	rm cweep *.o