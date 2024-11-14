#ifndef M_EXAMPLE_CLASS
#define M_EXAMPLE_CLASS

#include "Particle.cpp"
#include <cstdlib>
#include <cmath>
#include <iostream>
struct ExampleClass : IParticle<ExampleClass>{
  private:
    double x;
    double y;
    double evaluateFunc(){
      return 
        6 * pow(2.718281, -1 * pow(x - 30, 2) / (2 * 4)) + 
        2 * pow(2.718281, -1 * pow(y - 15, 2) / (2 * 16));
    };
  public:
    ExampleClass(): ExampleClass(0.0, 0.0){}
    ExampleClass(double x, double y): x(x), y(y){}
    ExampleClass(ExampleClass &a): x(a.x), y(a.y){}


    static ExampleClass random() {
      ExampleClass e;
      e.x = rand() % 10;
      e.y = rand() % 10;
      // e.print("");
      return e;
    }

    static ExampleClass randomVelocity(){
      ExampleClass e;
      e.x = rand() % 10;
      e.y = rand() % 10;
      return e;
    }

    double evaluate() override{
      return evaluateFunc();
    }

    void print(std::string msg){
      std::cout << "X: " << x << " Y: " << y << "\n" + msg << std::endl;
    }

    ExampleClass operator+(ExampleClass other){
      ExampleClass e;
      e.x = x + other.x;
      e.y = y + other.y;
      return e;
    }

    ExampleClass operator-(ExampleClass other){
      ExampleClass e;
      e.x = x - other.x;
      e.y = y - other.y;
      return e;
    }

    ExampleClass operator*(double scalar){
      ExampleClass e;
      e.x = x * scalar;
      e.y = y * scalar;
      // e.print("Nuevo Valor :");
      return e;
    }
};
#endif