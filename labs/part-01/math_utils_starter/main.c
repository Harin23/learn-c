#include <stdio.h>
#include "math_utils.h"

int main(void)
{
    printf("5 + 3 = %d\n", add(5, 3));
    printf("5 - 3 = %d\n", subtract(5, 3));
    printf("5 * 3 = %d\n", multiply(5, 3));
    printf("5 / 3 = %.2f\n", divide(5, 3));
    return 0;
}
