#include <stdio.h>

/* “broken” swap – works only on the copies */
void swap(int a, int b)          /* note: returns nothing */
{
    int tmp = a;
    a = b;
    b = tmp;                     /* a & b are only locals */
}

void print_pair(const char *msg, int x, int y)
{
    printf("%s:  x = %d,  y = %d\n", msg, x, y);
}

int main(void)
{
    int x = 5, y = 9;

    print_pair("Before swap", x, y);
    swap(x, y);
    print_pair("After  swap", x, y);

    return 0;
}


// (gdb) break swap
// Breakpoint 1 at 0x1157: file swap-demo.c, line 6.
// (gdb) run
// Starting program: /home/rin-dev/Desktop/repos/learn-c/part-01-programming-foundations/module-01-03-functions/swap-demo
//
// This GDB supports auto-downloading debuginfo from the following URLs:
//   <https://debuginfod.ubuntu.com>
// Enable debuginfod for this session? (y or [n]) n
// Debuginfod has been disabled.
// To make this setting permanent, add 'set debuginfod enabled off' to .gdbinit.
// [Thread debugging using libthread_db enabled]
// Using host libthread_db library "/usr/lib/x86_64-linux-gnu/libthread_db.so.1".
// Before swap:  x = 5,  y = 9
//
// Breakpoint 1, swap (a=5, b=9) at swap-demo.c:6
// 6	    int tmp = a;
// (gdb) step
// 7	    a = b;
// (gdb) print tmp
// $1 = 5
// (gdb) step
// 8	    b = tmp;                     /* a & b are only locals */
// (gdb) print a
// $2 = 9
// (gdb) step
// 9	}
// (gdb) print b
// $3 = 5
// (gdb) finish
// Run till exit from #0  swap (a=9, b=5) at swap-demo.c:9
// main () at swap-demo.c:22
// 22	    print_pair("After  swap", x, y);
// (gdb) print x
// $4 = 5
// (gdb) print y
// $5 = 9
// (gdb) quit
// A debugging session is active.
//
//     Inferior 1 [process 22321] will be killed.
//
// Quit anyway? (y or n) y
