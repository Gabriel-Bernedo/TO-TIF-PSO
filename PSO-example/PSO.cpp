#ifndef M_PSO
#define M_PSO
template <typename T>
class PSO {
  private:
    Swarm<T> swarm;
    double w;
    double c1;
    double c2;
  public:
    PSO(Swarm<T> swarm, double w, double c1, double c2){
      this->swarm = swarm;
      this->w = w;
      this->c1 = c1;
      this->c2 = c2;
    }

    double next(){
      T aux = T(swarm.getGlobalBest());
      double auxValue = aux.evaluate();
      for(int i = 0; i < swarm.getSize(); i++){
        T val = swarm.getParticle(i).next();
        double valValue = val.evaluate();
        if(valValue > auxValue){
          aux = val;
          auxValue = valValue;
        }
      }
      double improveRatio = auxValue - swarm.getGlobalBestValue();
      if (improveRatio > 0){
        swarm.setGlobalBest(aux);
        swarm.setGlobalBestValue(auxValue);
      }
      return improveRatio;
    }

    void newVelocity(){
      for(int i = 0; i < swarm.getSize(); i++){
        swarm.getParticle(i).newVelocity(swarm.getGlobalBest(), w, c1, c2);
      }
    }
};

#endif M_PSO