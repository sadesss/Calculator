#ifndef CALCULATE_H
#define CALCULATE_H
#define ERROR 12345e-56
#define ERRORS 123456e-67


struct Data {
    double num1;
    double num2;
    char operation;
};

double calc(struct Data data);


#endif //CALCULATE_H
