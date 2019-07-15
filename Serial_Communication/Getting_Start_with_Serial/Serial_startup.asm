org 0000
	mov scon,#0x50; // setting mode 2(8-bit UART) with Recevice enable bit
	mov tmod,#0x20; // setting mode 2(16-bit timer) of timer
	mov th1,#-3;	// setting baud rate of 9600 (instead of -3 you can use 0xFD as hexadecimal)
	setb tr1;	// start running timer 1
	
	// LOGIC FOR SEND 'A' 10 TIMES:
	mov r0,#10;
	l2:mov sbuf,#'A';
	l1:jnb ti,l1;
	clr ti;
	djnz r0,l2;
	l3:sjmp l3;
	end