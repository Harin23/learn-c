# ---------- Variables (easy to change) ----------
CC      := gcc                        # compiler
CFLAGS  := -Wall -Wextra -std=c11     # warnings + language version
TARGET  := main                  # name of the final executable
SRCS    := main.c math_utils.c				      # all source files
OBJS    := $(SRCS:.c=.o)              # replace .c with .o → main.o math_utils.o

# ---------- Default target ----------
all: $(TARGET)                        # “make” builds $(TARGET)

# ---------- Link step ----------
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# ---------- Compile each .c into .o ----------
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ---------- Clean up ----------
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
