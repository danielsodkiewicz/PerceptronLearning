Perceptron Learning
==================

This simple program trains a neural network with two inputs of binary values, therefore the four patterns for the Threshold Logic Unit (TLI) are: 00, 01, 10, 11. This n-dimensional space representing all the inputs patterns is usually referred to as the pattern space. You can recall from your computer engineering classes that this TLU is behaving as a 2-input gate. 


The model for mt TLI is shown below.  The function is:

```
y=x1*w1+x2*w2+x3*w3
```

The x3 is set to -1, x1 and x2 are used as input of the mentioned above input pattern. The output value y is 1 when the vector multiplication x*w is => 0 and 0 otherwise.

![Neuron](https://raw.githubusercontent.com/danielsodkiewicz/PerceptronLearning/master/neuron.jpg)

The program goes through epochs, in each one all input patterns are checked and y value calculated. It is compared with a value ‘t’ which I use to call the ‘true’ value which we want our system to learn. It goeas through as many epochs as needed to adjust weights in a way to learn a pattern.

For example for OR function we have this table:


| x1  | x2  | t  |
|---|---|---|
| 0  |  0 | 0  |
| 0  | 1  | 1  |
| 1  |  0 | 1  |
| 1  |  1 | 1  |

For each x1 and x2 input the value y is calculated and compare with t. If it is not the same we adjust the weights. The initial weight numbers are assigned randomly. x3 is assigned a value -1 which is a nice trick you probably learned in your Artificial Intelligence course.

How to use it
Insert a pattern you want to train your network and the program will create a function. After you plot it (for example you can use Google search) you can see that a line of the plot is separating 0s and 1s of your t values.


How to use the program
------------------------

For example one solution for the OR function could be:

Find in the source code a line:
```
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
// 
```

In this section show it to the program for which inputs you want to have output = 1. Simply comment inputs for which you want to have output  0.

For the OR function we comment the 1st set (becasue we want output be 0 for (0,0) input):
```
    /*
    t_array[0][0] = 0;
    t_array[0][1] = 0;
    t_array[0][2] = -1;
    */
    t_array[1][0] = 0;
    t_array[1][1] = 1;
    t_array[1][2] = -1;
    
    t_array[2][0] = 1;
    t_array[2][1] = 0;
    t_array[2][2] = -1;
    
    t_array[3][0] = 1;
    t_array[3][1] = 1;
    t_array[3][2] = -1;

```

Answer:
a line separating output 0 represented by point (0,0) and outputs 1 represented by points (0,1), (1,0) and (1,1).

![Answer](https://raw.githubusercontent.com/danielsodkiewicz/PerceptronLearning/master/answer.jpg)
