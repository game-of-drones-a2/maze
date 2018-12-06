// here the usonic sensor should get 3 distances: Left, Right, Straight sensors
// no evaluation/analysis - we just need 3 values
// Todo: find out, if arrays are working like in c -> "call by address"

// maybe something bigger than int? use uint? 8, 16, 32? how sensitive are the sensors? do we need it that sensitive?
// we could do int if using mm, or should use float?


int get_usonic_data(NewPing sonar){
    delay(200); // minimum 33 ms
    return sonar.ping_cm();
}

