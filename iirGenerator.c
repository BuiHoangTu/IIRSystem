#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//change these define status for other lecture with fir system
//#define H_SIZE 3
#define T_BUFFER_SIZE 2

/// @brief This function indicates the `step` next index, a safe way to put `n = n+step` 
/// @param current_index your current index (n, i, ...)
/// @param step amount of indexes forward, use negative number if you want to move backward
/// @param buffer_size max index
/// @return the safe `current_index + step`
int index_next(int current_index, int step, int buffer_size){
    current_index += step;
    while(current_index < 0) current_index = buffer_size + current_index;
    current_index = current_index % buffer_size;
    return current_index;
}

/// @brief change index content to `step` move
/// @param index pointer to current index
/// @param step amount of indexes forward, use negative number if you want to move backward
/// @param buffer_size max index
void index_move(int* index, int step, int buffer_size){
    *index = index_next(*index, step, buffer_size);
}

/// @brief calculate output of the sound system, !!!Change the equation underline this function for different assignment !!!
/// @param xn current x from input
/// @param tBuffer buffer of tn
/// @param t_index current index of tn 
/// @return output of system
double calYn(double xn, double * tBuffer, int t_index){
    int n_1 = index_next(t_index, -1, T_BUFFER_SIZE);
    int n_2 = index_next(t_index, -2, T_BUFFER_SIZE);
    double yn = xn + sqrt(2)*tBuffer[n_1] - tBuffer[n_2];
    
    return yn;
}

//////////////////////////////////////////////////MAIN//////////////////////////////////////////////////
int main(int argc, char* argv[]){
    // init memory block and its index
    double dTBuffer[T_BUFFER_SIZE] = {0};
    double* tBuffer;
    tBuffer = dTBuffer; //calloc(T_BUFFER_SIZE, sizeof(double));
    int tBuffer_index = 0;

    // start system with one init pulse
    double xn = 1, yn;
    // calculate output y1
    yn = calYn(xn, tBuffer, tBuffer_index);
    printf("%lf\n", yn);
    // save y1 to memory block
    tBuffer[tBuffer_index] = yn;
    // move to next block in memory
    index_move(&tBuffer_index, 1, T_BUFFER_SIZE);

    // turn off electrical pulse
    xn = 0;
    // let this system run 100 cycles
    for (int i = 0; i < 100; i++){
        yn = calYn(xn, tBuffer, tBuffer_index);
        printf("%lf\n", yn);
        tBuffer[tBuffer_index] = yn;
        index_move(&tBuffer_index, 1, T_BUFFER_SIZE);
    }

    //free(tBuffer);

}

