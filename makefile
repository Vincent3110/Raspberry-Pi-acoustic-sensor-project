OBJ = main.o wave.o screen.o comm.o
APPNAME = sound.a

$(APPNAME) : $(OBJ)
        gcc -o $(APPNAME) $(OBJ) -lm -lcurl

%.o : %.c
        gcc -c -o $@ $< -std=c99

clean :
        rm $(OBJ) $(APPNAME)

archive :
        tar cf sound.tar *.c *.h makefile




