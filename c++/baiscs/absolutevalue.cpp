#include <iostream>
#include <bitset>
using namespace std;

int absolut(int x) {
    int mask = x >> 31;

    return (mask+x)^mask;
}

class youcef{
public:
    __pure virtual void draw (){
        cout <<"hello world"<<endl;
    }
};
int main() {
    youcef y;
    y.draw();
    int x = -100;
    cout << absolut(x) << endl;
int x=121321;
reinterpret_cast<const char *>(&x);
cout <<x<<endl;
 
    return 0;
}




