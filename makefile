#makefile
CPP=g++
FLAGS=-std=c++11

converter.o: converter.h converter.cpp 
	$(CPP) $(FLAGS) -c converter.cpp
bdecimal.o: bdecimal.h bdecimal.cpp 
	$(CPP) $(FLAGS) -c bdecimal.cpp 
utils.o: utils.h utils.cpp 
	$(CPP) $(FLAGS) -c utils.cpp 
i18n.o: i18n.h i18n.cpp 
	$(CPP) $(FLAGS) -c i18n.cpp 
main.o: main.cpp 
	$(CPP) $(FLAGS) -c main.cpp 
main: main.o i18n.o utils.o bdecimal.o converter.o 
	$(CPP) $(FLAGS) main.o i18n.o utils.o bdecimal.o converter.o

run-vn: main 
	./a.out -l=vn 
run-en: main 
	./a.out -l=en
run-h: main 
	./a.out -h


