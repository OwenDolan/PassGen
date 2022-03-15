#include "../header/encrypt.h"


void Encrypt::encriptPass(string pass) {

}

mpz_t* Encrypt::chooseQ() {
    gmp_randstate_t state;
    mpz_t* q;
    //gmp_randinit_mt(state);
    //mpz_urandomb(q,state,10);
    return(q);
}

//works
int Encrypt::gcd(int p1, int p2) {

    int temp;
    if (p1 < p2) {
        temp = p1;
        p1 = p2;
        p2 = temp;
    }
    if (p1 == 1 || p2 == 1) {
        return 1;
    }
    else if (p1 % p2 == 0) {
        return p2;
    }
    else {
        return gcd(p1%p2, p2);
    }
}

//works but could be refined
bool Encrypt::isPrimeFLT(int p) {
    //double a = 1 + (rand() % p);
    int a = 2;
    bool relativelyPrime = false;
    while (!relativelyPrime) {
        if (p < a) {
            return false; //case for when p == 1
        }
        if (p % a != 0) {
            relativelyPrime = true;
        }
        else {
            a++;
        }
    }
    double aa = 1;
    for (int i = 1; i < p; i++) {
        aa = aa*a;
    }
   // a = aa;
    if (fmod(aa,p) == 1) {
        return true;
    } else { return false; }
}

//works as far as i know
int Encrypt::primeFactorizaiton(int n) {
    int upperBound = sqrt(n);
    for (int i = 1; i < upperBound; i++) {
        if (isPrimeFLT(i)) {
            if (n % i == 0) {
                    return i;
            }
        }
    }
    return -1;
}

//need to test
int Encrypt::eulerTotientFn(int p, int q) {
    if (isPrimeFLT(p) && isPrimeFLT(q)) {
        return (p-1)*(q-1);
    }
    else {
        return -1;
    }
}

//need to test
int Encrypt::calcD(int e, int p, int q, int n) {
    /*
    int d = (eulerTotientFn(p, q) + 1) / e;
    return d;
     */
    /*
    double phi = eulerTotientFn(p, q);
    double ii;
    for (int i = 2; i < n; i++) {
        ii = i;
        if (gcd(i, n) == 1) {
        if (fmod(pow(ii,phi), n) == 1) {
            return i;
        }
    }
    }
     */
    
    int i = 1;
    int d = -1;
    bool decoded = false;
    
    while (!decoded) {
        if (i*e % eulerTotientFn(p, q) == 1) {
            decoded = true;
            d = i;
        }
        else {
            i++;
        }
    }
    return d;
    
}

//need to check if works, probably pointer error in here
int* Encrypt::decrypt(int d, int n, int m, int* messageArr) {
    int *decryptedMess = new int[m];
    int temp;
    int decoded;
    
    for (int i = 0; i < m; i++) {
        decoded = 1;

        for (int j = 0; j < d; j++) {
            decoded = (messageArr[i] * decoded) % n;
        }
        decryptedMess[i] = decoded;
    }

    /*
    for (int i = 0; i < m; i++) {
        int decoded = 0;
        int perm = messageArr[i];
        if (d % 2 == 0) {   // if exponent is even
            temp = messageArr[i];
            if (temp > n) { // check to see if we can simplify
                decoded += temp % n;
            }
            else {  //else square base and divide d by 2 by exponent rules
                temp = temp * temp;
                d = d/2;
                if (temp > n) {
                    decoded += temp % n;
                }
                temp = messageArr[i];
            }
        }
        else {
            d = d-1;
            
        }
    }
*/
    /*
    int temp;
    double decoded;

    for (int i = 0; i < m; i++) {
        decoded = 1;
        temp = messageArr[i];
        for (int j = 0; j < d; j++) {
            decoded = decoded * temp;
        }
        decryptedMess[i] = fmod(decoded, n);
    }
    
    
    */
    
    
    return decryptedMess;
    
}
string Encrypt::decode (int *decryptedMess, int m) {
    string decodedMess;
    for (int i = 0; i < m; i++) {
        if (decryptedMess[i] > 33) { // test for broken algorithm
            cout << "uh oh" << endl;
        }
        else if (decryptedMess[i] < 29 && decryptedMess[i] > 2) { //test for letter
            char letter = decryptedMess[i] + 62;
            decodedMess += letter;
        }
        else if (decryptedMess[i] == 29) {
            decodedMess += ' ';
        }
        else if (decryptedMess[i] == 30) {
            decodedMess += '"';
        }
        else if (decryptedMess[i] == 31) {
            decodedMess += '.';
        }
        else if (decryptedMess[i] == 32) {
            decodedMess += ',';
        }
        else if (decryptedMess[i] == 33) {
            decodedMess += "'";
        }
        else {
            cout << "uh oh" << endl;
        }
    }
    return decodedMess;

}
