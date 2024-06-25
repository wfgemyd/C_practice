#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstdlib>
#define _CRT_SECURE_NO_WARNINGS


void helloWorld();
int showResult(int result);
int calc(int x, char sign, int y);
float tempConversion(char initialUnit, float value);
bool evenOdd(int num);
int sumEvenTIllSelected(int upperLimit);
void primeNum(int num);
void userInput();
int sumArr(int arr[], int size);
void findMinMax(int arr[], int size, int* min, int* max);
void revArr(int arr[], int size);
void swapInts(int* one, int* two);
void projectTwoOne(int* ar, int size);

int main() {

    //userInput();

    //int one = 2;
    //int two = 3;
    //printf("one: %d \n two: %d", one, two);
    //swapInts(&one, &two);
    //printf("one: %d \n two: %d", one, two);
    
    //int *ar;
    //int size = 5;
    //ar = (int*)malloc(sizeof(int) * size);

    //for (int i = 0; i < size; i++)
        //ar[i] = i + 4;

    //projectTwoOne(ar, size);
    //free(ar);




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


//project num1
//Create a program that allows the user to enter 10 integers, 
// stores them in an array, and then performs the following operations :

//Prints the array.
//Calculates and prints the sum of all elements.
//Finds and prints the maximum and minimum values.
//Reverses the array and prints it.

void userInput() {
    int arr[10];
    int userInput = 0;
    int size = sizeof(arr) / sizeof(arr[0]);

    //printf("%i", sizeof(arr)/4); int = 4 bytes
    for (int i = 0; i < size; i++) {
        printf("Insert 10 numbers. Insert the %dth number: ", i + 1);
        scanf_s("%d", &userInput); //scanf_s for security // & because it need the address of the location.
        arr[i] = userInput;
    }

    //1
    printf("The numbers you entered are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //2
    printf("THe sum is: %i", sumArr(arr, size));

    printf("\n");

    //3
    int min, max;
    findMinMax(arr, size, &min, &max);
    printf("The min is: %d\nThe max is: %d\n", min, max);

    printf("\n");

    //2
    revArr(arr, size);
    printf("\n");
}

int sumArr(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result+=arr[i];
    }
    return result;
}

void findMinMax(int arr[], int size, int *min, int * max) {
    *min = arr[0];
    *max = arr[1];
    
    for (int i = 2; i < size; i++) {
        if (arr[i] > *max)
            *max = arr[i];
        if (arr[i] < *min)
            *min = arr[i];
    }
}

void revArr(int arr[], int size) {
    printf("Reversed array:");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
}

//Project num2
//Write a program that swaps the values of two integers using pointers. The program should:

//Take two integer inputs from the user.
//Swap their values using a function that takes two integer pointers as arguments.
//Print the values before and after the swap.

void swapInts(int* one, int* two) { //by value
    printf("\nONE: %p\n", one);
    printf("ONE*: %d\n", *one);
    printf("ONE&: %p\n", &one);
    int temp = *one;
    *one = *two;
    *two = temp;
}

//Project num2.1
//Task:
//Write a program that :

//Declares an array of 5 integers.
//Initializes the array with values from the user.
//Uses a pointer to traverse the array and print each element.
//Uses a pointer to modify each element by multiplying it by 2.
//Prints the modified array.
void projectTwoOne(int ar[], int size) {
    ar = (int*)malloc(sizeof(int) * size);
    // Initialize the array with some values
    for (int i = 0; i < size; i++) {
        ar[i] = i + 1 * 2;
    }
    // Print the array
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

 
