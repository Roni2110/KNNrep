# KNNrep
In this assignment we will implement the algorithm KNN - K nearest neighbors in c++.
First of all, we will get 3 arguments in the running line command - K, file, distance.
k - will be the k nearest neighbors from the data given in the 2nd parameter. 
file - the name of the file where the data is, finished with .csv
distance - will be the name of the specific distance we want to calculate (MAN,AUC,MIN,CHB,CAN).
The distances methods were implemented in the previous exercise are taken from there. There is more detail about them in the DisRep.
Secondly, we will get a vector from the user, check if it is valid - it contains numbers in double type and no characters.
- if it is not valid, we will print an error message to the screen and go back to get a new vector from the user.
- if it is valid, we will call the KNN methods with the argumants from the line command. 
In the KNN algorithem we first go over every vector in the given file and split it into two separate vectors - one with all the numbers values - and one with the string value that classify the topic of the vector. If the vector with the number values and the input vector are not at the same size, we will not be able to calculate the distance between them, so we will print an error message to the screen and go back to get a new vector from the user.
Else, we will call the distance method according to the one from the arguments in the line command, calaculate the distance between the input vector and the one from the file and add the result to a vector of distances from the input vector.
After we did this for every vector in the file, we will check that the vector with the distances and the vector with the strings are at the same size - if not, the file is not proper, so it will exit the code.
Then, we push the distance vector and the string vector into pairs vector - so every value in the vector is a pair of distance and a string - and sort it in ascanding order by distance.
Last, using a map, we will check which one of the strings is the most repetitive - this will be the classified topic of the vector that the user entered - and print it to the screen.
After all, we will get a new vector from the user.

For executing the code we need to run the following command:
make

The program will run as follow:
a.out k file distance

For example:
a.out 3 iris_classified.csv MAN
Will uplaod iris_classified vectors and calulate Manhattan ditance between each one of the vectors and the input vector,
get the 3 closes neighbors - by sorting the distance vector and the name of the specific topic, and get the most significant topic in the k neighbors.
We will print the correct classified topic, and get an infinte input from user all over again.
