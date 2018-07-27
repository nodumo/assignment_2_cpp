#include <iostream>  
#include <ctime>


using namespace std;

void loop () {   
    for(int i =0; i < 90000; i++){

    }
}

void loop1() {
    for(int i =0; i < 100000; i++){
        loop();
    }
}

int main () {
    
    char a;

    clock_t  t1 = clock ();
    
    loop1();
    
    clock_t  t2 = clock ();
    
    double v = static_cast<double>(t2 -t1)/ CLOCKS_PER_SEC;
    
    cout << v << endl;

    return 1;
    
}        