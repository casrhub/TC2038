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



# Test Case Explanation

### transmission1.txt: `abxyzracecar123!@#`
- This string includes:
  - A mix of random characters (`abxyz`).
  - A palindrome (`racecar`).
  - A number sequence (`123`).
  - Special characters (`!@#`).
- It covers pattern matching, palindrome detection, and testing special characters and numbers.

### transmission2.txt: `123racecarzyxab!@#`
- This string includes:
  - The same palindrome (`racecar`) but in a different position.
  - Similar sequences (`123` and `!@#`), which test pattern matching.
  - Reversed parts of `transmission1.txt` (`zyxab`), which provides complexity for common substring detection.

### mcode1.txt: `racecar`
- A palindrome to test both **pattern matching** and **palindrome detection**.

### mcode2.txt: `123`
- A numeric pattern to test how numbers are detected across both transmissions.

### mcode3.txt: `!@#`
- A special character sequence to test how well the algorithm handles non-alphabetic characters in pattern matching.


