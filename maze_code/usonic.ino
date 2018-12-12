// here the usonic sensor should get 3 distances: Left, Right, Straight sensors
// no evaluation/analysis - we just need 3 values
// Todo: find out, if arrays are working like in c -> "call by address"

// maybe something bigger than int? use uint? 8, 16, 32? how sensitive are the sensors? do we need it that sensitive?
// we could do int if using mm, or should use float?

    // do we need check timer here

// ping_cm: Send a ping, returns the distance in centimeters or 0 (zero) if no ping echo within set distance limit 
int get_usonic_data(NewPing sonar){
    delay(50); // minimum 33 ms
    return sonar.ping_cm();
}

