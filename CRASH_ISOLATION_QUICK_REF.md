# 🎯 Crash Isolation - Quick Reference

## Commands

```bash
# Safe Mode (WITH crash protection)
./libft_tester -s
./libft_tester --safe

# Batch Mode (NO protection - fastest)
./libft_tester

# Interactive Mode (Menu-driven)
./libft_tester -i
./libft_tester --interactive

# Compilation
make              # Build tester
make re            # Clean rebuild
make clean        # Remove objects
make help         # Show help
```

## What Gets Protected

| Issue | Protected? |
|-------|-----------|
| Segmentation Fault (SIGSEGV) | ✅ Yes |
| Abort Signal (SIGABRT) | ✅ Yes |
| Bus Error (SIGBUS) | ✅ Yes |
| Floating Point Error (SIGFPE) | ✅ Yes |
| Illegal Instruction (SIGILL) | ✅ Yes |
| Timeout (>5 seconds) | ✅ Yes |
| Infinite Loop | ✅ Yes (via timeout) |

## Safe Mode Output Examples

### Normal Test (Passes)
```
✓ Test 'ft_strlen' completed successfully
```

### Crashed Test
```
[CRASH] Test 'ft_split' killed by signal 11 (Segmentation fault)
```

### Timed Out Test
```
[TIMEOUT] Test 'ft_itoa' exceeded 5 seconds
```

## Mode Comparison

| Feature | Batch | Safe | Interactive |
|---------|-------|------|-------------|
| Speed | Fast | Moderate | Moderate |
| Crash Protection | ❌ No | ✅ Yes | ✅ Yes |
| Timeout Protection | ❌ No | ✅ Yes | ✅ Yes |
| Menu Interface | ❌ No | ❌ No | ✅ Yes |
| View Traces | ❌ No | ❌ No | ✅ Yes |
| Best For | Quick tests | Debugging | Detailed review |

## How It Works

```
1. Parent forks child process
2. Child runs test function
3. Parent sets 5-second timeout
4. If test crashes: parent catches it
5. If test hangs: timeout kills it
6. Parent moves to next test
7. Summary shows all results
```

## When to Use Each Mode

### Use Batch Mode (Default)
```bash
./libft_tester
```
- Your code is stable and doesn't crash
- You want the fastest possible test
- You're just validating everything works

### Use Safe Mode (NEW!)
```bash
./libft_tester -s
```
- Your code has crashes/segfaults
- You want to test everything at once
- You need a crash report
- You're debugging incomplete functions

### Use Interactive Mode
```bash
./libft_tester -i
```
- You want to choose which tests to run
- You want to view failure traces
- You're doing detailed debugging
- You want to understand why tests failed

## Common Issues

### Issue: Still crashing even with -s
**Solution**: This is rare. Try running in a terminal session tool:
```bash
tmux new-session "./libft_tester -s"
```

### Issue: Tests take too long
**Solution**: Normal due to process forking overhead. Use batch mode if not needed:
```bash
./libft_tester  # Faster, but no crash protection
```

### Issue: Want different timeout
**Edit**: `isolation.h`
```c
#define TEST_TIMEOUT 10  /* Change from 5 to 10 seconds */
```
Then: `make re`

## File Overview

| File | Purpose |
|------|---------|
| `isolation.h` | Isolation system declarations |
| `isolation.c` | Process forking & crash handling |
| `isolated_tests.c` | Test wrappers for isolation |
| `tester.h` | Main tester header |
| `main.c` | Entry point with mode selection |

## Exit Codes

```bash
./libft_tester -s
echo $?  # Shows exit code
```

| Code | Meaning |
|------|---------|
| 0 | All tests passed |
| 1 | Some tests failed or crashed |

## Pro Tips

1. **Start with Safe Mode**
   ```bash
   ./libft_tester -s
   ```

2. **Identify Crashes**
   Look for `[CRASH]` in output

3. **Fix Crashes First**
   Prioritize SIGSEGV over other errors

4. **Switch to Batch Mode When Done**
   ```bash
   ./libft_tester
   ```

5. **Use Interactive for Details**
   ```bash
   ./libft_tester -i
   # Then choose option 4 to view traces
   ```

## Documentation Files

| File | Contains |
|------|----------|
| `CRASH_ISOLATION_GUIDE.md` | Complete user guide |
| `CRASH_ISOLATION_IMPLEMENTATION.md` | Technical details |
| `README.md` | General documentation |
| `QUICK_START.md` | Quick setup guide |

## Example Workflow

```bash
# 1. Run in safe mode to find crashes
./libft_tester -s
# Output shows: ft_split crashes with SIGSEGV

# 2. Fix the crash in ft_split

# 3. Test again in safe mode
./libft_tester -s
# Output shows: ft_split now passes (no crash)

# 4. Run other tests to find more issues
./libft_tester -i
# Choose "Run Part 2 Tests Only"

# 5. Once everything is stable
./libft_tester
# Fast validation in batch mode
```

## Remember

**Safe Mode enables process isolation:**
- ✅ Each test runs in its own process
- ✅ Crashes are caught automatically
- ✅ Program never crashes unexpectedly
- ✅ You get a complete test report
- ✅ Find all problems at once

**Use it when debugging broken code!** 🛡️
