#include "../header/generator.h"

queue<char>* Generator::constructPass(queue<char>* generated, unsigned length) {

     int choice;
     for (unsigned i = 0; i < length; i++) {
         usleep(5);
          choice = rand() % 6;
          if (choice < 2) {
               generated->push(computeCapitol());
          }
          else if (choice < 5) {
               generated->push(computeLowercase());
          }
          else if (choice == 5) {
               generated->push(computeSymbol());
          }
          else {
               cout << "invalid logic" << endl; // can add exception + handling here
          }
     }
     return generated;
}

char Generator::computeSymbol() {
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

char Generator::computeLowercase() {
     int low = rand() % 26 + 97;
     return static_cast<char>(low);
}

char Generator::computeCapitol() {
     int cap = rand() % 26 + 65;
     return static_cast<char>(cap);
}