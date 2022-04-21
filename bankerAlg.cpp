//Nick Weber
//Operating Systems - Assignment 2
//4/21/2022


#include <iostream>
#include <fstream>
#include <string>

using namespace std;
 

int main()
{
    // P0, P1, P2, P3, P4 are the Process names here


//FILE IO --------------------------------------------

    ifstream inFile;
    inFile.open("inputMatrices.txt");

    const int NUMPROC = 5; // Number of processes
    const int NUMRES = 3; // Number of resources

    int alloc[NUMPROC][NUMRES]; //Allocation Matrix
 
    int max[NUMPROC][NUMRES]; //Max Matrix

    int avail[NUMRES]; //Available Resources Matrix
 
    //ensures the explanation line above the matrix in the txt file is not used as matrix input
    string line;
    getline(inFile, line);



//fills alloc[][] from txt file
    for (int i = 0; i < NUMPROC; ++i){
        for(int j = 0; j < NUMRES; ++j){
            inFile >> alloc[i][j];
        }
    }

//fills max[][] from txt file
    for (int i = 0; i < NUMPROC; ++i){
        for(int j = 0; j < NUMRES; ++j){
            inFile >> max[i][j];
        }
    }    

    for(int i = 0; i < NUMRES; ++i){
        inFile >> avail[i];
    }


    inFile.close();


//END FILE IO------------------------------------------


    int finish[NUMPROC]; //stores 
    int seq[NUMPROC];    //stores the correct safe sequence
    int seqIndex = 0;

    //initializes finish array values to 0 
    for (int k = 0; k < NUMPROC; k++) {
        finish[k] = 0;
    }


    int need[NUMPROC][NUMRES]; //stores the values for how many resources each process is requesting
    for (int i = 0; i < NUMPROC; i++) {
        for (int j = 0; j < NUMRES; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < NUMPROC; i++) {
            if (finish[i] == 0) {
            
                int flag = 0;
                for (int j = 0; j < NUMRES; j++) {
                    if (need[i][j] > avail[j]){ //if a process needs more resources than are available
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {

                    seq[seqIndex++] = i;

                    for (int y = 0; y < NUMRES; y++)
                        avail[y] += alloc[i][y];
                        finish[i] = 1;
                }
            }
        }
    }


  int flag = 1; //if flag is 0, the sequence is not safe; if 1, sequence is safe

  // checks if sequence is safe or not
  for(int i = 0;i<NUMPROC;i++){

        if(finish[i]==0){

            flag = 0;
            cout << "The given sequence is not safe\n";
            break;
        }
  }
 
  //if sequence is safe it prints the order 
  if(flag==1){

    cout << "The Safe Sequence is:" << endl;

      for (int i = 0; i < NUMPROC - 1; i++)
        cout << " P" << seq[i] << ", ";

      cout << " P" << seq[NUMPROC - 1] <<endl;
  }

    return (0);
}