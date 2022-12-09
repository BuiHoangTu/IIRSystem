#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//change these define status for other lecture with fir system
//#define H_SIZE 3
#define T_BUFFER_SIZE 2

inline int index_next(int current_index, int step, int buffer_size){
    current_index += step;
    while(current_index < 0) current_index = buffer_size + current_index;
    current_index = current_index % current_index;
    return current_index;
}

inline void index_move(int* index, int step, int buffer_size){
    *index = index_next(*index, step, buffer_size);
}

double calYn(double xn, double * tBuffer, int t_index){
    int t_1 = index_next(t_index, -1, T_BUFFER_SIZE);
    int t_2 = index_next(t_index, -2, T_BUFFER_SIZE);
    double yn = xn + sqrt(2)*tBuffer[t_1] - 1* tBuffer[t_2];
    
    return yn;
}

//////////////////////////////////////////////////MAIN//////////////////////////////////////////////////
int main(int argc, char* argv[]){
    double dTBuffer[T_BUFFER_SIZE] = {0};
    double* tBuffer;
    tBuffer = dTBuffer; //calloc(T_BUFFER_SIZE, sizeof(double));
    int tBuffer_index = 0;

    double xn = 1, yn;
    yn = calYn(xn, tBuffer, tBuffer_index);
    printf("%lf\n", yn);
    tBuffer[tBuffer_index] = yn;
    index_move(&tBuffer_index, 1, T_BUFFER_SIZE);

    xn = 0;
    for (int i = 0; i < 100; i++){
        yn = calYn(xn, tBuffer, tBuffer_index);
        printf("%lf\n", yn);
        tBuffer[tBuffer_index] = yn;
        index_move(&tBuffer_index, 1, T_BUFFER_SIZE);
    }

    //free(tBuffer);

}

