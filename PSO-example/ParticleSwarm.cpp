#ifndef M_PARTICLE_SWARM
#define M_PARTICLE_SWARM

#define SWARM_SIZE 20
#include "Particle.cpp"
#include <string>
#include <iostream>
template <typename T>
class ParticleSwarm{
private:
  Particle<T>* particles;
  int size;
  T globalBest;
  double globalBestValue;
public:
  ParticleSwarm(): ParticleSwarm(SWARM_SIZE){}

  ParticleSwarm(int size) {
    this->particles = new Particle<T>[size];
    this->size = size;
    globalBest = T::random();
  }

  double next(){
    T aux = T(globalBest);
    double auxValue = aux.evaluate();
    for(int i = 0; i < size; i++){
      T val = this->particles[i].next();
      double valValue = val.evaluate();
      if(valValue > auxValue){
        aux = val;
        auxValue = valValue;
      }
    }
    double improveRatio = auxValue - globalBestValue;
    if (improveRatio > 0){
      globalBest = aux;
      globalBestValue = auxValue;
    }
    globalBest.print("Evaluacion : " + std::to_string(globalBestValue));
    return improveRatio;
  }

  void newVelocity(double w, double c1, double c2){
    for(int i = 0; i < size; i++){
      this->particles[i].newVelocity(globalBest, w, c1, c2);
      // std::cout << "New Velocities..." << std::endl;
    }
  }

};

#endif