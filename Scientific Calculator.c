#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* ===== COLORS (ANSI SAFE) ===== */
#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"

/* ===== DEGREE TO RADIAN ===== */
#define DEG_TO_RAD(x) ((x) * M_PI / 180.0)

/* ===== GLOBAL ===== */
int operationCount = 0;

/* ===== CLEAR SCREEN ===== */
void clearScreen() {
    system("cls || clear");
}

/* ===== FACTORIAL ===== */
long long factorial(int n) {
    long long f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

/* ===== HEADER ===== */
void showHeader() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    printf(CYAN);
    printf("\n==============================================\n");
    printf("        SCIENTIFIC CALCULATOR SYSTEM\n");
    printf("        Course: CSE103 | Language: C\n");
    printf("        Date: %02d-%02d-%d   Time: %02d:%02d\n",
           tm->tm_mday, tm->tm_mon + 1,
           tm->tm_year + 1900, tm->tm_hour, tm->tm_min);
    printf("==============================================\n");
    printf(RESET);
}

/* ===== MENU ===== */
void showMenu() {
    printf(YELLOW "\n------------- OPERATIONS MENU -------------\n" RESET);
    printf(" 1. Addition (multiple numbers)\n");
    printf(" 2. Subtraction (two numbers)\n");
    printf(" 3. Multiplication (multiple numbers)\n");
    printf(" 4. Division (two numbers)\n");
    printf(" 5. Power (x^y)\n");
    printf(" 6. Square Root\n");
    printf(" 7. Sine\n");
    printf(" 8. Cosine\n");
    printf(" 9. Tangent\n");
    printf("10. Log base 10\n");
    printf("11. Natural Log\n");
    printf("12. Exponential (e^x)\n");
    printf("13. Factorial\n");
    printf(" 0. Exit\n");
    printf("-------------------------------------------\n");
    printf("Enter your choice: ");
}

/* ===== RESULT BOX ===== */
void showResultBox() {
    operationCount++;
    printf(GREEN "\n-------------------------------------------\n");
    printf(" Calculation completed successfully\n");
    printf(" Operations performed this session: %d\n", operationCount);
    printf("-------------------------------------------\n" RESET);
}

/* ===== MAIN ===== */
int main() {
    int choice, count, n;
    double num, result, x, y;

    while (1) {
        clearScreen();
        showHeader();
        showMenu();
        scanf("%d", &choice);

        switch (choice) {

            /* ===== ADDITION (MULTIPLE NUMBERS) ===== */
            case 1:
                printf("How many numbers do you want to add? ");
                scanf("%d", &count);

                result = 0;
                for (int i = 1; i <= count; i++) {
                    printf("Enter number %d: ", i);
                    scanf("%lf", &num);
                    result += num;
                }
                printf(GREEN "Sum = %.4lf\n" RESET, result);
                break;

            /* ===== SUBTRACTION ===== */
            case 2:
                printf("Enter first number: ");
                scanf("%lf", &x);
                printf("Enter second number: ");
                scanf("%lf", &y);
                printf(GREEN "Result = %.4lf\n" RESET, x - y);
                break;

            /* ===== MULTIPLICATION (MULTIPLE NUMBERS) ===== */
            case 3:
                printf("How many numbers do you want to multiply? ");
                scanf("%d", &count);

                result = 1;
                for (int i = 1; i <= count; i++) {
                    printf("Enter number %d: ", i);
                    scanf("%lf", &num);
                    result *= num;
                }
                printf(GREEN "Product = %.4lf\n" RESET, result);
                break;

            /* ===== DIVISION ===== */
            case 4:
                printf("Enter dividend: ");
                scanf("%lf", &x);
                printf("Enter divisor: ");
                scanf("%lf", &y);

                if (y == 0)
                    printf(RED "Error: Division by zero\n" RESET);
                else
                    printf(GREEN "Result = %.4lf\n" RESET, x / y);
                break;

            /* ===== POWER ===== */
            case 5:
                printf("Enter base: ");
                scanf("%lf", &x);
                printf("Enter exponent: ");
                scanf("%lf", &y);
                printf(GREEN "Result = %.4lf\n" RESET, pow(x, y));
                break;

            /* ===== SQUARE ROOT ===== */
            case 6:
                printf("Enter number: ");
                scanf("%lf", &x);
                if (x < 0)
                    printf(RED "Error: Negative input\n" RESET);
                else
                    printf(GREEN "Result = %.4lf\n" RESET, sqrt(x));
                break;

            /* ===== TRIGONOMETRIC ===== */
            case 7:
                printf("Enter angle in degrees: ");
                scanf("%lf", &x);
                printf(GREEN "Result = %.4lf\n" RESET, sin(DEG_TO_RAD(x)));
                break;

            case 8:
                printf("Enter angle in degrees: ");
                scanf("%lf", &x);
                printf(GREEN "Result = %.4lf\n" RESET, cos(DEG_TO_RAD(x)));
                break;

            case 9:
                printf("Enter angle in degrees: ");
                scanf("%lf", &x);
                printf(GREEN "Result = %.4lf\n" RESET, tan(DEG_TO_RAD(x)));
                break;

            /* ===== LOG ===== */
            case 10:
                printf("Enter number: ");
                scanf("%lf", &x);
                if (x <= 0)
                    printf(RED "Error: Invalid input\n" RESET);
                else
                    printf(GREEN "Result = %.4lf\n" RESET, log10(x));
                break;

            case 11:
                printf("Enter number: ");
                scanf("%lf", &x);
                if (x <= 0)
                    printf(RED "Error: Invalid input\n" RESET);
                else
                    printf(GREEN "Result = %.4lf\n" RESET, log(x));
                break;

            /* ===== EXPONENTIAL ===== */
            case 12:
                printf("Enter exponent: ");
                scanf("%lf", &x);
                printf(GREEN "Result = %.4lf\n" RESET, exp(x));
                break;

            /* ===== FACTORIAL ===== */
            case 13:
                printf("Enter a non-negative integer: ");
                scanf("%d", &n);
                if (n < 0)
                    printf(RED "Error: Invalid input\n" RESET);
                else
                    printf(GREEN "Result = %lld\n" RESET, factorial(n));
                break;

            case 0:
                printf(CYAN "\nThank you for using the Scientific Calculator\n" RESET);
                exit(0);

            default:
                printf(RED "Invalid choice. Try again.\n" RESET);
        }

        showResultBox();
        printf(YELLOW "\nPress Enter to continue..." RESET);
        getchar();
        getchar();
    }

    return 0;
}
