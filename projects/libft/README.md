# Libft Project

## Description 📖

A custom C library implementing essential functions from the standard C library and additional useful utilities. This library serves as a foundation for other C projects, providing reliable implementations of commonly used functions.

## Features 🌟

### Character Functions
Functions for character type checking and manipulation:
- `ft_isalpha` - Check for alphabetic character
- `ft_isdigit` - Check for decimal digit
- `ft_isalnum` - Check for alphanumeric character
- `ft_isascii` - Check for ASCII character
- `ft_isprint` - Check for printable character
- `ft_toupper` - Convert to uppercase
- `ft_tolower` - Convert to lowercase

### String Operations
String manipulation and analysis functions:
- `ft_strlen` - Get string length
- `ft_strchr` - Locate character in string
- `ft_strrchr` - Locate character from end of string
- `ft_strncmp` - Compare two strings
- `ft_strlcpy` - Size-bounded string copying
- `ft_strlcat` - Size-bounded string concatenation
- `ft_strnstr` - Locate substring in string
- `ft_strdup` - Create new string duplicate
- `ft_substr` - Extract substring from string
- `ft_strjoin` - Concatenate two strings
- `ft_strtrim` - Trim specified characters
- `ft_split` - Split string into array
- `ft_strmapi` - Apply function to each character
- `ft_striteri` - Iterate and modify string

### Memory Operations
Memory manipulation functions:
- `ft_memset` - Fill memory with constant byte
- `ft_bzero` - Zero a byte string
- `ft_memcpy` - Copy memory area
- `ft_memmove` - Copy memory area with overlap handling
- `ft_memchr` - Scan memory for character
- `ft_memcmp` - Compare memory areas
- `ft_calloc` - Allocate and zero memory

### Number Functions
Number conversion and manipulation:
- `ft_atoi` - Convert ASCII to integer
- `ft_itoa` - Convert integer to ASCII

### File Descriptor Operations
Output functions for file descriptors:
- `ft_putchar_fd` - Output char to file descriptor
- `ft_putstr_fd` - Output string to file descriptor
- `ft_putendl_fd` - Output string with newline
- `ft_putnbr_fd` - Output number to file descriptor

### Linked List Operations
A set of functions for manipulating a generic linked list structure:

```c
typedef struct s_list
{
    void *content;          // Pointer to data
    struct s_list *next;    // Pointer to next node
} t_list;
```

List manipulation functions:
- `ft_lstnew` - Create new list node
- `ft_lstadd_front` - Add node at beginning
- `ft_lstadd_back` - Add node at end
- `ft_lstsize` - Count list elements
- `ft_lstlast` - Get last node
- `ft_lstdelone` - Delete single node
- `ft_lstclear` - Delete entire list
- `ft_lstiter` - Iterate and apply function
- `ft_lstmap` - Create new list from function

## Building 🔨

```bash
make        # Compile the library
make bonus  # Include bonus functions (linked list)
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Recompile everything
```

## Usage 🚀

```c
#include "libft.h"

int main(void)
{
    // String manipulation
    char *str = "Hello, World!";
    size_t len = ft_strlen(str);
    
    // Memory operations
    void *mem = ft_calloc(10, sizeof(int));
    
    // Number conversions
    int num = ft_atoi("12345");
    char *str_num = ft_itoa(num);
    
    // List operations
    t_list *list = ft_lstnew("content");
    ft_lstadd_back(&list, ft_lstnew("more content"));
    
    // Don't forget to free allocated memory
    free(mem);
    free(str_num);
    ft_lstclear(&list, free);
    
    return (0);
}
```

## Error Handling ⚠️

- Memory allocation functions return NULL on failure
- String functions handle NULL pointers gracefully
- List functions check for NULL parameters
- File descriptor functions validate fd values
