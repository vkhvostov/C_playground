# ft_printf project

## Description 📖

A custom implementation of the C standard library's `printf` function. This project recreates the core functionality of `printf`, handling various format specifiers and providing similar output behavior.

## Features 🌟

### Supported Format Specifiers

- `%c` - Single character
- `%s` - String
- `%p` - Pointer address
- `%d` - Signed decimal integer
- `%i` - Signed decimal integer
- `%u` - Unsigned decimal integer
- `%x` - Unsigned hexadecimal integer (lowercase)
- `%X` - Unsigned hexadecimal integer (uppercase)
- `%%` - Percentage sign

### Return Value
- Returns the number of characters printed
- Returns -1 on error

## Technical Details 🔧

### Core Functions
- `ft_printf()` - Main function that processes the format string
- Format specifier handlers:
  - `print_char()` - Character printing
  - `print_string()` - String printing
  - `print_pointer()` - Pointer address printing
  - `print_integer()` - Integer printing
  - `print_unsigned()` - Unsigned integer printing
  - `print_hex()` - Hexadecimal number printing

### Memory Management
- Careful memory allocation and deallocation for number conversions
- Dynamic string handling for various format types

### Error Handling
- Robust error checking for memory allocations
- Proper handling of NULL pointers and edge cases

## Usage 🚀

```c
#include "ft_printf.h"

int main() {
    // Basic usage
    ft_printf("Hello, %s!\n", "world");
    
    // Multiple format specifiers
    ft_printf("Number: %d, String: %s, Char: %c\n", 42, "test", 'X');
    
    // Hexadecimal and pointer printing
    int num = 255;
    ft_printf("Hex: %x, Pointer: %p\n", num, &num);
}
```

## Platform-Specific Notes ⚠️

- **Pointer Printing**
  - macOS: NULL pointers print as `0x0`
  - Linux: NULL pointers print as `(nil)`

- **Variable Arguments**
  - macOS: `va_list` should be passed as pointer
  - Linux: `va_list` can be passed directly

## Building 🔨

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Recompile everything
```

## Return Values 📊

- Success: Number of characters printed
- Error: -1
