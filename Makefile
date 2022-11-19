JFLAG = -g
JC = javac
JVM = java

all: jlox

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
