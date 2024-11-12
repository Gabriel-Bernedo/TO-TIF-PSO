#ifndef M_PARTICLE_SWARM
#define M_PARTICLE_SWARM

#define SWARM_SIZE 10
#include "Particle.cpp"

template <typename T>
class ParticleSwarm{
private:
  Particle* particles;
  int size;
  T globalBest;
  double w;
  double c1;
  double c2;
  double globalBestValue;
public:
  ParticleSwarm(): ParticleSwarm(SWARM_SIZE){}

  ParticleSwarm(int size){
    particles = new Particle[size];
    size = size;
  }

  double next(){
    T aux = T(globalBest);
    double auxValue = aux.evaluate();
    for(int i = 0; i < size; i++){
      T val = particles[i].next();
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
    return improveRatio;
  }

  void newVelocity(double w, double c1, double c2){
    for(int i = 0; i < size; i++){
      particles[i].newVelocity(globalBest, w, c1, c2);
    }
  }

};

#endif