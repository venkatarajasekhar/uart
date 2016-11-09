//
// com_state utils
//
#include <stdio.h>

#include "uart_drv.h"

void com_state_dump(FILE* f, uart_com_state_t* state)
{
    fprintf(f, "com { ");
    fprintf(f, "ibaud: %d,", state->ibaud);
    fprintf(f, "obaud: %d,", state->obaud);
    fprintf(f, "parity: %d,", state->parity);
    fprintf(f, "stopb: %d,", state->stopb);
    fprintf(f, "csize: %d,", state->csize);
    fprintf(f, "bufsz: %d,", state->bufsz);
    fprintf(f, "buftm: %d,", state->buftm);
    fprintf(f, "xonchar: %d,", state->xonchar);
    fprintf(f, "xoffchar: %d,", state->xoffchar);
    fprintf(f, "iflow: %d,", state->iflow);
    fprintf(f, "oflow: %d,", state->oflow);
    fprintf(f, "}\r\n");
}

void com_state_init(uart_com_state_t* ptr)
{
    uart_com_state_t* uart_s = ptr;
    uart_s->ibaud    = 9600;
    uart_s->obaud    = 9600;
    uart_s->parity   = 0;
    uart_s->stopb    = 1;
    uart_s->csize    = 8;
    uart_s->bufsz    = 1;
    uart_s->buftm    = 0;
    uart_s->xonchar  = 17;
    uart_s->xoffchar = 19;
    uart_s->iflow   = 0;
    uart_s->oflow   = 0;
}

// Copy changed com state configs from source to destination
void com_state_copy(uart_com_state_t* dst,uart_com_state_t* src,
		    uint32_t sflags)
{
    // update the state1 
	uart_com_state_t* uart_dst = dst;
	uart_com_state_t* uart_src = src;
    if (sflags & (1<<UART_OPT_IBAUD)) uart_dst->ibaud = uart_src->ibaud;
    if (sflags & (1<<UART_OPT_OBAUD)) uart_dst->obaud = uart_src->obaud;
    if (sflags & (1<<UART_OPT_CSIZE)) uart_dst->csize = uart_src->csize;
    if (sflags & (1<<UART_OPT_BUFSZ)) uart_dst->bufsz = uart_src->bufsz;
    if (sflags & (1<<UART_OPT_BUFTM)) uart_dst->buftm = uart_src->buftm;
    if (sflags & (1<<UART_OPT_STOPB)) uart_dst->stopb = uart_src->stopb;
    if (sflags & (1<<UART_OPT_PARITY)) uart_dst->parity = uart_src->parity;
    if (sflags & (1<<UART_OPT_IFLOW)) uart_dst->iflow = uart_src->iflow; 
    if (sflags & (1<<UART_OPT_OFLOW)) uart_dst->oflow = uart_src->oflow; 
    if (sflags & (1<<UART_OPT_XOFFCHAR)) uart_dst->xoffchar = uart_src->xoffchar; 
    if (sflags & (1<<UART_OPT_XONCHAR)) uart_dst->xonchar = uart_src->xonchar; 
}
