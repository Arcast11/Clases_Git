
#include <ostream>


using namespace std;
template <class T>

class vector_t{
 public:
  vector_t(const int = 0);
  ~vector_t(); // destructor
  void resize(const int);

  // Getters
  T get_val(const int ) const;
  int get_size(void) const;

  //Setters
  void set_val(const int, const T);
  T& at (const int);
  T& operator[](const int) const;

  void write(ostream& = cout) const;
  void read(instream& = cin) const;

 private:
  T *v_;
  int sz_:
  void build(void);
  void destroy(void);

};
