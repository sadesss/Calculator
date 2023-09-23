#include "calculate.h"
#include "math.h"

double rooting(struct Data data);
double changing(struct Data data);

double calc(struct Data data){
    double m_res=ERROR;
    if (data.num2!=ERROR || data.num2!=ERRORS){
        if (data.operation=='+'){
            m_res=data.num1 + data.num2;
        } else  if (data.operation=='~' || data.operation=='-'){
            m_res = data.num1 - data.num2;
        } else  if (data.operation=='*'){
            m_res=data.num1*data.num2;
        } else  if (data.operation=='/' && data.num2!=0){
            m_res=data.num1/data.num2;
        } else  if (data.operation=='s'){
            m_res=sin(data.num1);
        } else  if (data.operation=='c'){
            m_res=cos(data.num1);
        } else  if (data.operation=='t' && cos(data.num1)!=0){
            m_res=tan(data.num1);
        }  else  if (data.operation=='k' && sin(data.num1)!=0){
            m_res=1/tan(data.num1);
        }

    }
    if (data.num2==ERROR){
       m_res=changing(data);
    }
    if (data.num2==ERRORS){
       m_res=rooting(data);
    }
    return m_res;
}
double rooting(struct Data data){
    double m_res=ERROR;
    if (data.num1>=0){
        m_res=sqrt(data.num1);
    }
    return m_res;
}
double changing(struct Data data){
    double m_res=ERROR;
    m_res=data.num1*(-1);
    return m_res;
}
