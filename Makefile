OBJS = ast.o interpreter.o compiler.o runtime.o

all: pja

pja: $(OBJS)
  gcc -o pja $(OBJS)

ast.o: ast.c ast.h
  gcc -Wall -g -c ast.c

interpreter.o: interpreter.c interpreter.h
  gcc -Wall -g -c interpreter.c

compiler.o: compiler.c compiler.h
  gcc -Wall -g -c compiler.c

runtime.o: runtime.c runtime.h
  gcc -Wall -g -c runtime.c

clean:
  rm -f *.o pja
