JFLAGS = -classpath "jsoup-1.11.3.jar:."
JC = javac
JV = java
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = crawler.java

default: classes run

classes: $(CLASSES:.java=.class)

run:
	$(JV) $(JFLAGS) Main

clean:
	$(RM) *.class

