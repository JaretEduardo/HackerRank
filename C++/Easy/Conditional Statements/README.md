# Conditional Statements

if and else are two of the most frequently used conditionals in C/C++, and they enable you to execute zero or one conditional statement among many such dependent conditional statements. We use them in the following ways:

1. if: This executes the body of bracketed code starting with statements if condition evaluates to true.

```md
if (condition) {
    statement1;
    ...
}
```

2. if - else: This executes the body of bracketed code starting with statements if condition evaluates to true, or it executes the body of code starting with statements2 if condition evaluates to false. Note that only one of the bracketed code sections will ever be executed.

```md
if (condition) {
    statement1;
    ...
}
else {
    statement2;
    ...
}
```

3. if - else if - else: In this structure, dependent statements are chained together and the condition for each statement is only checked if all prior conditions in the chain evaluated to false. Once a condition evaluates to true, the bracketed code associated with that statement is executed and the program then skips to the end of the chain of statements and continues executing. If each condition in the chain evaluates to false, then the body of bracketed code in the else block at the end is executed.

```md
if(first condition) {
    ...
}
else if(second condition) {
    ...
}
.
.
.
else if((n-1)'th condition) {
    ....
}
else {
    ...
}
```

Given a positive integer
    if 1 < n <9, print the lowercase English word corresponding to the number (e.g., one for 1, two for 2, etc.).
    if n > 9, print Greater than 9

#### Inout Format

A single integer, n.

#### Constrains

if 1 < n < 9,  then print the lowercase English word corresponding to the number (e.g., one for 1, two for 2, etc.); otherwise, print Greater than 9.

#### Sample Input 0

```md
5
```

#### Sample Output 0

```md
five
```

#### Explanation 0

five is the English word for the number 5.

#### Sample Input 1

```md
8
```

#### Sample Output 1

```md
eight
```

#### Explanation 1

eight is the English word for the number 8.

#### Sample Input 2

```md
44
```

#### Sample Output 2

```md
Greater than 9
```

#### Explanation

n = 44 is greater than 9, so we print Greater than 9.