# Operating-Systems-Assignment-2
#Nick Weber
#4/21/2022
#Banker's Algorithm

In this repository, you should find two files: 'bankerAlg.cpp' and 'inputMatrices.txt'.

Inside of the inputMatrices.txt there contains three matrices with the corresponding values from the example in the assignment description.

It is important to note that bankerAlg.cpp will read in the allocation (5X3) matrix first, the maximum (5X3) matrix second and the available (1X3) matrix last.

This order is crucial to remember when altering the input numbers. 

DO NOT add any additional integers or strings to the txt. This may crash the file I/O.

If you wish to test your own data set replace matrix integers with the matrix integers you wish to test.

----------------------------------------------------------------------------------------------

In terms of bankerAlg.cpp, the code works as follows:

3 two-dimensional arrays are created for the allocation[], maximum[] and need[] matrices.

An additional array is created for the available resources.

'inputMatrices.txt' is then opened and the inputted matrices (allocated, maximum and available) are filled with their respective input values.

Next, an array 'finish' has its values initialized to 0; this array indicates whether each process has had its resource request granted (0 = no, 1 = yes).

The need matrix then stores the values of how many resources each process is requesting.

The program then goes from process to process comparing its need matrix values to the available matrix that keeps a running tally of how many resources are available 
for each resource type (A,B,C).

If a process is requesting more resources than are available then it skips that process and comes back to it when the system has enough available resources or when it 
is determined the sequence is unsafe.

If the sequence is safe, the order of processes is stored in its own array: 'seq[]' and this sequence is printed to the terminal.

----------------------------------------------------------------------------------------------

To compile and run this program, download the above two files into a terminal directory of your choice and run these commands:

g++ -o bankerAlg bankerAlg.cpp

./bankerAlg

----------------------------------------------------------------------------------------------

There are a couple of .png files that show what terminal results should look like in the case that the sequence is safe or that it is unsafe

The Given Example is an example of a safe sequence, so the program will output that the correct sequence order will be P1, P3, P4, P0, P2

If you were to initialize the Available matrix to {0, 0, 0} (no available resource), the sequence would then be unsafe because no process would be able to receive their requested resources.
