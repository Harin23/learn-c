#include <stdio.h>

//for
// int main (void) {
//     for (int i = 1; i <= 100; i++) {
//         const float mod3 = i % 3;
//         const float mod5 = i % 5;
//
//         if (mod3 == 0 && mod5 == 0) printf("FizzBuzz");
//         else if (mod3 == 0) printf("Fizz");
//         else if (mod5 == 0) printf("Buzz");
//         else printf("%d", i);
//     }
//     return 0;
// }

//while
// int main(void) {
//     int i = 1;
//
//     while (i <= 100) {
//         const int mod3 = i % 3;
//         const int mod5 = i % 5;
//
//         if (mod3 == 0 && mod5 == 0) printf("FizzBuzz");
//         else if (mod3 == 0) printf("Fizz");
//         else if (mod5 == 0) printf("Buzz");
//         else printf("%d", i);
//
//         i++;
//     }
//
//     return 0;
// }

//switch
int main(void) {
    for (int i = 1; i <= 100; i++) {
        switch(((i % 3 == 0) << 1 | (i % 5 == 0))) { //"<<" shifts 1 bit to left
            case 3: //binary: 11, true true, meaning divisible by both
                printf("FizzBuzz");
                break;
            case 2: //base 2: 10, true false
                printf("Fizz");
                break;
            case 1: // 01, false true
                printf("Buzz");
                break;
            default:
                printf("%d", i);
                break;
        }
    }
    return 0;
}