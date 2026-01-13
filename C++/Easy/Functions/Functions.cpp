#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int max_numbers(int a, int b, int c, int d){
    return max(a, max(b, max(c, d)));
}

int main() {
    int a, b, c, d;
    
    scanf("%d %d %d %d", &a, &b, &c, &d );
    
    int resultado = max_numbers(a, b, c, d);
    
    printf("%d", resultado);
    
    return 0;
}
