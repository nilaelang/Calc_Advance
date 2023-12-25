#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Complex {
    float real;
    float imaginary;
};

struct Complex add(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

// Function to subtract two complex numbers
struct Complex subtract(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiply(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real * b.real - a.imaginary * b.imaginary;
    result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return result;
}

// Function to divide two complex numbers
struct Complex divide(struct Complex a, struct Complex b) {
    struct Complex result;
    float denominator = b.real * b.real + b.imaginary * b.imaginary;
    result.real = (a.real * b.real + a.imaginary * b.imaginary) / denominator;
    result.imaginary = (a.imaginary * b.real - a.real * b.imaginary) / denominator;
    return result;
}

// Function to perform binary addition
long binaryAddition(long binary1, long binary2) {
    int carry = 0;
    long result = 0;
    int digit, digit1, digit2, tempBinary1 = binary1, tempBinary2 = binary2, position = 1;

    while (tempBinary1 != 0 || tempBinary2 != 0) {
        digit1 = tempBinary1 % 10;
        digit2 = tempBinary2 % 10;
        tempBinary1 /= 10;
        tempBinary2 /= 10;

        // Perform binary addition
        digit = digit1 + digit2 + carry;
        carry = 0;

        if (digit > 1) {
            digit -= 2;
            carry = 1;
        }

        result += digit * position;
        position *= 10;
    }

    if (carry != 0) {
        result += carry * position;
    }

    return result;
}

// Function to perform binary subtraction
long binarySubtraction(long binary1, long binary2) {
    int borrow = 0;
    long result = 0;
    int digit, digit1, digit2, tempBinary1 = binary1, tempBinary2 = binary2, position = 1;

    while (tempBinary2 != 0) {
        digit1 = tempBinary1 % 10;
        digit2 = tempBinary2 % 10;
        tempBinary1 /= 10;
        tempBinary2 /= 10;

        // Perform binary subtraction
        digit = digit1 - digit2 - borrow;
        borrow = 0;

        if (digit < 0) {
            digit += 2;
            borrow = 1;
        }

        result += digit * position;
        position *= 10;
    }

    return result;
}

// Function to perform binary multiplication
long binaryMultiplication(long binary1, long binary2) {
    long tempBinary2, factor, result = 0;
    int position = 0;

    while (binary2 != 0) {
        if (binary2 % 10 == 1) {
            tempBinary2 = binary2;
            factor = binary1;
            while (tempBinary2 != 0) {
                if (tempBinary2 % 10 == 1) {
                    result = binaryAddition(result, factor << position);
                }
                tempBinary2 /= 10;
                position++;
            }
        }
        binary2 /= 10;
        position = 0;
    }

    return result;
}

// Function to perform binary division
long binaryDivision(long binary1, long binary2) {
    long quotient = 0, tempBinary1, remainder = 0;
    int quotientBit;

    while (binary1 >= binary2) {
        tempBinary1 = binary1;
        quotientBit = 1;
        while (tempBinary1 >= (binary2 << 1)) {
            binary2 <<= 1;
            quotientBit <<= 1;
        }
        binary1 = binarySubtraction(tempBinary1, binary2);
        remainder = binary1;
        binary2 = binary2 >> quotientBit;
        quotient = quotient + (1 << (quotientBit - 1));
    }

    return quotient;
}

// Function to convert a decimal number to binary
long decimalToBinary(int decimal) {
    long binary = 0;
    int remainder, base = 1;

    while (decimal > 0) {
        remainder = decimal % 2;
        binary += remainder * base;
        decimal /= 2;
        base *= 10;
    }

    return binary;
}

// Function to convert a binary number to decimal
int binaryToDecimal(long binary) {
    int decimal = 0, i = 0, remainder;

    while (binary != 0) {
        remainder = binary % 10;
        binary /= 10;
        decimal += remainder * pow(2, i);
        ++i;
    }

    return decimal;
}

// Function to convert a decimal number to hexadecimal
int decimalToHexadecimal(int decimal) {
    char hexadecimal[100];
    int i = 0;
    int j;

    while (decimal != 0) {
        int temp = 0;
        temp = decimal % 16;
        if (temp < 10) {
            hexadecimal[i] = temp + 48;
            i++;
        } else {
            hexadecimal[i] = temp + 55;
            i++;
        }
        decimal = decimal / 16;
    }

    printf("Hexadecimal: ");
    for ( j = i - 1; j >= 0; j--)
        printf("%c", hexadecimal[j]);
    printf("\n");
    return hexadecimal;
}



int main() 
{
    int choice;
    float num1, num2;
    long int result;
    int exitChoice = 0;

    while (!exitChoice) 
	{
        printf("\nMAIN MENU\n");
        printf("1. Basic Functions\n2. Complex Calculations\n3. Base-N Calculation\n4. Matrices\n5. More Functions\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
			{
       		case 1:
			   {
       			printf("Basic Functions\n");
                printf("Choose an operation:\n");
                printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
                printf("Enter your operation choice (1-4): ");
                int operation;
                scanf("%d",&operation);

                printf("Enter two numbers: ");
                scanf("%f%f",&num1,&num2);

                switch (operation) 
				{
                    case 1:
                        result = num1 + num2;
                        printf("Result: %.2ld\n", result);
                        break;
                    case 2:
                        result = num1 - num2;
                        printf("Result: %.2lf\n", result);
                        break;
                    case 3:
                        result = num1 * num2;
                        printf("Result: %.2ld\n", result);
                        break;
                    case 4:
                        if (num2 != 0) {
                            result = num1 / num2;
                            printf("Result: %.2ld\n", result);
                        } else {
                            printf("Error! Division by zero is not allowed.\n");
                        }
                        break;
                    default:
                        printf("Invalid operation choice.\n");
                }
                break;
			   }
                
            case 2:
			{
                printf("Complex Calculations\n");
                printf("Choose an operation:\n");
                printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
                printf("Enter your operation choice (1-4): ");
                int complexOperation;
                scanf("%d", &complexOperation);

                struct Complex complex1, complex2, complexResult;

                printf("Enter the real and imaginary parts of the first complex number: ");
                scanf("%f %f", &complex1.real, &complex1.imaginary);

                printf("Enter the real and imaginary parts of the second complex number: ");
                scanf("%f %f", &complex2.real, &complex2.imaginary);

                switch (complexOperation) 
				{
                    case 1:
                        complexResult = add(complex1, complex2);
                        printf("Sum: %.2f + %.2fi\n", complexResult.real, complexResult.imaginary);
                        break;
                    case 2:
                        complexResult = subtract(complex1, complex2);
                        printf("Difference: %.2f + %.2fi\n", complexResult.real, complexResult.imaginary);
                        break;
                    case 3:
                        complexResult = multiply(complex1, complex2);
                        printf("Product: %.2f + %.2fi\n", complexResult.real, complexResult.imaginary);
                        break;
                    case 4:
                        complexResult = divide(complex1, complex2);
                        printf("Quotient: %.2f + %.2fi\n", complexResult.real, complexResult.imaginary);
                        break;
                    default:
                        printf("Invalid operation choice.\n");
                }
        		break;
			}
            case 3:
			{
            	printf("Base-N Calculation\n");
                // Input prompt and reading statement for baseNOperation
                printf("1. Decimal to Binary\n2. Binary to Decimal\n3. Decimal to Hexadecimal\n4. Hexadecimal to Decimal\n");
                printf("5. Binary Addition\n6. Binary Subtraction\n7. Binary Multiplication\n8. Binary Division\n");
                printf("Enter your operation choice (1-8): ");
                int baseNOperation,bin1,bin2;
                scanf("%d", &baseNOperation);
				switch (baseNOperation) 
				{
                    case 1:
                    {
                        printf("Enter a decimal number: ");
                        scanf("%d", &num1);
                        result = decimalToBinary(num1);
                        printf("Binary: %ld\n", result);
                        break;
                	}
                    case 2:
                    {
                        printf("Enter a binary number: ");
                        scanf("%ld", &num1);
                        result = binaryToDecimal(num1);
                        printf("Decimal: %d\n", result);
                        break;
                	}
                    case 3:
                    {
                        printf("Enter a decimal number: ");
                        scanf("%d", &num1);
                        decimalToHexadecimal(num1);
                        break;
                    }
                    case 4:
                    {
                    	printf("The function is not yet added \n");
                        break;
                    }
                    case 5:
                    {
                        printf("Enter two binary numbers to add: ");
                        long bin1, bin2;
                        scanf("%ld %ld", &bin1, &bin2);
                        result = binaryAddition(bin1, bin2);
                        printf("Sum: %ld\n", result);
                        break;
                    }
                    case 6:
                    {
                        printf("Enter two binary numbers to subtract (1st - 2nd): ");
                        scanf("%ld %ld", &bin1, &bin2);
                        result = binarySubtraction(bin1, bin2);
                        printf("Difference: %ld\n", result);
                        break;
                	}
                    case 7:
                    {
                        printf("Enter two binary numbers to multiply: ");
                        scanf("%ld %ld", &bin1, &bin2);
                        result = binaryMultiplication(bin1, bin2);
                        printf("Product: %ld\n", result);
                        break;
                    }
                    case 8:
                    {
                        printf("Enter two binary numbers to divide (1st / 2nd): ");
                        scanf("%ld %ld", &bin1, &bin2);
                        result = binaryDivision(bin1, bin2);
                        printf("Quotient: %ld\n", result);
                        break;
                    }    
					default:
                    printf("Invalid operation choice.\n");
				}
			break ;
			}
            case 6:
			{
				printf("Exiting...\n");
                exitChoice = 1;
                break;
			}
            default:
                printf("Invalid choice!\n");
                break;
        
    		}
	}
    return 0;

}
