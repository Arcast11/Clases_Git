
#include <cstdlib>

//Hay que ponerlo tambien el .cc 
namespace AYED {

  class vector{
    public:
     vector(const size_t sz);
     ~vector();
     
     void vector::build(const size_t sz){
      base_ = new double [sz];
    }
// Asi se escribirian los metodos si estan en otro archivo, pero me dil pereza
    void vector::destroy(){
      if (base_ != NULL){
        delete []base_;
        base_ = NULL;
      }
    }

    void vector::resize(size_t new_sz){
      if (new_sz > sz_){
        double *aux {base_};
        build(new_sz);
        for (size_t i{0}; i < sz_ ; i++){
          base_[i] = aux[i];
        }
        delete []aux;
        aux = NULL;
      }
      sz_ = new_sz;
    }

    vector::vector(const size_t sz, double *base) : sz_(sz), base_(base){
      build (sz);
    }

    private:
     double *base_;
     size_t sz_;

     void build(const size_t sz);
     void destroy();
  };
}