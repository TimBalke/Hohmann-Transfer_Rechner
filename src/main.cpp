#include <cmath>
#include <iostream>

using namespace std;

//// Variablen
// Naturkonstanten
double G = 6.67430E-11;

// Erde
float gErde = 9.81;
double mErde = 5.9722E24;


int mass;
int sMAxis1 = 0;
int sMAxis2 = 0;

double velocityCircularOrbit(int sMAxis){
    double velocity = sqrtf( (G * mErde) / sMAxis );

    return velocity;
}

double velocityTransferBegin(int r1, int r2){

    double velocity = sqrtf(2 * G * mErde * ((1.0 / r1) - (1.0 / (r1 + r2))));

    return velocity;
}

double velocityTransferEnd(int r1, int r2){
    double velocity = sqrtf(2 * G * mErde * ((1.0 / r2) - (1.0 / (r1 + r2))));

    return velocity;
}

bool userEingabe(){

    // Sattelite Masse abfragen:
    //cout << "Sattelite Masse in kg: ";
    //cin >> mass;
    //cout << endl;

    // Semi Major Axis abfragen:
    cout << "Semi Major Axis 1 in m: ";
    cin >> sMAxis1;
    cout << endl;

    cout << "Semi Major Axis 2 in m: ";
    cin >> sMAxis2;
    cout << endl;

    //cout << "Die Geschwindigkeit des Sattelit beträgt im ersten Orbit: " << velocityCircularOrbit(sMAxis1) << "m/s." << endl;
    //cout << "Die Geschwindigkeit des Sattelit beträgt im zweiten Orbit: " << velocityCircularOrbit(sMAxis2) << "m/s." << endl;

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
