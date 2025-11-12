# 🚀 QUICK START GUIDE

## TL;DR - Just Run This!

### Interactive Mode (Recommended! ⭐)
```bash
make
./libft_tester -i
```

### Quick Batch Test
```bash
./run_tests.sh /path/to/your/libft
```

---

## 📋 Prerequisites Checklist

Before running the tester, make sure you have:

- ✅ Your libft project directory
- ✅ `libft.h` header file in your libft
- ✅ `libft.a` compiled (or Makefile to compile it)
- ✅ All mandatory functions implemented

---

## 🎯 Four Ways to Use This Tester

### 1️⃣ Interactive Mode (NEW! Recommended ⭐)
```bash
make
./libft_tester -i
```
This gives you:
- **Menu interface** to choose what to test
- **Failure traces** with detailed advice
- **View past results** without re-running tests
- **Offline operation** - no internet needed
- **Persistent logging** to `.libft_test_traces.log`

**Menu Options:**
1. Run all tests (Part 1 + Part 2)
2. Run Part 1 tests only
3. Run Part 2 tests only
4. View last test failures with advice
5. Clear trace history
6. Help & documentation

### 2️⃣ Automatic Script (Quickest)
```bash
./run_tests.sh ../libft
```
This will automatically:
- Find your libft
- Compile it if needed
- Compile the tester
- Run all tests
- Clean up after

### 3️⃣ Batch Mode (Using Make)
```bash
make run LIBFT_DIR=../libft
# or just
./libft_tester
```

### 4️⃣ Manual Steps
```bash
# Step 1: Compile your libft
cd /path/to/libft
make

# Step 2: Compile the tester
cd /path/to/TesterV2
make LIBFT_DIR=/path/to/libft

# Step 3: Run it
./libft_tester          # Batch mode
# or
./libft_tester -i       # Interactive mode
```

---

## 📊 What Gets Tested

### Part 1 - Libc Functions (21 functions)
Character: `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`  
String: `strlen`, `strlcpy`, `strlcat`, `strchr`, `strrchr`, `strncmp`, `strnstr`, `atoi`  
Memory: `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`  
Convert: `toupper`, `tolower`

### Part 2 - Additional Functions (13 functions)
Allocate: `calloc`, `strdup`  
Strings: `substr`, `strjoin`, `strtrim`, `split`, `itoa`, `strmapi`, `striteri`  
File I/O: `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd`

**Total: 34 functions with 200+ tests!**

---

## 🎨 Output Legend

```
✓ Green = Test Passed ✅
✗ Red   = Test Failed ❌

Function Summary:
[6/6 tests passed]  ← All tests passed for this function

Final Summary:
Shows overall statistics and percentage
```

---

## 🔧 Common Setup Issues

### Issue: "libft.a not found"
**Solution:**
```bash
cd /path/to/your/libft
make
```

### Issue: "Permission denied"
**Solution:**
```bash
chmod +x run_tests.sh
```

### Issue: "Compilation failed"
**Solution:**
- Check your libft compiles: `cd libft && make`
- Check function prototypes match the subject
- Ensure all functions are implemented

---

## 💡 Pro Tips

1. **Test Often**: Don't wait until everything is done
   ```bash
   # After implementing a few functions:
   ./run_tests.sh ../libft
   ```

2. **Debug Failures**: When a test fails, the output shows exactly what went wrong
   
3. **Memory Leaks**: Check for leaks with valgrind:
   ```bash
   make LIBFT_DIR=../libft
   valgrind --leak-check=full ./libft_tester
   ```

4. **Focus on One Function**: Comment out tests in `main.c` to test specific functions

5. **Compare with Libc**: Most tests compare your function with the standard library

---

## 🎯 What Each File Does

| File | Purpose |
|------|---------|
| `run_tests.sh` | **USE THIS** - Automatic test runner |
| `Makefile` | Compiles the tester |
| `main.c` | Orchestrates all tests |
| `tester.h` | Header with all declarations |
| `utils.c` | Pretty printing and statistics |
| `test_char.c` | Character function tests |
| `test_string.c` | String function tests (part 1) |
| `test_string2.c` | String function tests (part 2) |
| `test_memory.c` | Memory function tests |
| `test_part2.c` | Part 2 function tests (part 1) |
| `test_part2_extra.c` | Part 2 function tests (part 2) |
| `test_fd.c` | File descriptor function tests |

---

## ⚡ Quick Commands Reference

```bash
# Run all tests (recommended)
./run_tests.sh ../libft

# Just compile (don't run)
make LIBFT_DIR=../libft

# Compile and run
make run LIBFT_DIR=../libft

# Clean up
make clean

# Full clean (remove executable)
make fclean

# Recompile everything
make re LIBFT_DIR=../libft

# Show help
make help
```

---

## 🎓 Understanding Test Results

### Example Output:
```
┌────────────────────────────────────────────┐
│ [01] Testing: ft_strlen                    │
└────────────────────────────────────────────┘
  ✓ Empty string
  ✓ Single character
  ✓ Normal string
  ✓ String with spaces
  ✓ String with special characters
  ✓ Long string (999 chars)
  [6/6 tests passed]
```

This means:
- All 6 tests for `ft_strlen` passed
- The function handles all edge cases correctly
- Move on to the next function! 🎉

---

## 🐛 Debugging Tips

### If a test fails:

1. **Read the test name** - It tells you what case failed
   Example: `"Empty string"` → Your function doesn't handle empty strings

2. **Check the test file** - Look at the test code to understand what's expected
   Example: For `ft_strlen`, check `test_string.c`

3. **Compare with libc** - Most tests compare with standard functions
   ```c
   if (ft_strlen("test") != strlen("test"))
   ```

4. **Test manually** - Write a simple test program:
   ```c
   #include "libft.h"
   #include <stdio.h>
   
   int main(void)
   {
       printf("Result: %zu\n", ft_strlen(""));
       return 0;
   }
   ```

---

## 🎉 When All Tests Pass

You'll see:
```
╔════════════════════════════════════════════╗
║          TEST SUMMARY                      ║
╠════════════════════════════════════════════╣
║  Functions Tested:  34                     ║
║  Functions Passed:  34        [100%]       ║
║  Functions Failed:  0                      ║
║                                            ║
║  Total Tests:      200+                    ║
║  Tests Passed:     200+       [100%]       ║
║  Tests Failed:     0                       ║
╚════════════════════════════════════════════╝

   🎉 CONGRATULATIONS! ALL TESTS PASSED! 🎉
```

**Now you're ready to submit your Libft! 🚀**

---

## 📞 Need Help?

1. **Read this guide** - Most answers are here
2. **Check README.md** - More detailed information
3. **Read error messages** - They tell you what's wrong
4. **Compare with libc** - Test with standard library functions
5. **Use a debugger** - gdb or lldb can help find issues

---

## 📚 Quick Reference: Function Signatures

Need to check a function signature? They should match these:

```c
// Part 1 - Character
int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);
int     ft_toupper(int c);
int     ft_tolower(int c);

// Part 1 - String
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
size_t  ft_strlcat(char *dst, const char *src, size_t size);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strnstr(const char *big, const char *little, size_t len);
int     ft_atoi(const char *nptr);

// Part 1 - Memory
void    *ft_memset(void *s, int c, size_t n);
void    ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
void    *ft_memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);

// Part 2
void    *ft_calloc(size_t nmemb, size_t size);
char    *ft_strdup(const char *s);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s1, char const *set);
char    **ft_split(char const *s, char c);
char    *ft_itoa(int n);
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void    ft_striteri(char *s, void (*f)(unsigned int, char*));
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putendl_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);
```

---

**Happy Coding! May all your tests be green! 🍀**
