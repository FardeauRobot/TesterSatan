# 🎯 LIBFT COMPREHENSIVE TESTER

A complete and detailed testing suite for the **Libft** project from School 42. This tester provides extensive coverage of all mandatory functions with beautiful, colorful output and comprehensive edge case testing.

---

## 📋 Features

✨ **Comprehensive Testing**
- Tests all Part 1 (libc functions) and Part 2 (additional functions)
- 6-15 tests per function covering edge cases
- Total of **200+ individual tests**

🎨 **Beautiful Visual Output**
- Color-coded results (Green = Pass, Red = Fail)
- Detailed progress indicators
- Summary statistics with percentages
- Clear function headers and test descriptions

🔍 **Edge Case Coverage**
- Boundary values (INT_MIN, INT_MAX, etc.)
- Empty strings and NULL pointers
- Zero-length operations
- Overlapping memory regions
- Extended ASCII characters
- Large buffers

📊 **Detailed Statistics**
- Per-function pass/fail tracking
- Overall test summary
- Percentage calculations
- Function-level and test-level metrics

---

## 🚀 Quick Start

### Option 1: Interactive Mode (NEW! ⭐)

```bash
# Compile and run in interactive mode
make
./libft_tester -i
# or
./libft_tester --interactive
```

**Interactive Features:**
- 🧪 Run all tests or select Part 1/Part 2 only
- 📊 View detailed failure traces with advice
- 🗑️ Clear trace history
- 📖 Built-in help and documentation
- 💾 Persistent trace logging to `.libft_test_traces.log`

### Option 2: Safe Mode (Crash Protection) 🛡️

```bash
# Run with crash isolation - each test runs in its own process
./libft_tester -s
# or
./libft_tester --safe
```

**Safe Mode Features:**
- 🛡️ **Process Isolation** - Each test runs in a child process
- ⚡ **Crash Protection** - If one test crashes, others continue
- ⏱️ **Timeout Protection** - Tests that hang are automatically killed (5s timeout)
- 📍 **Detailed Reports** - Shows which test crashed and why
- 🔧 **Perfect for Debugging** - Find problematic functions safely

**When to Use Safe Mode:**
- You suspect some functions might crash
- Your code has memory issues causing segfaults
- You want to test everything even if something is broken
- You need a crash report before fixing issues

### Option 3: Batch Mode (Quick Test)

```bash
# Run all tests in batch mode
make run
# or
./libft_tester
```

### Option 4: Using the Automated Script

```bash
# If your libft is in ../libft (default)
./run_tests.sh

# Or specify a custom path
./run_tests.sh /path/to/your/libft
```

### Option 5: Using Make

```bash
# Set LIBFT_DIR in Makefile, then:
make run

# Or specify the path directly:
make run LIBFT_DIR=/path/to/your/libft
```

---

## 📁 Project Structure

```
TesterV2/
├── main.c                 # Main test runner
├── utils.c                # Utility functions (stats, printing)
├── tester.h               # Header file with all declarations
├── test_char.c            # Tests for character functions (isalpha, isdigit, etc.)
├── test_string.c          # Tests for string functions (strlen, strchr, etc.)
├── test_string2.c         # More string tests (strlcpy, strlcat, atoi, etc.)
├── test_memory.c          # Tests for memory functions (memset, memcpy, etc.)
├── test_part2.c           # Tests for Part 2 functions (calloc, strdup, etc.)
├── test_part2_extra.c     # More Part 2 tests (strtrim, split, itoa, etc.)
├── test_fd.c              # Tests for file descriptor functions
├── Makefile               # Build configuration
├── run_tests.sh           # Automated test script
└── README.md              # This file
```

---

## 📝 Functions Tested

### Part 1: Libc Functions

#### Character Functions (5 functions)
- `ft_isalpha` - 6 tests
- `ft_isdigit` - 6 tests
- `ft_isalnum` - 6 tests
- `ft_isascii` - 6 tests
- `ft_isprint` - 6 tests

#### String Functions (8 functions)
- `ft_strlen` - 6 tests
- `ft_strlcpy` - 6 tests
- `ft_strlcat` - 6 tests
- `ft_strchr` - 7 tests
- `ft_strrchr` - 7 tests
- `ft_strncmp` - 7 tests
- `ft_strnstr` - 7 tests
- `ft_atoi` - 10 tests

#### Memory Functions (6 functions)
- `ft_memset` - 6 tests
- `ft_bzero` - 5 tests
- `ft_memcpy` - 6 tests
- `ft_memmove` - 6 tests
- `ft_memchr` - 6 tests
- `ft_memcmp` - 6 tests

#### Conversion Functions (2 functions)
- `ft_toupper` - 6 tests
- `ft_tolower` - 6 tests

### Part 2: Additional Functions

#### Memory Allocation (2 functions)
- `ft_calloc` - 6 tests
- `ft_strdup` - 6 tests

#### String Manipulation (7 functions)
- `ft_substr` - 7 tests
- `ft_strjoin` - 6 tests
- `ft_strtrim` - 7 tests
- `ft_split` - 6 tests
- `ft_itoa` - 7 tests
- `ft_strmapi` - 6 tests
- `ft_striteri` - 6 tests

#### File Descriptor Functions (4 functions)
- `ft_putchar_fd` - 4 tests
- `ft_putstr_fd` - 5 tests
- `ft_putendl_fd` - 5 tests
- `ft_putnbr_fd` - 6 tests

---

## 🔧 Setup Instructions

### Prerequisites

1. Your `libft` project with:
   - `libft.h` header file
   - `libft.a` compiled library (or Makefile to build it)

### Installation

1. Clone or download this tester:
```bash
cd ~/Desktop/Labo
git clone <repository-url> TesterV2
cd TesterV2
```

2. Make sure the script is executable:
```bash
chmod +x run_tests.sh
```

3. Run the tests:
```bash
./run_tests.sh ../libft
```

---

## 🎮 Usage

### Basic Usage

The simplest way to test your libft:

```bash
./run_tests.sh /path/to/your/libft
```

### Manual Compilation

If you prefer to compile manually:

```bash
# 1. Ensure your libft is compiled
cd /path/to/your/libft
make

# 2. Go back to the tester directory
cd /path/to/TesterV2

# 3. Compile the tester
make LIBFT_DIR=/path/to/your/libft

# 4. Run the tester
./libft_tester
```

### Makefile Targets

```bash
make              # Compile the tester
make run          # Compile and run tests
make clean        # Remove object files
make fclean       # Remove all compiled files
make re           # Recompile everything
make help         # Show help message
```

---

## 📊 Understanding the Output

### Test Results

- ✅ **Green ✓** = Test passed
- ❌ **Red ✗** = Test failed

### Function Summary

After each function's tests, you'll see:
```
[6/6 tests passed]
```

### Final Summary

At the end, you'll get:
- Total functions tested
- Functions passed/failed with percentage
- Total tests run
- Tests passed/failed with percentage

### Exit Codes

- `0` = All tests passed
- `1` = Some tests failed

---

## � Trace System & Debugging

### Failure Tracking

The tester includes an advanced trace system that logs all test failures with detailed information:

- **Function name** - Which function failed
- **Test name** - Specific test case that failed
- **Timestamp** - When the failure occurred
- **Expected vs Got** - What was expected and what your function returned
- **Advice** - Suggestions on how to fix the issue

### Using Traces

**In Interactive Mode:**
1. Run tests (options 1, 2, or 3)
2. Select option 4 to view detailed failure traces
3. Follow the advice to fix issues
4. Run tests again to verify fixes

**Trace File:**
- Failures are saved to `.libft_test_traces.log`
- This file is created in the tester directory
- Persists across runs until cleared
- Can be viewed with: `cat .libft_test_traces.log`

**Clearing Traces:**
- Use option 5 in interactive mode
- Or manually: `rm .libft_test_traces.log`
- Or use: `make clean`

### Offline Operation

✅ **Fully Offline Capable**
- No internet connection required
- All functionality works locally
- Traces stored locally in `.libft_test_traces.log`
- No external dependencies (except libbsd)

---

## 🛡️ Crash Isolation & Safety

### Safe Mode (Process Isolation)

The tester includes a **crash isolation system** that protects your test suite from crashing functions:

```bash
./libft_tester -s
# or
./libft_tester --safe
```

### How It Works

1. **Process Forking**: Each test function runs in its own child process
2. **Signal Handling**: Crashes (segfaults, aborts) are caught before affecting the main program
3. **Timeout Protection**: Tests that hang or take too long are automatically killed
4. **Graceful Recovery**: The tester continues with remaining tests even if one crashes
5. **Detailed Reporting**: Shows exactly which test crashed and why

### What Gets Protected

- **Segmentation Faults** (SIGSEGV) - Out-of-bounds memory access
- **Abort Signals** (SIGABRT) - Assertion failures
- **Bus Errors** (SIGBUS) - Misaligned memory access
- **Floating Point Errors** (SIGFPE) - Division by zero
- **Illegal Instructions** (SIGILL) - Invalid CPU instruction
- **Timeouts** - Tests exceeding 5-second limit

### When to Use Safe Mode

✅ Use Safe Mode when:
- Your libft might have memory bugs causing crashes
- You want to find all broken functions at once
- You need to test even when some functions are incomplete
- You're debugging segmentation faults
- You want a complete crash report

❌ Regular mode is fine when:
- Your libft compiles and runs without crashes
- You just want quick validation
- You're in interactive mode (already has per-function execution)

### Safe Mode Example Output

```
[CRASH] Test 'ft_split' killed by signal 11 (Segmentation fault)
[TIMEOUT] Test 'ft_itoa' exceeded 5 seconds
[CRASH] Test 'ft_strmapi' exited with code 134
```

This tells you exactly which functions are problematic so you can fix them first.

### Offline Operation

✅ **Fully Offline Capable**
- No internet connection required
- All functionality works locally

---

## �🐛 Troubleshooting

### Common Issues

#### "libft.a not found"
- Make sure your libft is compiled: `cd /path/to/libft && make`
- Check the path you provided is correct

#### "libft.h not found"
- Ensure `libft.h` exists in your libft directory
- Check the LIBFT_DIR variable in Makefile

#### Compilation Errors
- Make sure your libft compiles without errors
- Check that all required functions are implemented
- Verify function prototypes match the subject

#### Segmentation Fault
- Check for NULL pointer handling in your functions
- Verify memory allocation in functions like `ft_split`, `ft_substr`, etc.
- Use valgrind to check for memory issues:
  ```bash
  valgrind --leak-check=full ./libft_tester
  ```

---

## 🎯 Test Coverage Details

### Edge Cases Covered

#### Character Functions
- Valid ranges (letters, digits)
- Boundaries (before 'A', after 'Z', etc.)
- Special characters
- Extended ASCII
- Negative values

#### String Functions
- Empty strings
- NULL terminators
- Very long strings
- Strings with special characters
- Buffer size edge cases

#### Memory Functions
- Zero-length operations
- Large buffers
- Overlapping memory regions
- NULL pointers
- Binary data

#### Conversion Functions
- Minimum and maximum values (INT_MIN, INT_MAX)
- Zero
- Negative numbers
- Leading/trailing whitespace
- Invalid input

---

## 💡 Tips for Success

1. **Read the Error Messages**: The tester provides detailed output about what failed
2. **Test Incrementally**: Don't wait until all functions are done to test
3. **Check Your Makefile**: Ensure your libft Makefile is correct
4. **Use a Debugger**: For failing tests, use gdb or lldb to debug
5. **Memory Check**: Run with valgrind to ensure no leaks
6. **Compare with Libc**: The tester compares your functions with standard library versions

---

## 🔍 Memory Leak Detection

To check for memory leaks:

```bash
# Compile the tester
make LIBFT_DIR=/path/to/your/libft

# Run with valgrind
valgrind --leak-check=full --show-leak-kinds=all ./libft_tester
```

---

## 📚 Additional Resources

- [42 Libft Subject](https://cdn.intra.42.fr/pdf/pdf/960/libft.en.pdf)
- [C Standard Library Reference](https://en.cppreference.com/w/c)
- [Linux Man Pages](https://man7.org/linux/man-pages/)

---

## 🤝 Contributing

Found a bug or want to add more tests? Feel free to:
1. Report issues
2. Suggest improvements
3. Add more edge cases

---

## ⚖️ License

This tester is provided for educational purposes for School 42 students.
Feel free to use, modify, and share!

---

## 📧 Support

If you encounter issues:
1. Check this README thoroughly
2. Review the error messages carefully
3. Test individual functions in isolation
4. Compare with standard library behavior

---

## 🎉 Good Luck!

May all your tests be green! 🍀

```
╔════════════════════════════════════════════════════════════════╗
║                                                                ║
║              LIBFT COMPREHENSIVE TESTER                        ║
║                  School 42 Project                             ║
║                                                                ║
╚════════════════════════════════════════════════════════════════╝
```

---

**Version**: 1.0  
**Last Updated**: November 2025  
**Tested With**: School 42 Libft Project  
**Compatibility**: Linux, macOS
