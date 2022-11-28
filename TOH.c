// Day 11:
// Problem 1:
// Write a program in C to implement:
// 1.	Static queue
// 2.	Dynamic queue
// 3.	Circular queue
// to perform the following operations:
// a.	Insert
// b.	Delete
// c.	Display

// Problem 2:
// Write a program in C to implement tower of Hanoi problem and display the sequence of moves.
#include<stdio.h>
void t_o_h(int n,char a,char b,char c)
{
    if(n==1){
    printf("\nMove %c to %c",a,c);
    return;
    }
    else if(n>1)
    {
        t_o_h(n-1,a,c,b);
        printf("\nMove %c to %c",a,c);
        t_o_h(n-1,b,a,c);
    }
}
int main(){
    int n;
    printf("Please enter the number--");
    scanf("%d",&n);
    char a='A',b='B',c='C';
    t_o_h(n,a,b,c);
    return 0;
}