#include <cmath>
#include <iostream>

using namespace std;

//// Variablen
// Naturkonstanten
double G = 6.67430E-11;

// Erde
float gErde = 9.81;
double mErde = 5.9722E24;

double mKerbol = 1.7565459E28;


int mass;
long long sMAxis1 = 0;
long long sMAxis2 = 0;

double velocityCircularOrbit(long long sMAxis){
    
    double velocity = sqrtf( (G * mKerbol) / sMAxis );

    return velocity;
}

double velocityTransferBegin(long long r1, long long r2){

    double velocity = sqrtf(2 * G * mKerbol * ((1.0 / r1) - (1.0 / (r1 + r2))));

    return velocity;
}

double velocityTransferEnd(long long r1, long long r2){
    double velocity = sqrtf(2 * G * mKerbol * ((1.0 / r2) - (1.0 / (r1 + r2))));

    return velocity;
}

bool userEingabe(){


    // Semi Major Axis abfragen:
    cout << "Semi Major Axis 1 in m: ";
    cin >> sMAxis1;
    cout << endl;

    cout << "Semi Major Axis 2 in m: ";
    cin >> sMAxis2;
    cout << endl;

    return false;
}

int main(){

    userEingabe();

    float VelocityOne = velocityCircularOrbit(sMAxis1);
    float VelocityTwo = velocityCircularOrbit(sMAxis2);

    float VelocityOneB = velocityTransferBegin(sMAxis1, sMAxis2);
    float VelocityTwoB = velocityTransferEnd(sMAxis1, sMAxis2);

    float DeltaVOne = VelocityOneB - VelocityOne;
    float DelatVTwo = VelocityTwo - VelocityTwoB;

    float totalDeltaV = DeltaVOne + DelatVTwo;


    cout << "Die Geschwindigkeit des Sattelit beträgt im ersten Orbit: " << VelocityOne << "m/s." << endl;
    cout << "Die Geschwindigkeit des Sattelit beträgt im zweiten Orbit: " << VelocityTwo << "m/s." << endl;
    cout << endl;
    cout << endl;

    cout << "Die Geschwindigkeit des Sattelit beträgt nach dem erstem Manöver: " << VelocityOneB << "m/s." << endl;
    cout << "Die Geschwindigkeit des Sattelit beträgt nach dem zweite Manöver: " << VelocityTwoB << "m/s." << endl;
    cout << endl;
    cout << endl;

    cout << "DeltaV 1: " << DeltaVOne << "m/s" << endl;
    cout << "DeltaV 2: " << DelatVTwo << "m/s" << endl;
    cout << endl;

    cout << "Gesammt DeltaV für das Manöver: " << totalDeltaV << "m/s." << endl;

    return 0;
}
