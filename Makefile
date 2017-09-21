


fizzbuzzFirstAttempt: fizzbuzzMain.o fizzbuzzFirstAttempt.o
	gcc -o $@ $^

testFirstAttempt: fizzbuzzTester.o fizzbuzzFirstAttempt.o
	gcc -o $@ $^


test: testFirstAttempt
	./testFirstAttempt

clean: 
	rm *.o  

.PHONY: test clean

 
