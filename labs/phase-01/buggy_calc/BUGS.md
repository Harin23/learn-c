# Buggy Calculator — Instructor / Self-Check Reference

**Do not read until you have attempted the lab with GDB.**

## Bug 1: Wrong division order

**Location:** `apply_op`, `/` case  
**Symptom:** `10 / 2` prints `0.2000` instead of `5.0000`  
**Fix:** Return `a / b` instead of `b / a`. Check divisor is `b`, not `a`.

## Bug 2: History buffer overflow

**Location:** `push_history`  
**Symptom:** After 6+ calculations, corrupted output or crash when printing history  
**Fix:** Only write when `history_count < HISTORY_LEN`; optionally implement ring buffer.

## Bug 3: Quit only accepts lowercase (minor)

**Location:** `main` loop  
**Symptom:** `Q` does not quit  
**Fix:** Accept both `'q'` and `'Q'`, or document as intentional.

## GDB Tips

```bash
gdb ./calc
break apply_op
run
# Enter: 10 / 2
print a
print b
step
```

```bash
break push_history
# Run 6 calculations and watch history_count exceed HISTORY_LEN
print history_count
```
