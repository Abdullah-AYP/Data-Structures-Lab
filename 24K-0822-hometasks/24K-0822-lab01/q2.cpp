#include <iostream>
using namespace std;

class Box {
    private:
    int* volume;
    public:
    Box(){
        volume = new int(0);
    }
    Box(int vol){
        volume = new int(vol);
    }
    Box(const Box& other) {
        volume = new int(*other.volume);
    }
    Box& operator=(const Box& other) {
        if(this != &other){
            delete volume;
            volume = new int(*other.volume);
        }
        return *this;
    }
    ~Box() {
        delete volume;
    }
    void setVolume(int vol){
         *volume = vol;
          }
    void show() const{
         cout << "Volume: " << *volume << endl;
          }
};
int main() {
    Box b1;           
    b1.show();
    Box b2(69);      
    b2.show();
    Box b3 = b2;      
    b3.setVolume(999);
    cout << "after changing b3 volume:" << endl;
    b2.show();        
    b3.show();
}
