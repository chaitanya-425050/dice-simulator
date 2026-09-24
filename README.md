# Dice Simulator

A simple C program that simulates rolling a dice multiple times and provides statistical analysis of the results.

## About This Project

**Dice Simulator** is a beginner-friendly C program that lets you:
- Roll a dice with any number of sides (up to 50)
- Roll it as many times as you want
- Get instant statistics: total sum, average, and frequency of each face

This is a **practice project** designed to help students learn fundamental C programming concepts through a practical, interactive application.

---

## Program Flow

```
START
  ↓
Display Title
  ↓
Ask: How many sides on the die? (Max 50)
  ↓
Ask: How many times to roll?
  ↓
Allocate memory for rolls
  ↓
Roll the die N times (generate random numbers)
  ↓
Calculate: Sum of all rolls
  ↓
Calculate: Average of all rolls
  ↓
Calculate: Frequency of each face
  ↓
Display all results
  ↓
Ask: Continue (C) or Quit (Q)?
  ├─→ If Q: EXIT
  └─→ If C: Go back to step 3
END
```

---

## Function Explanations

### 1. `get_positive_int(const char *prompt)`
**Purpose:** Get a positive integer from the user with validation

**How it works:**
- Displays a prompt message
- Reads user input
- Checks if input is a valid positive number
- If invalid, clears the input buffer and asks again
- Returns the valid number

**Parameters:**
- `prompt` - The message to display to the user

**Returns:** A positive integer (greater than 0)

**Example:** Used to get number of sides and number of rolls

---

### 2. `rollDie(int sides)`
**Purpose:** Generate one random dice roll

**How it works:**
- Uses `rand()` to generate a random number between 0 and `sides-1`
- Adds 1 to shift the range to 1 and `sides`
- Returns the result

**Parameters:**
- `sides` - Number of faces on the die

**Returns:** Random number between 1 and `sides`

**Example:** `rollDie(6)` returns a number between 1 and 6

---

### 3. `find_sum(const int *buffer, int no_rolls)`
**Purpose:** Calculate the total sum of all dice rolls

**How it works:**
- Loops through all rolls stored in the array
- Adds each roll to a running total
- Returns the final sum

**Parameters:**
- `buffer` - Array containing all roll results
- `no_rolls` - Total number of rolls

**Returns:** Sum of all rolls

**Example:** If rolls are [3, 5, 2, 6], returns 16

---

### 4. `find_average(int no_rolls, int sum)`
**Purpose:** Calculate the average value of all rolls

**How it works:**
- Divides the total sum by the number of rolls
- Converts to decimal (double) for accuracy
- Returns the average

**Parameters:**
- `no_rolls` - Total number of rolls
- `sum` - Sum of all rolls

**Returns:** Average as a decimal number

**Example:** If sum is 16 and rolls is 4, returns 4.00

---

### 5. `find_frequencies(const int *buffer, int no_rolls, int no_faces, int freq[])`
**Purpose:** Count how many times each face appears

**How it works:**
- Creates a frequency array (initially all zeros)
- For each roll, checks which face it is
- Increases the count for that face
- Stores results in the `freq` array

**Parameters:**
- `buffer` - Array containing all roll results
- `no_rolls` - Total number of rolls
- `no_faces` - Number of faces on the die
- `freq[]` - Array to store frequency counts

**Returns:** Nothing (modifies `freq[]` directly)

**Example:** If you roll [1, 2, 1, 3], frequency of face 1 is 2

---

### 6. `choice()`
**Purpose:** Ask the user if they want to continue or quit

**How it works:**
- Displays a prompt asking for C (continue) or Q (quit)
- Clears the input buffer
- Returns 1 if user enters C, returns 0 if user enters Q
- Handles invalid input by asking again

**Parameters:** None

**Returns:**
- `1` - User wants to continue
- `0` - User wants to quit

---

### 7. `main()`
**Purpose:** Main program that controls the entire flow

**How it works:**
1. Seeds the random number generator using current time
2. Enters an infinite loop that repeats until user quits
3. Gets number of sides and number of rolls from user
4. Allocates memory for storing roll results
5. Rolls the dice and stores each result
6. Calculates sum, average, and frequencies
7. Displays all results
8. Frees allocated memory
9. Asks user to continue or quit
10. If quit, exits the program

**Key features:**
- Uses dynamic memory allocation (`malloc`)
- Properly frees memory before exiting (`free`)
- Checks if memory allocation was successful

---

## How to Compile

### On Windows (with MinGW)

Open Command Prompt and run:
```bash
gcc -o dice_simulator dice_roll.c
```

**Explanation:**
- `gcc` - The C compiler
- `-o dice_simulator` - Creates an output file named `dice_simulator.exe`
- `dice_roll.c` - Your source code file

### On macOS (with GCC)

Open Terminal and run:
```bash
gcc -o dice_simulator dice_roll.c
```

The command is the same. After compilation, you'll get a file named `dice_simulator`.

---

## How to Run

### On Windows
```bash
dice_simulator.exe
```

Or simply double-click the `dice_simulator.exe` file.

### On macOS
```bash
./dice_simulator
```

---

## How to Use

Once the program starts:

1. **Enter number of faces (sides):** Type a number between 1 and 50. Example: `6` for a standard die.

2. **Enter number of rolls:** Type how many times you want to roll the die. Example: `100`

3. **View results:** The program will show:
   - Total sum of all rolls
   - Average value per roll
   - Frequency of each face (how many times each number appeared)

4. **Continue or Quit:** 
   - Press `C` to run another simulation
   - Press `Q` to exit the program

**Important:** Always enter valid numbers. The program will ask you to re-enter if your input is invalid.

---

## Example Run

### Input and Output:

```
 ==== DICE ROLL ====
Enter the number of faces(sides) on the die (e.g., 6):6
Enter number of rolls (positive number) : 20

=========== RESULTS ===========

Sum: 68
Average: 3.40
Frequencies:
1         : 2
2         : 4
3         : 3
4         : 4
5         : 4
6         : 3

Enter Q/q to Quit and C/c to continue : c
 ==== DICE ROLL ====
Enter the number of faces(sides) on the die (e.g., 6):10
Enter number of rolls (positive number) : 15

=========== RESULTS ===========

Sum: 79
Average: 5.27
Frequencies:
1         : 2
2         : 1
3         : 3
4         : 0
5         : 2
6         : 2
7         : 1
8         : 1
9         : 1
10        : 2

Enter Q/q to Quit and C/c to continue : q
Q/q is selected Exiting the program....
```

---

## Key C Concepts Used

This project demonstrates these important C concepts:

### 1. **Dynamic Memory Allocation**
```c
int *roll_result = (int*)malloc(no_rolls * sizeof(int));
free(roll_result);
```
- `malloc()` - Allocates memory at runtime
- `free()` - Releases allocated memory
- **Why it matters:** You don't know the number of rolls ahead of time, so you allocate memory dynamically

### 2. **Pointers**
```c
int *roll_result = ...;  // Pointer to an integer array
```
- Pointers hold memory addresses
- Used to access dynamically allocated arrays

### 3. **Arrays**
```c
int freq[no_faces];  // Array to store frequencies
```
- Store multiple values in one variable
- Access elements using index: `freq[0]`, `freq[1]`, etc.

### 4. **Input Validation**
```c
if(scanf("%d", &in_buffer) == 1 && in_buffer > 0)
```
- Check if user input is valid
- Clear the input buffer if invalid
- Ask the user to try again

### 5. **Random Number Generation**
```c
srand(time(NULL));      // Seed the random generator
rand() % sides + 1;     // Generate random number
```
- `srand()` - Seeds the random number generator with current time
- `rand()` - Generates pseudo-random numbers
- Formula `rand() % sides + 1` gives numbers from 1 to `sides`

### 6. **Functions**
- Breaking code into smaller, reusable pieces
- Each function has one clear purpose
- Makes code easier to understand and test

### 7. **Loops and Conditionals**
```c
for(int i = 0; i < no_rolls; i++)  // For loop - repeat N times
while(1)                            // While loop - repeat until break
if(condition)                       // If statement - make decisions
```
- Control program flow
- Repeat actions or make decisions

### 8. **String Handling**
```c
const char *prompt    // Constant pointer to string
printf("%s", prompt)  // Print string
```
- Prompts and messages are stored as strings
- `const` means the string won't be changed

---

## License

This project is licensed under the MIT License - see LICENSE file for details.

---

## Learning Tips for Students

- **Understand the flow first** before diving into the code
- **Trace through the program** with a small example (like 3 rolls of a 6-sided die)
- **Modify the code** - try changing limits, adding features, or fixing bugs
- **Practice memory management** - always `free()` what you `malloc()`
- **Test edge cases** - what happens with 1 roll? 1 side? 50 sides?

Happy learning! 🎲
