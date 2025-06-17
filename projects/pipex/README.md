# Pipex Project

## Description 📖

A C program that simulates shell command pipelines, similar to the pipe operator (`|`) in bash. The program takes input from a file, executes a series of commands with their arguments, and writes the output to another file.

## Features 🌟

- Simulates shell pipes behavior
- Handles multiple commands in sequence
- Supports input/output redirection
- Error handling and child process management
- Command path resolution using PATH environment variable
- Memory leak prevention

## Technical Details 🔧

### Core Components

1. **Process Management**
   - Creates child processes for each command
   - Handles pipe communication between processes
   - Manages file descriptors for input/output

2. **Command Execution**
   - Parses command arguments
   - Resolves command paths using PATH environment variable
   - Executes commands using execve

3. **File Operations**
   - Input file handling
   - Output file creation/truncation
   - File descriptor management

## Usage 🚀

```bash
./pipex file1 cmd1 cmd2 ... file2
```

### Example
```bash
./pipex infile "ls -l" "wc -l" outfile
# Equivalent to: < infile ls -l | wc -l > outfile
```

## Error Handling ⚠️

The program handles various error scenarios:
- Invalid number of arguments
- File permission issues
- Command not found
- Memory allocation failures
- Pipe creation errors
- Fork failures

Error messages include:
- Program name
- Error description
- Affected component (file/command)
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
- 1: General error
- 127: Command not found
