# Lexical Analyzer

## Description

A C-based Lexical Analyzer that reads a C source file and identifies different types of tokens such as keywords, identifiers, literals, operators, special symbols, and comments.

## Features

- Identifies C keywords
- Identifies identifiers
- Identifies integer and floating-point literals
- Identifies character literals
- Identifies string literals
- Identifies arithmetic and relational operators
- Identifies logical operators
- Identifies special symbols
- Handles single-line and multi-line comments
- Supports array declarations

## Technologies Used

- C Programming
- File Handling
- String Handling
- GCC Compiler

## Project Structure

| File | Description |
|------|-------------|
| `main.c` | Main function and file handling |
| `lexer.c` | Lexical analysis implementation |
| `lexer.h` | Function declaration |
| `input.c` | Sample C input file |

## How to Compile

```bash
gcc main.c lexer.c 
