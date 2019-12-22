#include"header\mm4.h"
void history()
{	
	hbox(2,2,79,24,"Û",14,1);
	fbox(3,3,78,10,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("history",20,4,10,6);
	ptext("data\\text\\m.dat",15);
	int ch=1;
	char k='0';
	while(1)
	{	k=getch();

		if((k=='2'||k=='4'||k=='w'||k=='a'|| k=='W'||k=='A'|| k==72||k==75 )&&ch!=1)
			ch-=1;

		else if((k=='5'||k=='6'||k=='s'||k=='d' || k=='S'||k=='D' ||k==80||k==77 ) &&ch!=9)
			ch+=1;

		else if(k=='e'||k=='E')
			exite();

		else if(k=='b'||k=='B')
			return;

		switch(ch)
		{   	case 1: ptext("data\\text\\m1.dat"); break;
			case 2: ptext("data\\text\\m2.dat"); break;
			case 3: ptext("data\\text\\m3.dat"); break;
			case 4: ptext("data\\text\\m4.dat"); break;
			case 5: ptext("data\\text\\m5.dat"); break;
			case 6: ptext("data\\text\\m6.dat"); break;
			case 7: ptext("data\\text\\m7.dat"); break;
			case 8: ptext("data\\text\\m8.dat"); break;
			case 9: ptext("data\\text\\m9.dat"); break;
		}
	}
}

void features()
{    	int ch=1,f=0,i;
	char k='0';

	hbox(2,2,79,24,"Û",14,1);
	fbox(3,3,78,10,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("features",17,4,10,6);
	fbox(11,3,43,23,"Û",3,1);
	fbox(11,44,78,23,"Û",2,1);
	textcolor(1); textbackground(3);
	gotoxy(4,12); cprintf("Û PROCESSOR");
	textcolor(11); textbackground(1);
	gotoxy(4,12); cprintf("Û");
	textcolor(1); textbackground(3);
	gotoxy(4,13); cprintf("Û OPERATING SYSTEM");
	gotoxy(4,14); cprintf("Û MEMORY");
	gotoxy(4,15); cprintf("Û BATTERY");
	gotoxy(4,16); cprintf("Û CAMERA");
	gotoxy(4,17); cprintf("Û DISPLAY");
	gotoxy(4,18); cprintf("Û BODY");
	gotoxy(4,19); cprintf("Û NETWORK");
	gotoxy(4,20); cprintf("Û SENSORS");
	gotoxy(4,22); cprintf("'B'-BACK");
	textbackground(2);
	gotoxy(45,12); cprintf(">> USE ARROW KEYS OR");
	gotoxy(45,13); cprintf("   W/A/S/D FOR SELECTION");
	gotoxy(45,15); cprintf(">> 'C'-CONFIRMATION");
	gotoxy(45,17); cprintf(">> 'E'- EXIT");
	while(1)
	{	k=getch();
		if((k=='2'||k=='4'||k=='w'||k=='a'|| k=='W'||k=='A'  || k==72||k==75 )&&ch!=1)
			ch-=1;

		else if((k=='5'||k=='6'||k=='s'||k=='d' || k=='S'||k=='D' ||   k==80||k==77 ) &&ch!=9)
			ch+=1;

		else if(k=='c'||k=='C'||k==13)
		{	fbox(3,3,78,23,"Û",6,1);
			textcolor(1); textbackground(3);
			switch(ch)
			{    	case 1: pro();  break;
				case 2: os();   break;
				case 3: mem();  break;
				case 4: bat();  break;
				case 5: cam();  break;
				case 6: disp();  break;
				case 7: body();  break;
				case 8: net(); 	 break;
				case 9: sens();  break;
			}
			f=1;
		}
		else if(k=='e'||k=='E')
			exite();

		else if(k=='b'||k=='B')
			return;

		if(f)
		{	hbox(2,2,79,24,"Û",14,1,0);
			fbox(3,3,78,10,"Û",6,1,0);
			hbox(2,2,79,10,"Û",14,1,0);
			lcon("features",17,4,10,6);
			fbox(11,3,43,23,"Û",3,1,0);
			fbox(11,44,78,23,"Û",2,1,0);
			textcolor(1); textbackground(3);
			gotoxy(4,12); cprintf("Û PROCESSOR");
			textcolor(11); textbackground(1);
			gotoxy(4,12); cprintf("Û");
			textcolor(1); textbackground(3);
			gotoxy(4,13); cprintf("Û OPERATING SYSTEM");
			gotoxy(4,14); cprintf("Û MEMORY");
			gotoxy(4,15); cprintf("Û BATTERY");
			gotoxy(4,16); cprintf("Û CAMERA");
			gotoxy(4,17); cprintf("Û DISPLAY");
			gotoxy(4,18); cprintf("Û BODY");
			gotoxy(4,19); cprintf("Û NETWORK");
			gotoxy(4,20); cprintf("Û SENSORS");
			gotoxy(4,22); cprintf("'B'-BACK");
			textbackground(2);
			gotoxy(45,12); cprintf(">> USE ARROW KEYS OR");
			gotoxy(45,13); cprintf("   W/A/S/D FOR SELECTION");
			gotoxy(45,15); cprintf(">> 'C'-CONFIRMATION");
			gotoxy(45,17); cprintf(">> 'E'- EXIT");
			f=0;
		}
		
		switch(ch)
		{     	case 1: for(i=0;i<=8;i++)
				{	gotoxy(4,12+(i));
					if(i==0) textcolor(11);
					else	 textcolor(1);
					cprintf("Û");
				}  break;
			case 2: for(i=0;i<=8;i++)
				{	gotoxy(4,12+(i));
					if(i==1) textcolor(11);
					else	 textcolor(1);
					cprintf("Û");
				}  break;
			case 3: for(i=0;i<=8;i++)
				{	gotoxy(4,12+(i));
					if(i==2) textcolor(11);
					else	 textcolor(1);
					cprintf("Û");
				}  break;
			case 4: for(i=0;i<=8;i++)
				{	gotoxy(4,12+(i));
					if(i==3) textcolor(11);
					else	 textcolor(1);
					cprintf("Û");
				}  break;
			case 5: for(i=0;i<=8;i++)
				{	gotoxy(4,12+(i));
					if(i==4) textcolor(11);
					else	 textcolor(1);
					cprintf("Û");
				}  break;
			case 6: for(i=0;i<=8;i++)
				{	gotoxy(4,12+(i));
					if(i==5) textcolor(11);
					else	 textcolor(1);
					cprintf("Û");
				}  break;
			case 7: for(i=0;i<=8;i++)
				{	gotoxy(4,12+(i));
					if(i==6) textcolor(11);
					else	 textcolor(1);
					cprintf("Û");
				}  break;
			case 8: for(i=0;i<=8;i++)
				{	gotoxy(4,12+(i));
					if(i==7) textcolor(11);
					else	 textcolor(1);
					cprintf("Û");
				}  break;
			case 9: for(i=0;i<=8;i++)
				{	gotoxy(4,12+(i));
					if(i==8) textcolor(11);
					else	 textcolor(1);
					cprintf("Û");
				}  break;
		}
	}
}
