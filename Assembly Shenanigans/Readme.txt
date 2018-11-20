Here are some nasm x86 routines used by cpp programs in an attempt at greater efficientcy.  This folder may be rather sparse
as programming in x86 is a real hassle, and only really viable for simple tasks that would take a scripting language too long
to complete.  Below is included a list of relevant files and their functionalities.

threeplusinput.cpp: a file that takes the number of steps in the collatz function as input and outputs the smallest number with
greater than or equal to that many steps to one.

threeplusone.s: x86 code that calculates the number of steps to one for any given number in the collatz formula recursively.