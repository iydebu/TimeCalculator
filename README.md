# Time Calculator

A stylish command-line time calculator with ASCII art logo and sound effects. This program helps you add or subtract times with a user-friendly interface.

## Features

- Beautiful ASCII art TIME logo
- Colorful terminal interface
- Input validation with sound feedback
- Add or subtract times
- Shows result with day reference (Yesterday/Today/Tomorrow)
- Sound effects for interactions
- Clean and organized code structure

## Functions

- `printLogo()`: Displays the ASCII art TIME logo
- `clearTerminal()`: Clears screen and reprints logo
- `printTime()`: Formats time in HH:MM format
- `GetTime()`: Gets validated time input from user
- `GetOperator()`: Gets calculation choice (add/subtract)
- `calculate()`: Performs time calculations
- `printResult()`: Shows formatted result with day reference

## Requirements

- Windows operating system
- C++ compiler
- Terminal that supports ANSI color codes

## Usage

```bash
1. Run the program
2. Enter first time (hours and minutes)
3. Choose operation (1: Add, 2: Subtract)
4. Enter second time
5. View the calculated result
```

## Color Scheme

- Yellow: Headers and prompts
- Green: Input fields and results
- White: Default text

## Notes

- Time input uses 24-hour format
- Hours must be between 0-24
- Minutes must be between 0-60
- Invalid inputs trigger error sounds
- Successful operations play completion sounds

This project demonstrates:
- Input validation
- Time arithmetic
- Terminal formatting
- Sound integration
- User interface design

Feel free to contribute or report issues!
