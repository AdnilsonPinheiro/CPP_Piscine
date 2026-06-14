#!/bin/bash

# Colors for pretty printing
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Path to your executable
EXECUTABLE="./converter"

if [ ! -f "$EXECUTABLE" ]; then
    echo -e "${RED}Error: Executable '$EXECUTABLE' not found. Please compile your program first.${NC}"
    exit 1
fi

run_test() {
    local category=$1
    local input=$2
    echo -e "${BLUE}------------------------------------------------------${NC}"
    echo -e "${YELLOW}Category: $category | Input: '$input'${NC}"
    echo -e "${BLUE}------------------------------------------------------${NC}"
    $EXECUTABLE "$input"
    echo ""
}

# ==============================================================================
# 1. CHAR LITERALS
# ==============================================================================
echo -e "${GREEN}=== Testing Char Literals ===${NC}"
run_test "Standard Char" "a"
run_test "Standard Char (Symbol)" "*"

# ==============================================================================
# 2. INT LITERALS
# ==============================================================================
echo -e "${GREEN}=== Testing Integer Literals ===${NC}"
run_test "Zero Int" "0"
run_test "Positive Int" "42"
run_test "Negative Int" "-42"
run_test "Max Int" "2147483647"
run_test "Min Int" "-2147483648"

# ==============================================================================
# 3. FLOAT LITERALS
# ==============================================================================
echo -e "${GREEN}=== Testing Float Literals ===${NC}"
run_test "Zero Float" "0.0f"
run_test "Positive Float" "42.42f"
run_test "Negative Float" "-4.2f"
run_test "Float with active precision" "0.123456f"

# ==============================================================================
# 4. DOUBLE LITERALS
# ==============================================================================
echo -e "${GREEN}=== Testing Double Literals ===${NC}"
run_test "Zero Double" "0.0"
run_test "Positive Double" "42.42"
run_test "Negative Double" "-4.2"

# ==============================================================================
# 5. PSEUDO-LITERALS (Science & Fun)
# ==============================================================================
echo -e "${GREEN}=== Testing Pseudo-literals ===${NC}"
run_test "Float Nan" "nanf"
run_test "Float +Inf" "+inff"
run_test "Float -Inf" "-inff"
run_test "Double Nan" "nan"
run_test "Double +Inf" "+inf"
run_test "Double -Inf" "-inf"

# ==============================================================================
# 6. EDGE CASES & OVERFLOWS
# ==============================================================================
echo -e "${GREEN}=== Testing Edge Cases & Overflows ===${NC}"
run_test "Non-displayable Char conversion (from Int)" "0"
run_test "Non-displayable Char conversion (from Int 127)" "127"
run_test "Int Overflow (+1)" "2147483648"
run_test "Int Underflow (-1)" "-2147483649"
run_test "Massive Float Overflow" "3.40282e+39f"
run_test "Massive Double Overflow" "1.79769e+309"

# ==============================================================================
# 7. INVALID INPUTS
# ==============================================================================
echo -e "${GREEN}=== Testing Invalid Inputs ===${NC}"
run_test "Empty String" ""
run_test "Multiple Chars" "abc"
run_test "Malformed Float (No trailing f)" "42.42f42"
run_test "Malformed Float (Multiple f's)" "42.42ff"
run_test "Multiple Decimals" "42.42.42"
run_test "Trailing Garbage" "42abc"
run_test "Leading Garbage" "abc42"
run_test "Just a sign" "+"
run_test "Just a dot" "."

echo -e "${GREEN}=== Testing complete ===${NC}"