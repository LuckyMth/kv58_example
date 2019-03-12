
#include "kv58_port.h"

static PORT_Type * const PORTx[] = PORT_BASE_PTRS;

void port_init(PTXn_e ptxn, port_mux_t mux)
{
    //打开端口时钟
    SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK<<PTX(ptxn);
    //清标志位
    
    //配置复用功能
    PORTx[PTX(ptxn)]->PCR[PTn(ptxn)] &= ~PORT_PCR_MUX_MASK;
    PORTx[PTX(ptxn)]->PCR[PTn(ptxn)] |= PORT_PCR_MUX(mux);
}


void port_pull(PTXn_e ptxn, port_pull_t pull)
{
    //上拉或下拉使能
    PORTx[PTX(ptxn)]->PCR[PTn(ptxn)] &= ~PORT_PCR_PE_MASK;
    PORTx[PTX(ptxn)]->PCR[PTn(ptxn)] |= PORT_PCR_PE_MASK;
    //上拉或下拉
    PORTx[PTX(ptxn)]->PCR[PTn(ptxn)] &= ~PORT_PCR_PS_MASK;
    PORTx[PTX(ptxn)]->PCR[PTn(ptxn)] |= PORT_PCR_PS(pull);
}

void port_opendrain(PTXn_e ptxn)
{
    PORTx[PTX(ptxn)]->PCR[PTn(ptxn)] &= ~PORT_PCR_ODE_MASK;
    PORTx[PTX(ptxn)]->PCR[PTn(ptxn)] |= PORT_PCR_ODE_MASK;
}





