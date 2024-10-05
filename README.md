### CSC 357 Assignment 1 - Build Automation

Purpose:
- This assignment focuses on automating the process of building software by compiling source code into a complete software program.
- The tasks include converting characters between tabs and spaces, and removing non-plain text characters while reading input and printing corresponding outputs.

Tasks and Specifics:

Ground Rules:
- The programs should be developed and tested on the Cal Poly UNIX servers.
- Familiarity with basic UNIX commands (e.g., cd, ls, gcc) is required to compile and run the C programs on these servers.
- Code must be compiled using gcc with specific flags like -Wall, -Wextra, -Werror, -ansi, and -pedantic.
  
GitHub Integration:
- Submit assignments through GitHub Classroom.
- Ensure all programs are pushed to the designated GitHub repository created for this assignment.
- Automated grading feedback will be provided through GitHub issues.
  
Static Variables and Strings:
- You are required to implement functions that convert between tabs and spaces, ensuring the characters are represented as plain text.
- C strings (null-terminated character arrays) should be handled correctly, with special handling for newline and tab characters.
- Helper functions can be added, but they must conform to the given function prototypes.
  
Programs to Complete:
- chars.c: Implement functions to convert characters between tabs and spaces, following the specifications in the provided chars.h file.
- detab.c: Convert tabs into spaces and remove any non-plain text characters from input.
- entab.c: Convert spaces into tabs, similar to detab but performs the inverse operation.
- Programs should process arbitrary user input and output the corresponding converted text.

Testing:
- Basic unit testing is provided in chartests.c using the assert macro from the standard library.
- A provided Makefile includes targets for compiling and testing the programs.
- The detab and entab programs should be tested using specific input/output text files and compared using diff to ensure correctness.
- Custom tests are encouraged to ensure the programs handle all edge cases.
