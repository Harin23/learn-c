/*
 * Lab 1.5 — Buggy calculator (intentional bugs for GDB practice)
 *
 * Find and fix all bugs using GDB. Do not read BUGS.md until you have tried.
 *
 * Build: make
 * Debug: gdb ./calc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 128
#define HISTORY_LEN 5

static double history[HISTORY_LEN];
static int history_count;

static void push_history(double value)
{
	/* BUG 2: no bounds check — writes past history[4] when count reaches 5 */
	history[history_count] = value;
	history_count++;
}

static void print_history(void)
{
	printf("History:\n");
	for (int i = 0; i < history_count; i++)
		printf("  [%d] %.4f\n", i, history[i]);
}

static double parse_double(const char *s)
{
	char *end;
	double v = strtod(s, &end);
	if (end == s) {
		fprintf(stderr, "Invalid number: %s\n", s);
		exit(1);
	}
	return v;
}

static double apply_op(double a, double b, char op)
{
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		/* BUG 1: wrong operand order — should be a / b */
		if (b == 0.0) {
			fprintf(stderr, "Division by zero\n");
			return 0.0;
		}
		return b / a;
	default:
		fprintf(stderr, "Unknown operator: %c\n", op);
		return 0.0;
	}
}

int main(void)
{
	char line[MAX_INPUT];

	printf("Buggy Calc — enter: <num> <op> <num> (q to quit)\n");

	while (1) {
		printf("> ");
		if (!fgets(line, sizeof(line), stdin))
			break;

		/* BUG 3: quit check only looks at 'q', not 'Q' — minor */
		if (line[0] == 'q')
			break;

		double a, b;
		char op;
		if (sscanf(line, "%lf %c %lf", &a, &op, &b) != 3) {
			printf("Format: <num> <op> <num>\n");
			continue;
		}

		double result = apply_op(a, b, op);
		printf("= %.4f\n", result);
		push_history(result);
	}

	print_history();
	return 0;
}
