#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void helloWorld();
int showResult(int result);
int calc(int x, char sign, int y);
float tempConversion(char initialUnit, float value);
bool evenOdd(int num);
int sumEvenTIllSelected(int upperLimit);
void primeNum(int num);

int main() {
    //helloWorld();


    //int x = 10;
    //int y = 5;
    //char sign = '+';

    //calc(x, sign, y);

    //tempConversion('c', 36.6);
    //tempConversion('F', 100.1);
    //evenOdd(11);
    //sumEvenTIllSelected(10);
    //primeNum(24);


    return 0;
}

//helo world
void helloWorld() {
	printf("Hello World\n");
}

//calc result print
int showResult(int result) {
    printf("Result: %i\n", result);
    return result;
}

//simple calc
int calc(int x, char sign, int y) {
    int result = 0;
    switch (sign) {
    case '+':
        result = x + y;
        break;
    case '-':
        result = x - y;
        break;
    case '*':
        result = x * y;
        break;
    case '/':
    case ':':
        if (y != 0) {
            result = x / y;
        }
        else {
            printf("Error: Division by zero\n");
            return -1;  // Return an error code for division by zero
        }
        break;
    default:
        printf("Error: Invalid operator\n");
        return -1;  // Return an error code for invalid operator
    }
    return showResult(result);
}

//temp conversion C to F and vise versa
float tempConversion(char initialUnit, float value) {
    float result = 0;
    switch (initialUnit) {
    case 'C':
    case 'c':
        result = (value * 9.0 / 5.0) + 32.0;
        printf("The temperature in Fahrenheit is: %.2f\n", result);
        return result;
    case 'F':
    case 'f':
        result = (value - 32.0) * 5.0 / 9.0;
        printf("The temperature in Celsius is: %.2f\n", result);
        return result;
    default:
        printf("Error: Invalid unit\n");
        return -1;  // Return an error code for invalid unit
    }
}

//is it even?
bool evenOdd(int num) {
    if (num % 2 == 0)
        return true;
    return false;
}

//calculates the sum of all even numbers between 1 and a user-defined upper limit (inclusive)
int sumEvenTIllSelected(int upperLimit) {
    int result = 0;
    for (int i = 0; i <= upperLimit; i++) {
        if (evenOdd(i))
            result += i;
    }


    printf("result: %i", result);
    return result;
}


//is it prime number detector.
void primeNum(int num) {
    if (num <= 1) {
        printf("Not a prime number\n");
        return;
    }

    if (num <= 3) {
        printf("Prime\n");
        return;
    }

    if (num % 2 == 0 || num % 3 == 0) {
        printf("Not a prime number\n");
        return;
    }

    int i = 5;
    while (i * i <= num) {
        if (num % i == 0 || num % (i + 2) == 0) {
            printf("Not a prime number\n");
            return;
        }
        i += 6;
    }

    printf("Prime\n");
}