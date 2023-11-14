# CS303-Assignment-3

## Usage Instructions

This program consists of two main parts: the Expression Manager and the Queue implementation.

### Expression Manager
- On running the program, you will first interact with the Expression Manager.
- You will be prompted to enter an infix expression. This expression should include numbers, variables, or operators like `+`, `-`, `*`, `/`, `%`. Parentheses can be used to indicate the order of operations.
- After entering the expression, the program will check if the parentheses in the expression are balanced and then convert the expression from infix to postfix notation if it's balanced.

### Queue Implementation
- After the Expression Manager, the program will move to the Queue operations.
- A menu will be displayed with the following options:
  1. Enqueue (Add an element to the rear of the queue)
  2. Dequeue (Remove and display an element from the front of the queue)
  3. Front Element (Display the element at the front of the queue without removing it)
  4. Queue Size (Display the current number of elements in the queue)
  5. Exit (Exit the queue operations and end the program)
- You can perform operations on the queue by choosing the appropriate number. After each operation, the program will display the result and return to the menu until you choose to exit.

## Examples of Program Output

### Expression Manager
1. **Balanced Expression Conversion**
   - **Input:** `"(1 + 2) * 3"`
   - **Output:** 
     - The program should indicate that the expression is balanced.
     - It should then display the postfix conversion of the expression, which would be `"1 2 + 3 *"`.
     - Screenshot: https://imgur.com/a/D0uSE8W

2. **Unbalanced Expression Check**
   - **Input:** `"((1 + 2) * 3"`
   - **Output:** 
     - The program should indicate that the expression is not balanced.
     - Screenshot: https://imgur.com/a/IVZsYb4

### Queue Operations
1. **Enqueue Operation**
   - **Action:** Choose to enqueue, and enter a number, say `5`.
   - **Output:** 
     - If you enqueue `5`, the program doesn't typically display a confirmation for enqueue, but you can use the 'Queue Size' or 'Front Element' options to show the element is added.
     - Screenshot: https://imgur.com/a/6vGg3Mt

2. **Dequeue Operation**
   - **Action:** After enqueueing a few elements, choose to dequeue.
   - **Output:** 
     - The program should display the element being dequeued and removed from the queue.
     - Screenshot: https://imgur.com/a/D0Abx8f

3. **Front Element Display**
   - **Action:** Choose to display the front element of the queue.
   - **Output:** 
     - The program should show the element at the front of the queue without removing it.

4. **Queue Size Display**
   - **Action:** Choose to display the size of the queue.
   - **Output:** 
     - The program should display the number of elements currently in the queue.
