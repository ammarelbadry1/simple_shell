# Simple Shell Project

This project is a simple UNIX command line interpreter, often referred to as a "shell." It provides basic functionality for users to interact with their system through a command-line interface. This README file will guide you through the features and usage of this simple shell.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Error Handling](#error-handling)

## Features

### 1. Command Execution

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.

### 2. Command Parsing

- The shell can parse command lines with arguments.

### 3. Command Execution Errors

- If an executable cannot be found, it prints an error message and displays the prompt again.

### 4. Handling Errors

- The shell handles various errors gracefully and provides informative error messages to the user.

### 5. End of File Handling

- Handles the "end of file" condition (Ctrl+D) to exit the shell.

### 6. PATH Environment Variable

- Handles commands that are part of the PATH environment variable, allowing users to execute common system commands.

### 7. Built-in Commands

- Supports built-in commands such as `exit` and `env`.

### 8. Comment Handling

- Ignores comments in the command line (lines starting with `#`), making it easy to add comments to scripts.

## Getting Started

To get started with this simple shell, follow these steps:

1. Clone the project repository to your local machine:

    ```shell
    git clone https://github.com/your-username/simple-shell.git
    ```

2. Change your current directory to the project folder:

    ```shell
    cd simple-shell
    ```

3. Compile the shell:

    ```shell
    gcc main.c -o hsh
    ```

4. Run the shell:

    ```shell
    ./hsh
    ```

## Usage

Once the shell is running, you can enter commands and interact with your system using the simple shell. Here are some examples:

- Execute a system command:

    ```shell
    ls -l
    ```

- Run a built-in command:

    ```shell
    exit
    ```

- Use comments in your script:

    ```shell
    echo "Hello, world!" # This is a comment
    ```

## Built-in Commands

The simple shell supports the following built-in commands:

- `exit`: Exit the shell.
- `env`: Display the current environment variables.

To use a built-in command, simply enter the command at the shell prompt.

## Error Handling

The shell provides detailed error messages for various situations, including:

- Command not found.
- Invalid input.
- File or directory not found.

The error messages are designed to help you understand and resolve issues with your commands.

___

Enjoy using the Simple Shell! If you have any questions or encounter issues, please feel free to reach out for assistance.
