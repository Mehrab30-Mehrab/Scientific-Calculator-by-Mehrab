#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Convert degrees to radians for trig functions
#define DEG_TO_RAD(angle) ((angle) * M_PI / 180.0)

// Factorial function
long long factorial(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; ++i) result *= i;
    return result;
}

void showMenu() {
    printf("\n==== Scientific Calculator ====\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    printf("6. Power (x^y)\n");
    printf("7. Square Root (√x)\n");
    printf("8. Sine (sin x)\n");
    printf("9. Cosine (cos x)\n");
    printf("10. Tangent (tan x)\n");
    printf("11. Logarithm base 10 (log x)\n");
    printf("12. Natural Logarithm (ln x)\n");
    printf("13. Exponential (e^x)\n");
    printf("14. Factorial (x!)\n");
    printf("0. Exit\n");
    printf("Choose an operation: ");
}

int main() {
    int choice;
    double num1, num2;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result = %.4lf\n", num1 + num2);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result = %.4lf\n", num1 - num2);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result = %.4lf\n", num1 * num2);
                break;

            case 4:
                printf("Enter dividend and divisor: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0)
                    printf("Error: Division by zero!\n");
                else
                    printf("Result = %.4lf\n", num1 / num2);
                break;

            case 5:
                printf("Enter two integers: ");
                int a, b;
                scanf("%d %d", &a, &b);
                if (b == 0)
                    printf("Error: Modulo by zero!\n");
                else
                    printf("Result = %d\n", a % b);
                break;

            case 6:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result = %.4lf\n", pow(num1, num2));
                break;

            case 7:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 < 0)
                    printf("Error: Negative number for square root!\n");
                else
                    printf("Result = %.4lf\n", sqrt(num1));
                break;

            case 8:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                printf("sin(%.2lf) = %.4lf\n", num1, sin(DEG_TO_RAD(num1)));
                break;

            case 9:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                printf("cos(%.2lf) = %.4lf\n", num1, cos(DEG_TO_RAD(num1)));
                break;

            case 10:
                printf("Enter angle in degrees: ");
                scanf("%lf", &num1);
                printf("tan(%.2lf) = %.4lf\n", num1, tan(DEG_TO_RAD(num1)));
                break;

            case 11:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 <= 0)
                    printf("Error: Logarithm undefined for <= 0\n");
                else
                    printf("log10(%.2lf) = %.4lf\n", num1, log10(num1));
                break;

            case 12:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 <= 0)
                    printf("Error: Natural log undefined for <= 0\n");
                else
                    printf("ln(%.2lf) = %.4lf\n", num1, log(num1));
                break;

            case 13:
                printf("Enter exponent: ");
                scanf("%lf", &num1);
                printf("e^%.2lf = %.4lf\n", num1, exp(num1));
                break;

            case 14:
                printf("Enter a non-negative integer: ");
                int n;
                scanf("%d", &n);
                if (n < 0)
                    printf("Error: Factorial of negative number undefined!\n");
                else
                    printf("%d! = %lld\n", n, factorial(n));
                break;

            case 0:
                printf("Exiting calculator. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
