//
//  Perceotron Learning
//
//  Created by Daniel Sodkiewicz
//  Copyright (c) 2014 Daniel Sodkiewicz. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <fstream>
#include <cmath>
#include <ctime>
#include <array>

using namespace std;

// functions
int check_output_t (int a, int check[], int org[]);
int x_array[4][3] = { {0,0,-1},{0,1,-1},{1,0,-1},{1,1,-1}}; // initial values
double w_array[3];
double calculate_xw (int a, int x[], double w[]);


// calculates a value t - the correct value of out put which we want to achieve
int check_output_t (int a, int check[4][3],int org[4][3]) {
    int found = 0;
        for (int i = 0; i <= 3; i++)  {
            found = 0;
            for (int j = 0; j <= 2; j++)  {
                if ( check[a][j] == org[i][j] ) found++;
            }
            if (found == 3) return true;
        }
    return false;
}

// calculate x*w, vector multiplication of inputs and weights values
double calculate_xw (int a, int x[4][3], double w[3]) {
    double result = 0;
        for (int j = 0; j <= 2; j++)  {
            result += (x[a][j] * w[j]);
        }
    return result;
}





int main(int argc, const char * argv[])
{

    int original_str[3];
    
    int t_array[4][3];
    // initialize original array with solutions (2 means nothing)
    for (int i = 0; i <= 3; i++)  {
        for (int j = 0; j <= 2; j++)  {
            t_array[i][j]=2;
        }
    }

// Setting up the truth table for the problem
// values kept in x_array  and t_array
// --------------------------
//   t_array            |
// --------------------------
//     x1     x2    x3  | t
// --------------------------
//  [0][0]  [0][1]  -1  | ?
//  [1][0]  [1][1]  -1  | ?
//  [2][0]  [2][1]  -1  | ?
//  [3][0]  [3][1]  -1  | ?
// --------------------------
//
    
// insert here values for t_array
// for which t must be = 1
// keep the last value -1
//
// This is done in a strage way, because this simple program
// is a fundation for more complex learning algorithms
    
    t_array[0][0] = 0;
    t_array[0][1] = 1;
    t_array[0][2] = -1;
    
    t_array[1][0] = 0;
    t_array[1][1] = 0;
    t_array[1][2] = -1;
    
    t_array[2][0] = 1;
    t_array[2][1] = 1;
    t_array[2][2] = -1;
    


// to make sure we are getting random value
srand ( time(NULL) ); // neede for rand()
    
  
    // setup initial values of weight in a random way
double val2;
for (int x = 0; x <= 2; x++) {
    /* pick random number from -1 to 1 and output it */
    val2 = (rand() % 200) -100;
    w_array[x]=val2/100;
}

    
//  train network
    int learning_cycles=1;
    int y;
    int t;
    double l = 0.5; // learning speed
    double xw;
    double correct;
    
while (learning_cycles) {
    // stop training after ... found correct (4) means all
    correct=4;
    
    cout << "x0   x1    x2    |  w0       w1      w2        | x*w   |  y    | t  |   "<<endl;
    
// display x values
for (int x = 0; x <= 3; x++) {
    for (int yy= 0; yy <= 2; yy++) {
        cout << x_array[x][yy]<< "     " ;
}
        
    // display valuies of weights
        for (int i= 0; i <= 2; i++) {

            cout << w_array[i] << "     "  ;
        }
        
        // calculate wx, y amd t
        xw = calculate_xw(x,x_array, w_array);
        if (xw<0) y = 0;
        else y=1;
        t = check_output_t(x,x_array, t_array);
        
        cout <<  " | " << xw <<  " |    " << y;
        cout <<  " |    " << t <<  " | ";
        
        
        // adjust weights based on results

        
        if (y==t) correct--;
        else if (y<t) {
            // y is smaller than needed so we need to make values bigger
            for (int i= 0; i <= 2; i++) {
                if (x_array[x][i]==1) w_array[i] = w_array[i]+l   ;
                else if (x_array[x][i]==-1) w_array[i] = w_array[i]-l   ;
            }
        } else if (y>t)
        {
            for (int i= 0; i <= 2; i++) {
                if (x_array[x][i]==1) w_array[i] = w_array[i]-l   ;
                else if (x_array[x][i]==-1) w_array[i] = w_array[i]+l   ;
            }
        }

        cout << endl;
    }
   
    cout << "incorrect: " << correct;
    cout << endl << endl;
   if (!correct) learning_cycles=0;
  //  learning_cycles--;
}
    
    // final results of a curve separating the solution
    cout << "Answer: y=" << (w_array[2]/w_array[1]) << " - " << (w_array[0]/w_array[1]  ) << "x"<< endl;
    
    // you can copy this result to Google to get a graphs

    return 0;
}

