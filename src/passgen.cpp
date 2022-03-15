#include <iostream>
#include <queue>
#include <random>

#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

using namespace std;


char computeSymbol() {
     int sym = rand() % 6 + 33;

     int bol = rand() % 5 + 60;

     int flip = rand() % 2;

     if (flip == 1) {
          return static_cast<char>(bol);

     }
     else if (flip == 0) {
          return static_cast<char>(sym);
     }
     else {
          cout << "invalid logic." << endl;
          return '*';
     }
}

char computeLowercase() {
     int low = rand() % 26 + 97;
     return static_cast<char>(low);
}

char computeCapitol() {
     int cap = rand() % 26 + 65;
     return static_cast<char>(cap);
}

void printPass(queue<char>* pass){
     for (unsigned i = 0; i < pass->size(); i++) {
          cout << pass->front() << flush;
          pass->pop();
     }
     cout << endl;
}

void encriptPass(queue<char> *pass) {

     

}

queue<char>* constructPass(queue<char>* generated, unsigned length) {

     int choice;
     for (unsigned i = 0; i < length; i++) {
          choice = rand() % 3;
          if (choice == 0) {
               generated->push(computeCapitol());
          }
          else if (choice == 1) {
               generated->push(computeLowercase());
          }
          else if (choice == 2) {
               generated->push(computeSymbol());
          }
          else {
               cout << "invalid logic" << endl; // can add exception + handling here
          }
     }
     return generated;
}

long long unsigned chooseQ() {

}

int main() {
     srand(time(nullptr));

     cout << "Welcome to PassGen <->" << endl;
     cout << "length: " << flush;

     unsigned length = 50;
     //cin >> length;
     while (cin.fail()) {
          cout << "invalid input." << endl;
          cin.clear();
          cin.ignore();
          cin >> length;
     }


     
     queue<char> *generated = new queue<char>;
     generated = constructPass(generated, length);

     printPass(generated);


     delete generated;
     return 0;
     
}