


fizzbuzzFirstAttempt: fizzbuzzMain.o fizzbuzzFirstAttempt.o
	gcc -o $@ $^

testFirstAttempt: fizzbuzzTester.o fizzbuzzFirstAttempt.o
	gcc -o $@ $^

testSecondAttempt: fizzbuzzTester.o fizzbuzzSecondAttempt.o
	gcc -o $@ $^

test: testFirstAttempt testSecondAttempt
	./testFirstAttempt
	./testSecondAttempt

clean: 
	rm *.o  

.PHONY: test clean

 
