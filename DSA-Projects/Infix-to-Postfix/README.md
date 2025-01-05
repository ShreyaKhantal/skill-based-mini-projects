# Expression Evaluator with Infix to Postfix Conversion

This program evaluates arithmetic expressions by converting an infix expression into postfix notation and then calculating the result. It supports operators like `+`, `-`, `*`, `/`, and `^`, and handles both numbers and variables (letters). The program also checks whether the input expression is balanced in terms of parentheses and other brackets.

## Features
1. **Infix to Postfix Conversion**: Converts infix expressions (like `(3 + 2) * 5`) to postfix (Reverse Polish Notation) expressions (like `3 2 + 5 *`).
2. **Expression Evaluation**: Evaluates postfix expressions to compute the result.
3. **Balanced Expression Check**: Ensures that the expression has balanced parentheses `()`, square brackets `[]`, and curly braces `{}`.
4. **Supports Operations**: Supports `+`, `-`, `*`, `/`, and exponentiation `^`.
5. **Handles Variables**: Supports variables (letters) and numeric operands.

## Data Structures Used
- **Stack**: A stack data structure is used for:
  - Storing operators and operands during the infix to postfix conversion.
  - Storing intermediate results during postfix evaluation.

## How to Use

1. **Input Expression**: You can input an arithmetic expression that may contain:
   - Numbers (e.g., `2`, `3.5`).
   - Operators (`+`, `-`, `*`, `/`, `^`).
   - Parentheses `()`, square brackets `[]`, and curly braces `{}`.
   
2. **Balanced Expression Check**: The program checks whether the input expression has balanced brackets and prints an error message if the brackets are mismatched.

3. **Infix to Postfix Conversion**: The program will convert the expression to postfix notation.

4. **Expression Evaluation**: If the expression is numeric, it will evaluate the postfix expression and print the result. If the expression contains variables, it will only show the postfix notation.

## How It Works

1. **Balanced Parentheses**: The `isbalanced()` function checks if the parentheses are balanced by using a stack. It matches opening brackets with their corresponding closing brackets.

2. **Infix to Postfix**:
   - The program traverses the infix expression.
   - If an operand (number/variable) is found, it's added to the result.
   - If an operator is found, the program compares its precedence with operators on the stack and pops operators with higher or equal precedence to the result.
   - When a closing parenthesis is encountered, operators are popped until an opening parenthesis is found.

3. **Postfix Evaluation**: The `evaluatepostfix()` function evaluates the postfix expression by using a stack. For every operand, it pushes the value onto the stack, and for every operator, it pops operands, performs the operation, and pushes the result back onto the stack.

## Functions

- **`push(int c)`**: Pushes a character onto the stack.
- **`pop()`**: Pops a character from the stack.
- **`isempty()`**: Checks if the stack is empty.
- **`top()`**: Returns the top character of the stack without removing it.
- **`clearStack()`**: Clears the stack.
- **`isbalanced(char a[])`**: Checks if the expression has balanced parentheses.
- **`priority(char x)`**: Returns the precedence of operators.
- **`infixtopostfix(char input[])`**: Converts an infix expression to postfix notation.
- **`evaluatepostfix(string input)`**: Evaluates a postfix expression.

## Features
- Infix to Postfix conversion
- Postfix expression evaluation
- Parentheses balance checking
- Supports operators: `+`, `-`, `*`, `/`, `^`

Here’s a concise `README.md` for your project:

```md
# Expression Evaluator

A C++ program to evaluate mathematical expressions in infix and postfix notations, with support for balanced parentheses.

## Features
- Infix to Postfix conversion
- Postfix expression evaluation
- Parentheses balance checking
- Supports operators: `+`, `-`, `*`, `/`, `^`

## Compilation and Execution

### 1. Save the Code
Save the code in a file named `expression_evaluator.cpp`.

### 2. Compile the Program
For Linux/macOS:
```bash
g++ expression_evaluator.cpp -o expression_evaluator
```
For Windows (using MinGW or similar):
```bash
g++ expression_evaluator.cpp -o expression_evaluator.exe
```

### 3. Run the Program
For Linux/macOS:
```bash
./expression_evaluator
```
For Windows:
```bash
expression_evaluator.exe
```

### 4. Input and Test
The program will prompt for an expression:
```
Enter The Expression: (3 + 2) * 5
```

### 5. Output
```
Postfix is: 3 2 + 5 *
Result: 25
```

## License
MIT License
```