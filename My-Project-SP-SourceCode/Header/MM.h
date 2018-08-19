#include"header\mm2.h"
void mainmenu()
{    	int i,j,ch=1;
	char s[20],k='0';
	mosaic(1);
	hbox(2,2,79,24,"Û",10,1);
	lcon("welcome",4,4,14,1);
	lcon("to",47,4,10,1);
	lcon("the",60,4,14,1);
	lcon("wonderful",15,11,10,1);
	lcon("world",14,18,14,1);
	lcon("of",58,18,10,1);
	delay(300);
	mosaic(2);
	hbox(2,2,79,24,"Û",1,10);
	lcon("smart",26,7,1,10);
	lcon("phones",23,14,1,10);

	ifstream fin("data\\images\\sp.im");
	for(i=0;i<20;i++)
	{    	fin.getline(s,80,'p');
		for(j=0;s[j]!=NULL;j++)
		{    	if(s[j]=='l')
				s[j]='Û';
			if(s[j]=='k')
				s[j]=char(223);
			if(s[j]=='u')
				s[j]=char(222);
			if(s[j]=='o')
				s[j]=char(220);
		}
		textcolor(11);
		gotoxy(6,8);
		if(i>1) gotoxy(6,7+i);
		cprintf(s);
		delay(30);
	}
	fin.close();
	fin.open("data\\images\\pro.im");
	for(i=0;i<20;i++)
	{    	fin.getline(s,80,'p');
		for(j=0;s[j]!=NULL;j++)
		{     	if(s[j]=='l')
				s[j]='Û';
			if(s[j]=='k')
				s[j]=char(223);
			if(s[j]=='u')
				s[j]=char(222);
		}
		textcolor(11);
		gotoxy(60,4);
		if(i>1) gotoxy(60,3+i);
		cprintf(s);
		delay(30);
	}
	fin.close();
	fin.open("data\\images\\bat.im");
	for(i=0;i<20;i++)
	{     	fin.getline(s,80,'p');
		for(j=0;s[j]!=NULL;j++)
		{     	if(s[j]=='Z')
				s[j]='Û';
			if(s[j]=='K')
				s[j]=char(223);
			if(s[j]=='N')
				s[j]=char(222);
			if(s[j]=='l')
				s[j]='Û';
			if(s[j]=='k')
				s[j]=char(223);
			if(s[j]=='u')
				s[j]=char(222);
		}
		textcolor(11);
		gotoxy(60,14);
		if(i>1) gotoxy(60,13+i);
		cprintf(s);
		delay(30);
	}
	fin.close();
	int f=0;
	delay(300);
	mosaic(1);
	hbox(2,2,79,24,"Û",14,1);
	fbox(3,3,78,10,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("main",15,4,10,6);
	lcon("menu",44,4,10,6);
	fbox(11,3,43,23,"Û",3,1);
	fbox(11,44,78,23,"Û",2,1);
	textcolor(1); textbackground(3);
	gotoxy(4,12); cprintf("Û SMART PHONES BRIEF INFORMATION");
	textcolor(11); textbackground(1);
	gotoxy(4,12); cprintf("Û");
	textcolor(1); textbackground(3);
	gotoxy(4,14); cprintf("Û SOME POPULAR SMART PHONES DESCRIPTION");
	gotoxy(4,16); cprintf("Û SMART PHONES FILTERING ");
	gotoxy(4,18); cprintf("Û ADD / MODIFY / EXPORT DATA ");
	gotoxy(4,20); cprintf("Û STATUS");
	gotoxy(4,22); cprintf("Û AMAZE ME");
	textbackground(2);
	gotoxy(45,12); cprintf(">> USE ARROW KEYS OR");
	gotoxy(45,13); cprintf("   W/A/S/D FOR SELECTION");
	gotoxy(45,15); cprintf(">> 'C'-CONFIRMATION");
	gotoxy(45,17); cprintf(">> 'E'- EXIT");
	gotoxy(45,19); cprintf(">> 'L'-HELP | 'B'-ABOUT");
	while(1)
	{	k=getch();
		if((k=='2'||k=='4'||k=='w'||k=='a'|| k=='W'||k=='A'||k==72||k==75 )&&ch!=1)
			ch-=1;

		else if((k=='5'||k=='6'||k=='s'||k=='d' || k=='S'||k=='D' ||k==80||k==77 ) &&ch!=6)
			ch+=1;

		else if(k=='c'||k=='C'||k==13)
		{	textcolor(1); textbackground(3);
			switch(ch)
			{   	case 1: info();    break;
				case 2: desc();    break;
				case 3: filter();  break;
				case 4:	add();     break;
				case 5: sta();     break;
				case 6: ama();   break;

			}
f=1;
		}

		else if(k=='e'||k=='E')
			exite();

		else if(k=='l'||k=='L')
		{       help(); f=1;  }

		else if(k=='b'||k=='B')
		{       about();f=1;  }

		if(f)
		{ 	hbox(2,2,79,24,"Û",14,1,0);
			fbox(3,3,78,10,"Û",6,1,0);
			hbox(2,2,79,10,"Û",14,1,0);
			lcon("main",15,4,10,6);
			lcon("menu",44,4,10,6);
			fbox(11,3,43,23,"Û",3,1,0);
			fbox(11,44,78,23,"Û",2,1,0);
			textcolor(1); textbackground(3);
			gotoxy(4,12); cprintf("Û SMART PHONES BRIEF INFORMATION");
			textcolor(11); textbackground(1);
			gotoxy(4,12); cprintf("Û");
			textcolor(1); textbackground(3);
			gotoxy(4,14); cprintf("Û SOME POPULAR SMART PHONES DESCRIPTION");
			gotoxy(4,16); cprintf("Û SMART PHONES FILTERING ");
			gotoxy(4,18); cprintf("Û ADD / MODIFY /EXPORT DATA ");
			gotoxy(4,20); cprintf("Û STATUS");
			gotoxy(4,22); cprintf("Û AMAZE ME");
			textbackground(2);
			gotoxy(45,12); cprintf(">> USE ARROW KEYS OR");
			gotoxy(45,13); cprintf("   W/A/S/D FOR SELECTION");
			gotoxy(45,15); cprintf(">> 'C'-CONFIRMATION");
			gotoxy(45,17); cprintf(">> 'E'- EXIT");
			gotoxy(45,19); cprintf(">> 'L'-HELP | 'B'-ABOUT");
			f=0;
		}
		switch(ch)
		{      	case 1: for(i=0;i<=5;i++)
				{	gotoxy(4,12+(2*i));
					if(i==0) textcolor(11);
					else     textcolor(1);
					cprintf("Û");
				} break;
			case 2: for(i=0;i<=5;i++)
				{	gotoxy(4,12+(2*i));
					if(i==1) textcolor(11);
					else     textcolor(1);
					cprintf("Û");
				} break;
			case 3: for(i=0;i<=5;i++)
				{	gotoxy(4,12+(2*i));
					if(i==2) textcolor(11);
					else     textcolor(1);
					cprintf("Û");
				} break;
			case 4: for(i=0;i<=5;i++)
				{	gotoxy(4,12+(2*i));
					if(i==3) textcolor(11);
					else     textcolor(1);
					cprintf("Û");
				} break;
			case 5: for(i=0;i<=5;i++)
				{	gotoxy(4,12+(2*i));
					if(i==4) textcolor(11);
					else     textcolor(1);
					cprintf("Û");
				} break;
			case 6: for(i=0;i<=5;i++)
				{	gotoxy(4,12+(2*i));
					if(i==5) textcolor(11);
					else     textcolor(1);
					cprintf("Û");
				} break;
		}
       }
}
