#include <stdio.h>

typedef unsigned long long ull;

typedef ull (*funcPtr)(ull, ull);

ull add(ull a, ull b){
    return (a+b);
}

ull reduce(ull *array, int sizeOfArray, funcPtr functionPTR, ull startingValue){
    ull result = startingValue;

    for(int i = 0; i < sizeOfArray; i++){
        result = functionPTR(result, array[i]);
    }

    return result;
}

int main(){
    ull arr[3] = {1, 2, 3};

    funcPtr ptr = add;


    printf("result: %llu", reduce(arr, 3, ptr, 0));
    

    return 0;
}