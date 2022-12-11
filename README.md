# KNNrep
In this assignment we will implement the algorithm KNN - K nearest neighbors in c++.
Given a vector input from the user - we will check first if its valid - 
all numbers can be double type and no characters - if characters written - we will print an error message to the screen.
Second, we will get 3 arguments in the running line command - K, file, distance.
k - will be the k nearest neighbors from the data given in the 2nd parameter. 
file - the name of the file where the data is, finished with .csv
distance - will be the name of the specific distance we want to calculate (MAN,AUC,MIN,CHB,CAN).

the program will run as follow:
a.out k file distance

for example:
a.out 3 iris_classified.csv MAN
Will uplaod iris_classified vectors and calulate Manhattan ditance between each one of the vectors and the input vector,
get the 3 closes neighbors - by sorting the distance vector and the name of the specific topic, and get the most significant topic in the k neighbors.
We will print the correct classified topic, and get an infinte input from user all over again.
