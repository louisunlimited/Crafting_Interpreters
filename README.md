# Crafting_Interpreters

This is a follow-along repo for the book `"Crafting Interpreters"` by `Robert Nystrom`

I will be implementing `jlox` and `clox`, trying to understand the structure of the languange and various other aspects.

My goal eventually is to have a better understanding of Open Source Language codebases and being able to contribute. (e.g. Swift, CPython, etc.) Also, I'm curious to know how programming languages actually work under the hood, and try to implement my own language in c++.

## jlox

- implemented using AST and heavily relies on Java runtime features, so it's SLOW! We've taken advantage of stuff like `instanceof` and wished they would work somehow. Memory management was also never an issue since JVM's garbage collector took care of all of that.

- AST's are not memory-efficient, a simple expression like `1 + 2` evaluates to 5-7 objects with pointers all over the place. This will be bad for caches since we are bascically throwing our data across the heap: we cannot take advantage of `spatial locality`!!!

Flow: Parser -> Syntax Trees -> Interpreter

## clox

- Bytecode!!! -> resembles machine code, but it's much simpler and higher-leveled.

Flow: Compiler -> Bytecode -> VM
