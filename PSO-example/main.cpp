#include "PSO.cpp"
#include "ExampleClass.cpp"
#include <cstdlib>
int main(){
    srand(time(NULL));
    PSO<ExampleClass> pso(0.75, 0.25, 0.25);
    pso.optimize();
    return 0;
}