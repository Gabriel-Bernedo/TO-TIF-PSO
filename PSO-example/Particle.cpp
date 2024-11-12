#ifndef M_PARTICLE
#define M_PARTICLE

class IParticle{
  public:
    virtual IParticle random() = 0;
    virtual IParticle randomVelocity() = 0;
    virtual double evaluate() = 0;
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
    Particle(T init) : position(init){
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
    }

    void newVelocity(T globalBest, double w, double c1, double c2){
        //
      velocity =  
        w * velocity + 
        c1 * (rand() % 10 / 10) * (bestPosition - position) + 
        c2 * (rand() % 10 / 10) * (globalBest - position);
    }
};

#endif