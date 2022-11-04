JFLAG = -g
JC = javac
JVM = java

all: jlox

#compile the java files
jlox: jlox/lox/*.java
	$(JC) $(JFLAG) jlox/lox/*.java

#run the java files
run: jlox
	$(JVM) jlox/lox/Lox

#clean the directory
clean:
	rm jlox/lox/*.class
