## Overview

Implementation of the FizzBuzz coding exercise in C.

Yes, you read that correctly, C.  Why?  Because it should be possible (and is if you google) to do TDD in C
and it should also be a really compact and quick implementation for something that's just kicking out
strings.

The other reason is I pretty much screwed up the Java implementation by making it way too complicated.  That was
partly because I'm not good enough at TDD yet but also because I don't like pointless* code and try to make it "interesting"
which probably means "complicated".

[ * Yes, the point is actually to demonstrate an approach and use of TDD but aside from that it achieves nothing of use ]


## Task

```
Guidance: This excercise should be completed within 90 minutes. TDD, Clean code and unit testing approach should be used.
Output should be archived as Zip file or into github.

FizBuzz
=======
Step 1:
Write code that prints out the following for a contiguous range of numbers:
* the number
* 'fizz' for numbers divisible by 3
* 'buzz' for numbers divisible by 5
* 'fizzbuzz' for numbers divisible by both 3 and 5
e.g. if I run the program over a range from 1-20 I should get the following output
1 2 fizz 4 buzz fizz 7 8 fizz buzz 11 fizz 13 14 fizzbuzz 16 17 fizz 19 buzz
Archive this as a zip file and continue to step two.


Step 2:
Enhance your existing FizzBuzz solution to perform the following:
* If the number contains a three you must output the text 'lucky'. This overrides any existing behaviour
e.g. if I run the program over a range from 1-20 should get the following output
1 2 luck 4 buzz fizz 7 8 fizz buzz 11 fizz luck 14 fizzbuzz 16 17 fizz 19 buzz
Archive this as a zip file and continue to step three


Step 3:
Enhance your exising FizzBuzz solution to also print statistics about how many times the following were output:
- fizz
- buzz
- fizzbuzz
- luck
- number
e.g. if I run the prograrm over a range from 1-20 I should get the following output:
1 2 luck 4 buzz fizz 7 8 fizz buzz 11 fizz luck 14 fizzbuzz 16 17 fizz 19 buzz
fizz: 4
buzz: 3
fizzbuzz: 1
luck: 2
number: 10

```
