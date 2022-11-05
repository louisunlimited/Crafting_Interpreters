JFLAG = -g
JC = javac
JVM = java

all: jlox

#compile the java files to bin
jlox: jlox/lox/*.java
	$(JC) $(JFLAG) jlox/lox/*.java -d jlox/bin

#run the java files
run: jlox
	$(JVM) -cp jlox/bin jlox.lox.Lox

#clean the directory
clean:
	rm -rf jlox/bin/*
