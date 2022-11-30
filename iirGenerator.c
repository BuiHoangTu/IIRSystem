#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//change these define status for other lecture with fir system
//#define H_SIZE 3
#define T_BUFFER_SIZE 2

void buffer_next(int* buffer_index, int step, int buffer_size){
    int tmpi = *buffer_index + step;
    if(tmpi < 0) tmpi = 0 - tmpi;
    *buffer_index = tmpi % buffer_size;
}

double calYn(double xn, double * tBuffer, int tBuffer_index){
    buffer_next(&tBuffer_index,-1,T_BUFFER_SIZE);
    double yn = xn + sqrt(2)*tBuffer[tBuffer_index];
    buffer_next(&tBuffer_index,-1,T_BUFFER_SIZE);
    yn += -1*tBuffer[tBuffer_index];
    
    return yn;
}

//////////////////////////////////////////////////MAIN//////////////////////////////////////////////////
int main(int argc, char* argv[]){
    double* tBuffer = calloc(T_BUFFER_SIZE, sizeof(double));
    int tBuffer_index = 0;

    double xn = 1, yn;
    yn = calYn(xn, tBuffer, tBuffer_index);
    printf("%lf\n", yn);
    tBuffer[tBuffer_index] = yn;
    buffer_next(&tBuffer_index, 1, T_BUFFER_SIZE);

    xn = 0;
    for (int i = 0; i < 100; i++){
        yn = calYn(xn, tBuffer, tBuffer_index);
        printf("%lf\n", yn);
        tBuffer[tBuffer_index] = yn;
        buffer_next(&tBuffer_index, 1, T_BUFFER_SIZE);
    }

    free(tBuffer);

}

