//Donald Marovich IFT 510 Troy McDaniel
//Project 1
//2's Complement Restoring Division

#include<stdio.h>
#include<stdlib.h>


//begining of main function
int main()
{
    register char A; // https://www.geeksforgeeks.org/understanding-register-keyword/
    register char M;
    register char Q;
    unsigned char store1; 
    unsigned char store2;
    unsigned char store3;
    int x; //for input
    int y; //for input
    int o; //for our for loop interations

    //prompt and take input for dividend
    printf("Enter in the dividend! ");
    scanf("%d", &x);

    //prompt and take input for divisor
    printf("Enter in the divisor! ");
    scanf("%d", &y);

    //initialize the A and Q and M values for our flowchart
    Q = x;
    M = y; 
    A = 0;

    //give back the initial values of Q, M, and A
    //%d is for decimal
    printf("The initial values are: \n");
    printf("A: %d | Q: %d | M: %d\n", A, Q, M);

    //https://www.quora.com/In-C-is-it-a-good-practice-to-use-code-C-sizeof-char-code-instead-of-code-C-1-code
    //we use sizeof(char) to get the number of bits and multiply it by eight
    store3 = sizeof(char)*8;  //try "type" or "variable" or "char" here

    //want absolute values incase there's a negative passed
    Q = abs(x); //Try setting to Q
    M = abs(y); //Try setting to M
    store1 = 1<<(store3-1);

    //for loop matches the context of the flowchart
    //https://beginnersbook.com/2014/01/c-for-loop/ 
    //increment against the number of bits
    for (o=0; o<store3; o++) //i is totally overrated
    {
        //first we shift A and Q to the left using the << shift operators
        //https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/
        //https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
        //https://www.tutorialspoint.com/cprogramming/c_operators.htm

        A = A<<1; //shifting a to the left 
        store2 = Q&store1; //takes the numbers from q against t and does AND on every bit, result is 1 if and only if both bits are 1
        store2 = store2>>(store3-1);  //s is shifting right number of times of bits minus 1 
        Q = Q<<1; //shift q to the right
        A = A|store2;  //Or operation, results 1 if any of the two bits are 1         

        //Subtraction time! A-M = A+(-M), but our computer is smart enough to do A-M :)
        A = A-M;

        //MSB of A -------------WHAT DOES THAT MEAN???
        store2 = A&store1; //takes numbers of A against t and does AND on every bit, results 1 if and only if both bits are 1
        store2 = store2>>(store3-1); //s is shifting to the right number of time of bits minus 1

        //Check here if A is less than zero A<0 (LOOKS LIKE s IS our value of A???)
        //this first if is for a negative A (1 in most significant position)
        if(store2==0) //is there a different way we can check this, still unclear on s
            //setting Q_0 to 1;
            Q = Q|1;

        else
        {
            //setting Q_0 to 0
            Q = Q|0;

            //formula for restoring A is A = A+M
            A = A+M;
        }
    }

    //testing if the user input was less than 0. 
    if (x<0)
        //if so, we want to flip the bits on our answer to get the negative result
        //the ~ is used to flip the bits and of course we add 1 for 2's complement
        A = ~A+1;

    //https://www.tutorialspoint.com/cprogramming/c_operators.htm
    //testing if the dividend will be a negative result
    if (x<0 && y>0 || x>0 && y<0) 
        //to get negative we flip bits and add 1
        Q = ~Q+1;
    
    //Print back the result to the console
    printf("The result is: %d\n", Q);
    printf("With a remainder of: %d\n", A);

    //printf("yRx Format: %dR%d\n", Q, A);

}

