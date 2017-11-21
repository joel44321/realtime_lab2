/*
 * slip.h
 *
 *  Created on: 21 Nov 2017
 *      Author: Joel
 */

#ifndef SLIP_H_
#define SLIP_H_

/* SLIP special character codes
*/

#define END             /*'e'*/ 0300    /* indicates end of packet */
#define ESC             /*'s'*/ 0333    /* indicates byte stuffing */
#define ESC_END         /*'d'*/ 0334    /* ESC ESC_END means END data byte */
#define ESC_ESC         /*'c'*/ 0335    /* ESC ESC_ESC means ESC data byte */

void send_packet(char *p, int len);
int recv_packet(char *p, int len);

#endif /* SLIP_H_ */
