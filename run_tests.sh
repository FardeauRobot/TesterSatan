#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
BOLD='\033[1m'
RESET='\033[0m'

# Print header
print_header() {
    echo -e "${BOLD}${CYAN}╔════════════════════════════════════════════════════════════════╗${RESET}"
    echo -e "${BOLD}${CYAN}║                                                                ║${RESET}"
    echo -e "${BOLD}${CYAN}║              LIBFT COMPREHENSIVE TESTER                        ║${RESET}"
    echo -e "${BOLD}${CYAN}║                  School 42 Project                             ║${RESET}"
    echo -e "${BOLD}${CYAN}║                                                                ║${RESET}"
    echo -e "${BOLD}${CYAN}╚════════════════════════════════════════════════════════════════╝${RESET}"
    echo ""
}

# Check if libft path is provided
LIBFT_DIR="../libft"

if [ $# -eq 1 ]; then
    LIBFT_DIR="$1"
fi

# Main script
clear
print_header

echo -e "${BLUE}Looking for libft in: ${YELLOW}${LIBFT_DIR}${RESET}"
echo ""

# Check if libft directory exists
if [ ! -d "$LIBFT_DIR" ]; then
    echo -e "${RED}✗ Error: Directory ${LIBFT_DIR} not found!${RESET}"
    echo -e "${YELLOW}Usage: $0 [path/to/libft]${RESET}"
    echo -e "${YELLOW}Example: $0 ../libft${RESET}"
    exit 1
fi

# Check if libft.h exists
if [ ! -f "$LIBFT_DIR/libft.h" ]; then
    echo -e "${RED}✗ Error: libft.h not found in ${LIBFT_DIR}${RESET}"
    exit 1
fi

echo -e "${GREEN}✓ Found libft.h${RESET}"

# Check if libft.a exists
if [ ! -f "$LIBFT_DIR/libft.a" ]; then
    echo -e "${YELLOW}⚠ libft.a not found. Compiling libft...${RESET}"
    
    # Try to compile libft
    make -C "$LIBFT_DIR" > /dev/null 2>&1
    
    if [ ! -f "$LIBFT_DIR/libft.a" ]; then
        echo -e "${RED}✗ Error: Failed to compile libft.a${RESET}"
        echo -e "${YELLOW}Please compile libft manually:${RESET}"
        echo -e "${YELLOW}  cd ${LIBFT_DIR} && make${RESET}"
        exit 1
    fi
    
    echo -e "${GREEN}✓ libft.a compiled successfully${RESET}"
else
    echo -e "${GREEN}✓ Found libft.a${RESET}"
fi

echo ""
echo -e "${BLUE}════════════════════════════════════════════════════════════════${RESET}"
echo -e "${BOLD}${YELLOW}Compiling tester...${RESET}"
echo -e "${BLUE}════════════════════════════════════════════════════════════════${RESET}"
echo ""

# Compile the tester
make re LIBFT_DIR="$LIBFT_DIR"

if [ $? -ne 0 ]; then
    echo ""
    echo -e "${RED}✗ Compilation failed!${RESET}"
    exit 1
fi

echo ""
echo -e "${BLUE}════════════════════════════════════════════════════════════════${RESET}"
echo -e "${BOLD}${GREEN}Running tests...${RESET}"
echo -e "${BLUE}════════════════════════════════════════════════════════════════${RESET}"
echo ""

# Run the tester
./libft_tester

# Capture exit code
EXIT_CODE=$?

echo ""
if [ $EXIT_CODE -eq 0 ]; then
    echo -e "${BOLD}${GREEN}════════════════════════════════════════════════════════════════${RESET}"
    echo -e "${BOLD}${GREEN}    ALL TESTS PASSED! Your libft is working correctly! 🎉${RESET}"
    echo -e "${BOLD}${GREEN}════════════════════════════════════════════════════════════════${RESET}"
else
    echo -e "${BOLD}${RED}════════════════════════════════════════════════════════════════${RESET}"
    echo -e "${BOLD}${RED}    SOME TESTS FAILED - Please review the output above ⚠️${RESET}"
    echo -e "${BOLD}${RED}════════════════════════════════════════════════════════════════${RESET}"
fi

echo ""
echo -e "${CYAN}Cleaning up temporary files...${RESET}"
make clean > /dev/null 2>&1
echo -e "${GREEN}✓ Done${RESET}"
echo ""

exit $EXIT_CODE
