a.out: main.o Knn.o DistanceClass.o
		g++ -std=c++11 main.o Knn.o  DistanceClass.o -o a.out

main.o: main.cpp
		g++ -std=c++11 -c main.cpp

Knn.o: Knn.cpp Knn.h
		g++ -std=c++11 -c Knn.cpp

DistanceClass.o: DistanceClass.cpp DistanceClass.h
		g++ -std=c++11 -c DistanceClass.cpp

clean: rm *.o a.out