#include "controler.h"
// #include <Main/tools.h>

Controler::Controler(float kp, float kd, float ki)
{   KP = kp;
    KD = kd;
    KI = ki;
    integral = 0;
    time = 0 ; 
    last_time = 0 ;
    delta_time= 0 ;
    last_error = 0;
    error = 0;
}

float Controler::output(float input_value, float current_value){
    error =  input_value - current_value ;
    time = micros();
    delta_time = time - last_time;
    if(input_value == 0){
        output_value =  input_value + proporcional() + derivative() ;
    }else{
        output_value =  input_value +proporcional() + integrative() + derivative();
    }

    // output_value = saturation(output_value,1000);

    last_time = time;
    return output_value;
}

float Controler::proporcional(){

    return error*KP; 

}

float Controler::integrative(){
    integral = integral + error*KI ;
    // integral = saturation(integral,1000);
    return integral ;

}

float Controler::derivative(){
    delta_error = last_error - error ;
    return delta_error*KD;

}






