# get_next_line project

## Description 📖

A function that reads text from a file descriptor line by line. This project focuses on understanding file I/O operations, static variables, and memory management in C. It represents a crucial utility for reading text files or input streams sequentially.

## Features 🌟

- Read text line by line from any valid file descriptor
- Handle multiple file descriptors simultaneously
- Support variable buffer sizes through compilation
- Clean memory management with no leaks
- Handle both files and standard input
- Support for large files

## Technical Details 🔧

### Core Function
```c
char *get_next_line(int fd);
```
- **Parameters:** File descriptor to read from
- **Returns:** Next line from the file, or NULL if nothing left to read or error
- **Buffer Size:** Configurable via BUFFER_SIZE macro during compilation

### Memory Management
- Static buffer for maintaining state between calls
- Dynamic memory allocation for line storage
- Proper memory cleanup on errors or EOF
- No memory leaks in any scenario

### Implementation Features
- Uses static array to handle multiple file descriptors
- Efficient buffer management with configurable size
- Handles partial reads and line breaks correctly
- Proper EOF and error handling

## Usage 🚀

```c
#include "get_next_line.h"

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        // Process the line
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## Compilation 🔨

```bash
# Compile with custom buffer size
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

# Default buffer size is 10 if not specified
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
```

## Limitations ⚠️

- Maximum file descriptors: 1024 (FD_MAX)
- Buffer size affects memory usage and performance
- Must handle memory deallocation in calling function
- No backward seeking or line skipping
