build:
	g++ walsh.cpp -o walsh
	g++ statistics.cpp -o statistics
	g++ prinel.cpp -o prinel
	g++ crypto.cpp -o crypto

run-p1:		walsh
	./walsh

run-p2:		statistics
	./statistics

run-p3: 	prinel
	./prinel

run-p4:  	crypto
	./crypto

clean:
	rm *.o