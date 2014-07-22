#ifndef MOBILE_VECTOR_H_
#define MOBILE_VECTOR_H_

class Mobile_Vector
{
private:
    float           velocity_x;
    float           velocity_y;

    float           velocity_cap;

    float           acceleration_x;
    float           acceleration_y;

    float           acceleration_cap;

public:
    /*ctr*/         Mobile_Vector();
                    /*********************************
                    * Start off at a set acceleration
                    *********************************/
                    Mobile_Vector(float, float);

                    /*********************************
                    * Start off at a set acceleration
                    * and velocity.
                    *********************************/
                    Mobile_Vector(float, float, float, float);

                    /*********************************
                    * Start off at a set acceleration
                    * and velocity, and set the caps
                    * for velocity and acceleration
                    **********************************/
                    Mobile_Vector(float, float, float, float, float, float);

    /*dtr*/         ~Mobile_Vector();

    void            set_acceleration(float, float);
    void            set_velocity(float, float);

    void            scale_velocity(float);

    void            set_acceleration_cap(float);
    void            set_velocity_cap(float);

    float           get_x_velocity();
    float           get_y_velocity();

    float           get_x_acceleration();
    float           get_y_acceleration();

    float           get_acceleration_cap();
    float           get_velocity_cap();
};
#endif
