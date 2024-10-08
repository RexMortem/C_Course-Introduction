# Session 1 - An Introduction To C 

The course starts gently by introducing basic programming concepts in C such as variables, types, functions, and loops. If you’re an experienced programmer then feel free to skim through these sections to get to the more C-specific parts! 

I would personally recommend doing all the exercises regardless of your level, to ensure that you know the material. At times, my writing can be verbose so please do skim through the content, scan for bold/italicised text, and carefully read content when you cannot do the corresponding exercises. 

## Contents 

- <a href="#WhatIsC" style="color: black;"> What is C </a>
- <a href="#HelloWorld" style="color: black;"> Hello World! </a>
- <a href="#Compiling" style="color: black;"> Compiling & Running C Code </a>
    - <a href="#HelloWorldExercises" style="color: black;"> Compiling and Hello World Exercises </a>
- <a href="#Variables" style="color: black;"> Variable Declaration & Initialisation </a> 
- <a href="#Integers" style="color: black;"> Int </a>
- <a href="#FormatSpecifiers" style="color: black;"> Format Specifiers (**%d**, **%s**, **%c**) </a>
    - <a href="#CharExercises" style="color: black;"> Int, Char, and Format Specifier Exercises </a>
- <a href="#Comments" style="color: black;"> Comments (and increment operator) </a>
- <a href="#IntegerTypes" style="color: black;"> More Integer Types (char, short, int, long, long long) </a>
    - <a href="#IntegerTypeExercise" style="color: black;"> Integer Type Exercise (size of types) </a> 
- <a href="#OverflowUnderflow" style="color: black;"> Underflow/Overflow </a>
- <a href="#Unsigned" style="color: black;"> Unsigned Integers  </a> 
- <a href="#StdInt" style="color: black;"> StdInt Library </a> 
- floating-point types 
- Functions 
- Basic Loops
- Arrays (& undefined behaviour)

## <a name="WhatIsC"> What is C </a>

C is a general purpose programming language that originated as the language for UNIX ….

## <a name="HelloWorld"> Hello, World! </a>

Let's start with the first program almost *everyone* writes. 

```c
#include <stdio.h>

main(){
    printf("hello world");
}
```

There are **3** main things to note already: 

1) The **stdio** library is the **st**an**d**ard **i**nput/**o**utput library which we’ll use to print text to the console. Think of **libraries** as a collection of tools that other people have coded so that we don't have to; typically a library is dedicated to *one thing* and I'm sure you can guess what **stdio** is dedicated to. 

We import it using the **include** *preprocessor directive*; don’t worry, we’ll learn more about what preprocessor directives are later! Just know that preprocessor directives start with a **#** (fun fact: also called an octothorpe), and that `#include <stdio.h>` tells C to copy all the code from stdio so that we get access to **printf** and everything else in that library.

2) All C programs start at the **main** function; not having a main will lead to an error! 

```
undefined reference to 'WinMain'
```

*The error I receive on my machine*

It is similar to Java’s main, which you may have already learned about in CS118, in that it is the first block of code run. 

If you don’t know what functions are yet, then just think of them as blocks of code. We will discuss them soon!

3) Statements in C, like using the **printf** function, end with a *semicolon*. This helps C read the program as semicolons tell it where one statement ends and another begins.  

Okay so we've seen our first C program but how do we actually run it? 

## <a name="Compiling"> Running C Code </a> 

If you're working on DCS machines, then you should have the GNU C compiler installed. 

If not then you should check by running the following command:
```sh
gcc --version
```
*gcc stands for GNU Compiler Collection* 

If you do not have it installed, then follow the installation instructions from [here](https://gcc.gnu.org/install/).

### What is a compiler? 

A compiler turns **high-level** code (such as **C**) into **low-level** machine code that the computer can run. 

The idea is that **C** code is relatively portable so you can write some **C** code, give that code to multiple different machines and they'll be able to run it using their respective compilers. In practice, since **C** often talks "directly" to Operating Systems, you will often have to write slightly different **C** code for different machines for complex programs.  

![A diagram describing compilation](images/CompilationDiagram.png)
- Compiling C code turns it into an exe 
- You can run the exe with `./TheExe`

### <a name="CompilingAndExecuting"> Compiling and Executing C Code </a>

Use `gcc` to compile C code. As an example:

1) create a new file directly under the main folder (named C_Course-Introduction) 
2) Call it `exampleToCompile.c`
3) Run the command `gcc exampleToCompile.c -o exampleProgram`

This should give you an exe named `exampleProgram.exe` that you can run using:
```
./exampleProgram
```

Note that the `-o` flag lets you name the exe and, by extension, place it in a specific folder. If you wrote `exes/exampleProgram` instead of `exampleProgram`, then it would place the newly created program in the `exes` folder (assuming this folder exists). This will make it easier to keep track of your files! 

## <a name="HelloWorldExercises"> Exercises for Hello World & Compiling </a>

1) Compile one of the c files inside of `cFiles` (**hint:** use the <a href="#CompilingAndExecuting" style="color: black;"> <u>last paragraph of Compiling and Executing</u> </a> to help you)

2) Try changing up the text outputted to the console. Note that **C** does not automatically insert *newlines* after each usage of `printf`! 

```c
#include <stdio.h>

main(){
    printf("hello ");
    printf("world");
}
```

So the above code outputs:

```
hello world
```
*Key thing to note is that it's all on one line*

If you want a newline, use **\n** which stands for the *newline* character. 

```c
#include <stdio.h>

main(){
    printf("hello\n");
    printf("world");
}
```

Have fun writing your own output! 

## <a name="Variables"> Variables </a>  

So we can interact with the console using `printf` but we need a way of handling data; at the very least, we need a way of storing input when we start reading input from the user. 

**Enter variables!** 

Variables have:
- a **name**
- a **type** ( which tell you what kind of data is stored)
- a **value**, regardless of if you provide one! 

### Declaring with value

![Declaring a variable with a value](images/DeclaringWithValue.png)

### Declaring without value 

![Declaring a variable without specified value](images/DeclaringWithoutValue.png) 

This is the difference between **declaration** and **initialisation**. 

Both of these **declare** the variable (they tell **C** that memory must be reserved for the variable), but only the first **initialises** the variable with a value. 

We will see soon that the variable that isn’t initialised *does* have a value, but it might not be what you expect! 

## <a name="Integers"> Integer variables </a> 

First, we’ll explore the integer (positive & negative whole number) types! 

```c
#include <stdio.h>

main(){
    int a = 5;
    int b, c;

    b = 1; 
    c = -4;

    printf("%d\n", a + b + c);
}
```
*A program with a variety of int initialisations*

```
2
```

1) Note the different ways we’ve initialised the variables a,b,c- all valid! 

2) Note the use of `+` as an operation for integers (and numbers in general). You also get `-` for subtraction, `*` for multiplication, `/` for division. 

3) Notice that we’re using `printf` differently. The previous use of `printf` was just passing it a piece of text; this current use of `printf` passes it a formatting piece of text (`%d\n`), and the values to slot into the format. 

As it’s useful to output values in meaningful ways for debugging complex programs and even outputs for simple command-line programs, we’ll take a closer look at using `printf`. 

## <a name="FormatSpecifiers"> Format Specifiers (using printf) </a>

The formatting piece of text includes **format specifiers** which begin with **%** and are replaced by the other values you pass `printf`; different values (or different ways of displaying values) require different format specifiers. 

For example, **%d** is used to stand in for a regular old base 10 integer (**d** for **d**ecimal). The pieces of text that we’ve been passing are called **strings** and so use **%s**. 

```c
#include <stdio.h>

int main(){
    int hours = 11;
    int minutes = 23;
    int seconds = 59;

    printf("%s - %d : %d : %d \n", "The Time",  hours, minutes, seconds);
}
```
*Example for time using both **%s** and **%d***

```
The Time - 11 : 23 : 59
```

What did I mean by **“different displays of values”**? To explain, I will introduce the **char** which is a *smaller* **int** data type, with a *tiny* range of possible values (`-128` to `+127`), that is typically used to represent *characters* using **ASCII** rather than to represent integers. 

For those who don’t know, ASCII is a standard encoding of *integers* to commonly used *characters*. To show a few:

<table>
    <tr>
        <th> Integer </th>
        <td> 65 </td>
        <td> 66 </td>
        <td> 67 </td>
        <td> 97 </td>
        <td> 98 </td>
        <td> 99 </td>
        <td> 33 </td>
        <td> 35 </td>
    </tr>
    <tr>
        <th> Character </th>
        <td> A </td>
        <td> B </td>
        <td> C </td>
        <td> a </td>
        <td> b </td>
        <td> c </td>
        <td> ! </td>
        <td> # </td>
    </tr>
</table>

Of course the **digits** must be encoded too; they’re encoded by the numbers **48**-**57**.

<table>
    <tr>
        <th> Integer </th>
        <td> 48 </td>
        <td> 49 </td>
        <td> 50 </td>
        <td> 51 </td>
        <td> 52 </td>
        <td> 53 </td>
        <td> 54 </td>
        <td> 55 </td>
        <td> 56 </td>
        <td> 57 </td>
    </tr>
    <tr>
        <th> Character </th>
        <td> 0 </td>
        <td> 1 </td>
        <td> 2 </td>
        <td> 3 </td>
        <td> 4 </td>
        <td> 5 </td>
        <td> 6 </td>
        <td> 7 </td>
        <td> 8 </td>
        <td> 9 </td>
    </tr>
</table>

So a char can be displayed as a *number* using **%d**, but also as a *character* using **%c**.

```c
char a = 101;
printf("%c : %d", a, a);
```
*Two different ways of displaying the same value: as the character the char represents, and the corresponding number itself*

```
e : 101
```

As a **char** can represent a fraction of the values an **int** can, an int can also be used to store and display a character since it can be converted into a char very easily. So the following code is also valid:

```c
int b = 100;
printf("%c : %d", b, b);
```
*Displaying both representations using an int instead of a char*

```
d : 100
```

If you’re concerned about not being able to display the **%** symbol, fret not! You can do this using **%%** which displays a single **%**. 

### <a name="CharExercises"> Exercises for using ints and chars </a> 

1) There are two groups in a room: `6` UWCS Exec and `20` C Programmers. `4` people in this room are both UWCS Exec and C Programmers. Finish the following C program in order to complete the total number of people in the room: 

```c
#include <stdio.h>

main(){
    int exec = 6; 
    int cProgrammers = 20;
    int both = 4;

    int total; 

    printf("The total number of people: %d", total);
}
```

2) Try to spell your name out using chars! If you’re feeling ambitious, try doing this using a mixture of capital and lower case letters. Refer to [this if needed](https://www.asciitable.com/).

To make this easier, you can set the value of a char using the character that it represents. For example:

```c
char capitalE = 'E';
```
*Note that characters are wrapped in single quotes*

3) Timmy wants to display how charged an attack is in his game! Can you help him output the text: 
```
Laser is charging, at 57% now! 
``` 

His current code is: 
```c
#include <stdio.h>

main(){
    int charge = 57;

    printf("FILL ME IN");
}
```

## <a name="Comments"> Break from ints: Comments </a> 

We’ll be using **comments** to help *describe* and *explain* bits of code; they don’t do anything to the execution of the program, but you should use comments in your own **C** programs to help the reader quickly understand what is going on (often you in the future)! 

<img src="images/CatCommentMeme.png" alt="Cat meme to illustrate that you should use comments for your future self" width="270" height="265"/>

Use **//** for single-line comments. Let’s see how they’re used to showcase the *increment* operator (**++**), which increases a number by 1. 

```c
main(){
    int i = 5; 
    i++;

    printf("%d\n", i); // output: 6 

    i++;
    i++;

    printf("%d\n", i); // output: 8 
}
```
*Use of single-line comments*

If you need to write something longer, then consider using **multi-line comments**. 

To start a multi-line comment, use **/\***

To end a multi-line comment, use **\*/**

```c
#include <stdio.h>

/*
    The main function is the entry-point to the program.
    This program shows the increment operator on integers, and its effect. 
    The main purpose of this program is to demonstrate the use of comments. 

    (This is a multiline comment)
*/
main(){
    int i = 5; 
    i++;

    printf("%d\n", i); // output: 6 

    i++;
    i++;

    printf("%d\n", i); // output: 8 
}
```
*The full program with a multi-line comment describing main*

Try to practice using **single-line** and **multi-line** comments in future exercises to get used to them!

## <a name="IntegerTypes"> Which int to use? </a> 

There are several **ints** (char, short, int, long, long long) to choose from, and generally you should choose them based on *what they’re used for* e.g. *chars* for representing *characters*, *shorts* for *small integers*, *longs* for *large integers*. 

For most use cases, the size taken up by an integer is negligible so most people tend to default to an int in a place where a short would be perfectly fine. This only really matters in situations where space is very valuable such as small embedded systems or storing **a lot** of integers. In fact, it can be beneficial to use an int as your future uses may require a larger range and arithmetic can actually be faster (although usually negligibly) if your machine’s native size is 32-bit or 64-bit. 

Despite the idea of **C** being a portable language, the size (and range) of integer types are machine-dependent; therefore, the **C** standard only specifies the *minimum* number of bytes for each type. 

For instance, the minimum number of bytes for an **int** is `2` however most modern machines use `4`.

| Type                              | (Minimum) number of bytes | (Minimum) range of values      | 
| --------------------------------- | ------------------------- | ------------------------------ |
| char                              | `1`                       | `-128` to `+127`               |
| short (aka short int)             | `2`                       | `-32768` to `+32767`           |
| int                               | `2`                       | `-32768` to `+32767`           |   
| long (aka long int)               | `4`                       | `-2147483648` to `+2147483647` |   
| long long (aka long long int)     | `8`                       | `-2^63` to `+2^63 - 1`         |

### <a name="IntegerTypeExercise"> Integer Type Exercise: Outputting the size of types </a>

1) We know the *minimum* number of bytes that a type must have, but how do we know what the *actual* number of bytes is for *your* machine? Well, wouldn't you like to know you nosy little scamp! 

You can use the `sizeof` function to do this. For example: 

```c
printf("Size of an int (in bytes): %d\n", sizeof(int));
```

Try to write out a C program that prints out the size of all 5 of the above types. 

## <a name="OverflowUnderflow"> Overflow/Underflow - What if the number goes above/below the range? </a>

Having ranges of values for integers begs the question: "What if you go above or below the range?"

- Going *above* the range (**overflow**) of an int type will wrap around to the *minimum* value. 
- Similarly, going *below* the range (**underflow**) of an int type will wrap around to the *maximum* value. 

```c
#include <stdio.h>

main(){
    char maxVal = 127;
    maxVal++; // integer overflow! 

    printf("%d\n", maxVal); // output: -128

    char minVal = -128; 
    minVal--; // integer underflow! 

    printf("%d\n", minVal); // output: 127
}
```
*Note that the decrement operator (`—`) subtracts `1` from a number.*

## <a name="Unsigned"> What if I want only positive numbers? </a>

The standard integers we are using so far are **signed** integers. As in, they have a **sign** (*positive* or *negative*). If you want to use only the positive range, then you can use unsigned integers by adding *“unsigned”* in the type! 

Since they don't represent negative integers, you roughly **double** the number of positive integers you can use.

## <a name="StdInt"> What if I want a guaranteed size? </a>

If the exact size of the int is crucial, you can use the **stdint** (`<stdint.h>`) library. 

| Type      | Number of bytes | Range of values     |
| --------- | --------------- | ------------------- |
| int8_t    | 1               | -2^7 to 2^7 - 1     |
| int16_t   | 2               | -2^15 to 2^15 - 1   |
| int32_t   | 4               | -2^31 to 2^31 - 1   |
| uint8_t   | 1               | 0 to 2^8 - 1        |
| uint16_t  | 2               | 0 to 2^16 - 1       |
| uint32_t  | 4               | 0 to 2^32 - 1       |

Most modern implementations also provide **int64_t** and **uint64_t**. 

### <a name="IntegerExercises"> Integer Exercises </a>

## <a name="IfStatements"> Conditional Logic (If Statements) </a>

Doing certain things under certain conditions is *essential*. The basics of this is the if statement:

<img src="images/IfStatementSyntax.PNG" alt="An if statement with special colouring" width="311" height="74"/>

An example of its use: 
```c
int age = 19; // my current age 

if(age >= 18){
    printf("Yay I can vote!");
}
```

We can see that the `<condition>` - in this case, whether I am older than 18 - is **True** or **False**; that is, each `<condition>` has a value of **True** or **False** (called **boolean** values). However booleans do not have their own type in **C**; this begs the question: "what actually is `<condition>`?" 

Well, **False** is actually represented by `0` and **True** is represented by anything *except* `0`. Let's see what value **C** assigns our condition with.  

```c
int age = 19; // my current age
int isOver18 = (age >= 18); // you can use brackets to ensure things inside happen first

printf("True: %d", isOver18); // 1 
```

We can already do a lot with just this, but we can make the if statement more *powerful* with **else**s:

<img src="images/IfElseStatementSyntax.PNG" alt="An if-else statement with special colouring" width="321" height="125"/>

We can make these even more *powerful* with **else if**s:

<img src="images/IfElseIfStatementSyntax.PNG" alt="An if-elseif statement with special colouring" width="397" height="218"/>

### <a name="IfStatementExercises"> If Statement Exercises </a>

## For loops

## While loops



## Using decimals: floats 

## Type Casting - maybe as an exercise?

When we saw that integers can be displayed as characters, we were actually converting integers to characters first: this is a **type cast**. 

### In Floats
### Overflow/Underflow

Functions 

Good code is often reusable and easily adaptable code. 

Arrays 

Next Session…

We’ll be covering arguably the most important and famous topic in C: pointers. 

