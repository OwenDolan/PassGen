
#include <iostream>
#include <queue>
#include <random>

//#include <stdio.h>      /* printf, NULL */
//#include <stdlib.h>     /* srand, rand */
#include <time.h> 

//#include "../gmp-6.2.1/gmp.h"

#include "../header/generator.h"
#include "../header/encrypt.h"

using namespace std;


void printPass(queue<char>* pass){
     for (unsigned i = 0; i < pass->size(); i++) {
          std::cout << pass->front() << flush;
          pass->pop();
     }
     std::cout << endl;
}

int main() {

     srand(time(nullptr));

    // cout << "Welcome to PassGen <->" << endl;
     // cout << "length: " << flush;

   std::cout << "Enter e: " << endl;
    int e, n, m;
    cin >> e;
    

    while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "invalid input. try again" << endl;
            cin >> e >> n;
    }
     std::cout << "Enter n: " << endl;
    cin >> n;

    while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "invalid input. try again" << endl;
            cin >> e >> n;
    }
    
std::cout << "Enter m: " << endl;
           cin >> m;
    while (cin.fail()) {
     
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "invalid input. try again" << endl;
            cin >> m;
    }
    /*
     std::cout << "Enter message: " << endl;
        int *encMessage = new int[m];

     for (int i = 0; i < m; i++) {
          cin >> encMessage[i];
        while (cin.fail()) {
            //cin.ignore();
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                std::cout << "invalid input. try again" << endl;
                cin >> encMessage[i];
          } 
     }

    
   // cout << "Enter n: " << endl;
    
    while (!cin.fail()) {
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input. try again" << endl;
        } else { break; }
    }
    */

    
   // cout << "Enter m: " << endl;

    
  //  int *encMessPtr;
  //  encMessPtr = &encMessage[m];

     int *encMessage = new int[m];
     string mess = "hello\n";
     for (int i = 0; i < m+1; i++) {
          encMessage[i] = mess.at(i);
     }

    Encrypt *enc = new Encrypt();

    if (enc->gcd(e,n) != 1) {
        std::cout << "Public key not valid!" << endl;
        return 0;
    }
    
    int p, q, phi, d;
    
    p = enc->primeFactorizaiton(n);
    q = n / p;
    phi = enc->eulerTotientFn(p, q);
    d = enc->calcD(e, p, q, n);

    std::cout << p << " ";
    std::cout << q << " ";
    std::cout << phi << " ";
    std::cout << d << endl;
    
    int *message = new int[m];
    message = enc->decrypt(d, n, m, encMessage);

    std::cout << p << " ";
    std::cout << q << " ";
    std::cout << phi << " ";
    std::cout << d << endl;
    
    for (int i = 0; i < m; i++) {
        std::cout << message[i] << " ";
    }
    cout << endl;
    
    string decryptedMessage = enc->decode(message, m);
    
    std::cout << decryptedMessage << endl;
    
    
    return 0;
}
/*
int main() {
     srand(time(nullptr));

     cout << "Welcome to PassGen <->" << endl;
     cout << "length: " << flush;

a
     Encrypt enc;
     mpz_t *q = new mpz_t();
     q = enc.chooseQ();
     mpz_out_str(cout, 10, q);


     unsigned length = 50;
     //cin >> length;
     while (cin.fail()) {
          cout << "invalid input." << endl;
          cin.clear();
          cin.ignore();
          cin >> length;
     }


     Generator gen;
     queue<char> *generated = new queue<char>;
     generated = gen.constructPass(generated, length);

     printPass(generated);



     delete generated;
     return 0;
     
}
*/