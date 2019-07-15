org 0000
	mov scon,#0x50;		// setting mode 2(8-bit UART) with Recevice enable bit
	mov tmod,#0x20;		// setting mode 2(16-bit timer) of timer
	mov th1,#-3;		// setting baud rate of 9600 (instead of -3 you can use 0xFD as hexadecimal)
	setb tr1;		// start running timer 1
	
	//LOGIC FOR SEND 'A' WHEN P1.1 IS HIGH AND BLINK LED @ P1.2 WHEN P1.1 IS LOW
	setb p1.1;
	l3:jb p1.1,l2;
	cpl p1.2;
	lcall delay;
	sjmp l3;
	l2:mov sbuf,#'A';
	l1:jnb ti,l1;
	clr ti;
	here:jb p1.1,here;
	sjmp l3;
	
	delay:mov r0,#0x04;
	ll4:   mov r2,#255;
	ll3:   mov r1,#255;
	ll2:   djnz r1,ll2;
		  djnz r2,ll3;
		  djnz r0,ll4;
		  ret
		  end