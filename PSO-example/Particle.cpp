#ifndef M_PARTICLE
#define M_PARTICLE

#include <cstdlib>
template <class T>
class IParticle{
  public:
    static T random(){};
    static T randomVelocity(){};
    virtual double evaluate(){};
};

template <class T>
class Particle{
private:
    T position;
    T velocity;
    T bestPosition;
    double bestValue;
    double value;
public:
    Particle() : Particle(T::random()){}
    Particle(T init) {
        position = init;
        velocity = T::randomVelocity();
        bestPosition = position;
        bestValue = position.evaluate();
        value = bestValue;
    }

    T next(){
        position = position + velocity;
        value = position.evaluate();
        if(value > bestValue){
            bestValue = value;
            bestPosition = position;
        }
        return bestPosition;
    }

    void newVelocity(T &globalBest, double w, double c1, double c2){
      velocity = velocity * w 
        + (bestPosition - position) * c1 * (rand() % 10)
        + (globalBest - position) * c2 * (rand() % 10);
    }
};

#endif