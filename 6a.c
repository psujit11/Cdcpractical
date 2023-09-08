#include <stdio.h>
#include <time.h>
void program1(){
int a, b = 10, c, d = 20, e = 30, f, g = 40, h = 50;
for(int i=0; i<1000000000; i++) //take the value of counter very large
{
a = b + i ;
c = d + e;
f = g + h;
}
}

void program2(){
int a, b = 10, c, d = 20, e = 30, f, g = 40, h = 50;
c = d + e;
f = g + h;
for(int i=0; i<1000000000; i++)
{
a = b + i;
}

}
int main(){
	double t1= 0.0;
	double t2= 0.0;

    clock_t begin = clock();
	program1(); 
    clock_t end = clock();
	t1 += (double)(end - begin) / CLOCKS_PER_SEC;

    begin = clock();
	program1(); 
    end = clock();
	t2 += (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Program 1 took %f seconds\n", t1);
	printf("Program 2 took %f seconds\n", t2);
	
}
