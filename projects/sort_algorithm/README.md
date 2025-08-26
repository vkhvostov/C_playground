# Sort Algorithm Project

## Description 📖

A C program that implements and demonstrates efficient sorting algorithms using stack operations. The project is inspired by the "push_swap" challenge and focuses on sorting a sequence of integers with a limited set of stack-based instructions.

## Features 🌟

- Efficient sorting using only stack operations
- Handles various input sizes and edge cases
- Custom implementation of list and stack utilities
- Error handling for invalid input and memory issues
- Modular code structure for easy extension and testing

## Technical Details 🔧

### Core Components

1. **Stack Operations**
	- Push, swap, rotate, and reverse rotate operations
	- Separate implementations for both stacks (A and B)
	- Instruction recording for output and validation

2. **Sorting Algorithms**
	- Optimized sorting for small and large input sets
	- Longest Increasing Subsequence (LIS) based approach
	- Efficient movement of elements between stacks

3. **Input Validation**
	- Checks for valid integers and duplicates
	- Handles edge cases (empty input, single element, etc.)

4. **Utilities**
	- Custom linked list implementation
	- Memory management helpers
	- Instruction validation and testing scripts

## Usage 🚀

```bash
./push_swap [numbers...]
```

### Example
```bash
./push_swap 3 2 1
# Output: sa rra
```

## Error Handling ⚠️

The program handles various error scenarios:
- Invalid or non-integer input
- Duplicate numbers
- Memory allocation failures
- Incorrect usage

Error messages include:
- Program name
- Error description
- System error message when applicable

## Building 🔨

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

## Exit Values 📊

- 0: Successful execution
- 1: General error (invalid input, memory error, etc.)
