JFLAG = -g
JC = javac
JVM = java

C = gcc
CFLAG = -g -std=c99

# all: jlox clox

# comile c files
clox: clox/*.c
	$(C) $(CFLAG) clox/*.c -o clox/bin/clox

crun: clox
	./clox

#compile the java files to bin
jlox: jlox/lox/*.java
	$(JC) $(JFLAG) jlox/lox/*.java -d jlox/bin

#run the java files
jrun: jlox
	$(JVM) -cp jlox/bin jlox.lox.Lox

jtest: jlox
	$(JVM) -cp jlox/bin jlox.lox.Lox lox_test.lox

#clean the directory
jclean:
	rm -rf jlox/bin/*
