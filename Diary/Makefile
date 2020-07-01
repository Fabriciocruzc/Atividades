GCC = g++
GCC_FLAGS = -I include -std=c++11 
PROGRAMA = diary

all: $(PROGRAMA)

$(PROGRAMA): App.o Date.o Diary.o Time.o Message.o Util.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) App.o Date.o Diary.o Time.o Message.o Util.o main.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Diary.o: src/Diary.cpp
	$(GCC) $(GCC_FLAGS) -c src/Diary.cpp

Date.o: src/Date.cpp
	$(GCC) $(GCC_FLAGS) -c src/Date.cpp

Time.o: src/Time.cpp
	$(GCC) $(GCC_FLAGS) -c src/Time.cpp

Message.o: src/Date.cpp
	$(GCC) $(GCC_FLAGS) -c src/Message.cpp

Util.o: src/Util.cpp
	$(GCC) $(GCC_FLAGS) -c src/Util.cpp

App.o: src/App.cpp
	$(GCC) $(GCC_FLAGS) -c src/App.cpp
