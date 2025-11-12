# 🛡️ Crash Isolation Guide

## What is Crash Isolation?

Crash Isolation is a safety feature that prevents one crashing test from taking down your entire test suite. Each test runs in its own child process, so if a test crashes (segfault, abort, etc.), the main program continues testing.

---

## Why Do You Need It?

### Common Scenarios
1. **Developing Libft** - You're implementing functions one by one and some are incomplete
2. **Bug Hunting** - You suspect certain functions have memory issues
3. **Comprehensive Testing** - You want results from ALL tests even if some crash
4. **Safety** - You want guaranteed crash protection for unfinished code

### Without Crash Isolation
```
Test ft_substr: ✓ pass
Test ft_strjoin: ✗ CRASH (segfault)
Test ft_split: (never runs - program crashed)
Test ft_itoa: (never runs - program crashed)
```

### With Crash Isolation
```
Test ft_substr: ✓ pass
Test ft_strjoin: ✗ CRASH (Segmentation fault - recovered)
Test ft_split: ✓ pass
Test ft_itoa: ✗ CRASH (Bus error - recovered)
Test strmapi: ✓ pass
```

---

## How To Use Crash Isolation

### Run in Safe Mode
```bash
./libft_tester -s
# or
./libft_tester --safe
```

### Example Output

```
╔════════════════════════════════════════════════════════╗
║  PART 2: ADDITIONAL FUNCTIONS (WITH CRASH PROTECTION) ║
╚════════════════════════════════════════════════════════╝

[CRASH] Test 'ft_split' killed by signal 11 (Segmentation fault)
  ✓ Substring from beginning
  ✓ Start beyond string length
[CRASH] Test 'ft_itoa' exceeded 5 seconds

...

Tests Summary:
  Total: 34
  Passed: 31
  Crashed: 3
  Timed Out: 1
```

---

## How It Works

### Technical Overview

```
┌─ Main Process (Parent)
│  │
│  ├─ Fork Child #1 ─→ run test_ft_calloc()
│  │  │
│  │  └─ Child 1 crashes → Parent catches it, continues
│  │
│  ├─ Fork Child #2 ─→ run test_ft_strdup()
│  │  │
│  │  └─ Child 2 completes normally → Parent records result
│  │
│  ├─ Fork Child #3 ─→ run test_ft_substr()
│  │  │
│  │  └─ Child 3 hangs → Parent timeout kills it after 5s
│  │
│  └─ Continue with remaining tests...
```

### Process Isolation Steps

1. **Fork**: Main process spawns a child process
2. **Execute**: Child runs the test function in isolation
3. **Monitor**: Parent sets alarm for 5-second timeout
4. **Catch**: Any crashes are caught before affecting parent
5. **Report**: Parent gets exit status and reports what happened
6. **Continue**: Parent moves to next test

### Crash Types Detected

| Crash Type | Signal | Example | Caught? |
|-----------|--------|---------|---------|
| Segmentation Fault | SIGSEGV | Out of bounds array access | ✅ Yes |
| Abort | SIGABRT | Failed assertion | ✅ Yes |
| Bus Error | SIGBUS | Misaligned memory access | ✅ Yes |
| Floating Point Error | SIGFPE | Division by zero | ✅ Yes |
| Illegal Instruction | SIGILL | Invalid CPU instruction | ✅ Yes |
| Timeout | SIGALRM | Infinite loop (>5 seconds) | ✅ Yes |

---

## Command Reference

### Safe Mode Options

```bash
# Long form
./libft_tester --safe

# Short form
./libft_tester -s
```

### Other Modes

```bash
# Interactive mode (also has per-function isolation)
./libft_tester -i
./libft_tester --interactive

# Batch mode (no isolation - faster but no crash protection)
./libft_tester

# Help and usage
make help
```

---

## Common Issues & Solutions

### Issue: Tests are running slowly
**Reason**: Process forking and context switching takes time
**Solution**: Use batch mode (`./libft_tester`) if you don't need crash protection

### Issue: Still crashes with "-s" flag
**Reason**: Some crashes might be fatal to the entire OS context
**Solution**: This is extremely rare; try running `./libft_tester` in a terminal session isolation tool like `tmux` or `screen`

### Issue: Want to see which function crashed?
**Solution**: The output clearly shows:
```
[CRASH] Test 'ft_split' killed by signal 11 (Segmentation fault)
```

### Issue: Tests timing out
**Reason**: Infinite loop or extremely slow function
**Solution**: 
1. Check for infinite loops in your code
2. Look for O(n²) or worse algorithms
3. Default timeout is 5 seconds (can be changed in `isolation.h`)

---

## Advanced Usage

### Checking Exit Codes

```bash
./libft_tester -s
echo $?  # Shows exit code
```

Exit codes:
- `0` = All tests passed
- `1` = Some tests failed or crashed

### Redirecting Output

```bash
# Save output to file
./libft_tester -s > test_results.txt 2>&1

# Pipe to pager for easy viewing
./libft_tester -s | less -R  # -R for colors
```

### Combining with Other Tools

```bash
# Monitor memory usage while testing
top -p $$
./libft_tester -s

# Count how many tests passed
./libft_tester -s 2>&1 | grep "✓" | wc -l

# Find which functions crashed
./libft_tester -s 2>&1 | grep "\[CRASH\]"
```

---

## Configuration

### Timeout Setting

Edit `isolation.h` to change the timeout value:

```c
/* Change from 5 to 10 seconds */
# define TEST_TIMEOUT 10
```

Then recompile:
```bash
make re
```

---

## Performance Considerations

### Safe Mode Performance
- **Overhead**: ~10-20% slower than batch mode due to forking
- **Memory**: Each child process uses ~5-10MB
- **Timeout Cost**: Default 5-second timeout per test adds safety
- **Worth It?**: Absolutely, if you have crashing code

### Speed Comparison

```
Batch Mode:  ~2 seconds  (no crash protection)
Safe Mode:   ~3 seconds  (with crash protection)
Interactive: ~3 seconds  (per-function choice + traces)
```

---

## Best Practices

### When Testing Your Libft

1. **Start with Safe Mode** if your code is incomplete
   ```bash
   ./libft_tester -s
   ```

2. **Fix Crashes First** - Focus on functions that crash
   - Segfaults usually mean memory issues
   - Aborts usually mean assertion failures

3. **Switch to Batch Mode** once everything works
   ```bash
   ./libft_tester
   ```

4. **Use Interactive Mode** for detailed debugging
   ```bash
   ./libft_tester -i
   ```

### Debugging Workflow

```
1. Run: ./libft_tester -s
2. Identify crashing functions from output
3. Fix each crash one at a time
4. Re-run: ./libft_tester -s
5. Repeat until no crashes
6. Fix failing tests (if any)
7. Run: ./libft_tester -i (view detailed failures)
8. Final validation: ./libft_tester (batch mode)
```

---

## Architecture Details

### Files Involved

- **isolation.h** - Declarations and constants
- **isolation.c** - Implementation of process isolation
- **isolated_tests.c** - Wrapper functions for each test
- **main.c** - Command-line flag handling (`-s`, `--safe`)

### Key Functions

```c
/* Core isolation function */
int run_isolated_test(void (*test_func)(void), const char *test_name);

/* Get human-readable crash reason */
const char *get_crash_reason(int status);
```

### How Signals Are Handled

```c
signal(SIGALRM, timeout_handler);  // Handle timeout
alarm(TEST_TIMEOUT);               // Start 5-second timer
test_func();                        // Run test
/* If child hasn't exited in 5s, SIGALRM is sent and timeout_handler runs */
```

---

## Limitations

### What Crash Isolation Cannot Protect Against

1. **Kernel Panic** - Critical system errors
2. **OOM Killer** - System running out of memory
3. **Compiler Bugs** - Compiler-generated crashes
4. **Hardware Failures** - CPU/memory hardware issues

These are extremely rare and beyond the scope of the tester.

---

## Summary

**Safe Mode is Perfect For:**
✅ Testing incomplete code
✅ Finding which functions crash
✅ Continuing tests despite crashes
✅ Getting a complete picture of your implementation

**Use Regular Mode When:**
✅ Your code is stable and doesn't crash
✅ You want maximum speed
✅ You're running in an automated system
✅ You only care about failing tests, not crashes

**Recommendation:**
Use `-s` while developing, switch to regular mode when done! 🚀
