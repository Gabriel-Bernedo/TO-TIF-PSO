#ifndef M_PSO
#define M_PSO

#define MAX_PSO_ITERATIONS 100
#include "ParticleSwarm.cpp"
#include <iostream>
template <typename T>
class PSO {
  private:
    ParticleSwarm<T> swarm;
    double w;
    double c1;
    double c2;
    int iterations;
    int maxIterations;
  public:
    PSO(double w, double c1, double c2): PSO(ParticleSwarm<T>(), w, c1, c2){}

    PSO(ParticleSwarm<T> swarm, double w, double c1, double c2){
      this->swarm = swarm;
      this->w = w;
      this->c1 = c1;
      this->c2 = c2;
      maxIterations = MAX_PSO_ITERATIONS;
      iterations = 0;
    }

    void optimize(){
      std::cout << "Start Optimizing..." << std::endl;
      for(; iterations < maxIterations; iterations++){
        double improveRatio = swarm.next();
        swarm.newVelocity(w, c1, c2);
        // if(improveRatio <= -10){
        //   break;
        // }
      }
      std::cout << "End Optimizing..." << std::endl;
    }
};

#endif M_PSO