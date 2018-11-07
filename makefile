comp:
	mkdir -p bin
	javac -d bin -sourcepath src src/*.java	
total:
	mkdir -p bin
	javac -d bin -sourcepath src src/*.java	
	javac -d bin src/jlogic/*.java
	javac -d bin src/jlist/*.java
	javac -d bin src/jclock/*.java
clean:
	rm -f src/jlogic/*.class src/jlogic/*~ src/jlogic/*#
	rm -f src/jlist/*.class src/jlist/*~ src/jlist/*#
	rm -f src/jclock/*.class src/jclock/*~ src/jclock/*#
	rm -f samples/*~ samples/*#
	rm -f src/*.class src/*~ src/*#
	rm -f *.class *~ *#
	rm -f smbionet
	rm -rf bin
install:
	make clean
	make total
	echo -e 'java -cp '${PWD}'/bin Main '"\044*""\necho" > smbionet
	chmod +x smbionet 
