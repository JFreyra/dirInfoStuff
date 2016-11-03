all: dirInfo.c
	gcc dirInfo.c -o dirInfo

clean: all
	rm dirInfo
	*~

run: all
	./dirInfo
