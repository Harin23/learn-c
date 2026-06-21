//
// Created by rin-dev on 6/21/26.
//

#include <stdint.h>
#include <stdio.h>

//Lab 2: Format Specifier Experiments

// int main() {
//     int x = 3;
//     float y = 3.14159265f;
//     double z = 3.141592653589793;
//
//     printf("%d \n", y);
//     printf("%d \n", z);
//     printf("%f \n", x);
//
// /*
//  * Mismatching format specifiers with variable types
//  * subverts the contract that printf relies on to fetch
//  * arguments from the stack (or registers) in a predictable
//  * way. When an int is printed with %f, printf interprets the
//  * bits of the integer as a floating‑point representation,
//  * reading a larger amount of data than was actually passed;
//  * similarly, using %d for a double causes printf to treat a
//  * 64‑bit floating‑point value as a 32‑bit integer, extracting
//  * the wrong portion of memory. This leads to undefined
//  * behavior: the program may output garbage values, corrupt
//  * adjacent stack data, or crash outright (e.g., with a segmentation
//  * fault under GDB). Because the compiler cannot verify these mismatches
//  * at compile time, the errors manifest only at runtime, making them hard
//  * to detect and potentially exposing security vulnerabilities such as format‑string attacks.
//  */
//     return 0;
// }

//--------------------------------------
// lab 3:
// int main() {
//     printf("sizes of basic types on x86-64\n");
//     printf("char %zu\n", sizeof(char));
//     printf("short %zu\n", sizeof(short));
//     printf("int %zu\n", sizeof(int));
//     printf("int8 %zu\n", sizeof(int8_t));
//     printf("uint8 %zu\n", sizeof(uint8_t));
//     printf("int16 %zu\n", sizeof(int16_t));
//     printf("uint16 %zu\n", sizeof(uint16_t));
//     printf("int32 %zu\n", sizeof(int32_t));
//     printf("uint32 %zu\n", sizeof(uint32_t));
//     printf("int64 %zu\n", sizeof(int64_t));
//     printf("uint64 %zu\n", sizeof(uint64_t));
//     printf("long %zu\n", sizeof(long));
//     printf("long long %zu\n", sizeof(long long));
//     printf("float %zu\n", sizeof(float));
//     printf("double %zu\n", sizeof(double));
//     printf("long double %zu\n", sizeof(long double));
//     return 0;
// }
/*
 * On many 32‑bit systems `int` and `long` are both 4 bytes, but on most
 * 64‑bit Unix‑like systems `int` remains 4 bytes while `long` expands to
 * 8 bytes. Code that assumes `int` and `long` are interchangeable can
 * break when moved between such environments.
 *
 * Fixed‑width types (`int32_t`, `uint64_t`, etc.) guarantee the exact
 * number of bits regardless of the underlying architecture, making
 * them essential for low‑level, network, or file‑format code where the
 * size of a field must be known precisely.
 */
//-----------------------------------------------------------------------------
//lab 4

int main() {
    double f = 0, c = 0;
    int type = 0;

    printf("Please press 0 to select input unit as Celsius or 1 for Fahrenheit:");
    scanf("%d", &type);

    if (type == 0) {
        printf("\nPlease enter temperature value to convert:");
        scanf("%lf", &c);

        // printf("%lf", (9/5)*c);
        f = (9.0/5.0) * c + 32; //have to ensure 9/5 is in float and not in int so ".0" needs to added
        // f = (9.0f/5.0f) * c + 32; //less accurate way because it ensures floats instead of doubles
    }else {
        printf("\nPlease enter temperature value to convert:");
        scanf("%lf", &f);
        c=(f-32)*((double)5/9); //different way to cast 5/9 to double instead of int
    }
    printf("\n%.2lf C | %.2lf F", c, f);
    return 0;
}