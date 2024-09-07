## Compile and run

### Compile: option 1 
You can compile the program using the following `g++` command, specifying C++11 standard.

```bash
g++ -std=c++11 main.cpp KMPMatcher.cpp Manacher.cpp LCS.cpp -o myprogram
````

### Run 
After successful compilation, you can run the program by executing the following command
```bash 
./main 
```


### Compile: option 2
You can also compile the program using the `Makefile`we've provided by running the following command: 
```bash
make 
`````

### Run 
The execution of the code it's the same 
```bash
./main
```



# Test Cases Overview

### Test Case 1: Simple Palindrome and Pattern Matching
- Tests for basic palindromes and pattern matching.
- Patterns: `"abc"`, `"racecar"`, `"123"`.
- Expected to find full palindromes and matching patterns.

### Test Case 2: No Common Substring or Palindromes
- Tests when no common substrings or palindromes exist.
- Expected to return single-character palindromes.
- Patterns: `"abc"`, `"ghi"`, `"xyz"`.

### Test Case 3: Overlapping Patterns
- Tests for overlapping patterns like `"ab"` and `"bab"`.
- Long palindrome expected: `"ababab"`.
- Patterns: `"ab"`, `"bab"`, `"xyz"`.

### Test Case 4: Special Characters in Patterns
- Tests pattern matching with special characters.
- Palindrome check should return single characters.
- Patterns: `"123"`, `"abc"`, `"!@#"`.

### Test Case 5: Full Match
- Tests where both transmission files are identical.
- All patterns should match.
- Expected full palindrome match.
