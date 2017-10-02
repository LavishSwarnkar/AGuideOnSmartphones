#include"header\fun.h"
#include"header\pass.h"
void welcome()
{
	clrscr();

	int i,j,k,n;
	char s[80];
  delay(1500);
	textmode(C80);

	halfb(1,1,80,24,1,30);
	halfb(1,3,80,24,10,30);
	halfb(1,5,80,24,9,30);

	ifstream fin("data\\text\\ls.dat");

	for(i=0;i<=23;i++)
	{     	gotoxy(34,1);

		if(i>0&&i<11)    gotoxy(34,i);
		if(i>=11&&i<17)  gotoxy(22,i);
		if(i>=17&&i<=23) gotoxy(16,i);

		fin.getline(s,60,'p');

		for(j=0;s[j]!=NULL;j++)
		{	if(s[j]=='l'||s[j]=='s')
				s[j]='Û';
		}
		textcolor(10); textbackground(1);
		cprintf(s);

		delay(30);
	}
	fin.close();
	delay(700);
	downb(6);

	lcon("presents",18,7,3,6);
	lcon("a",9,14,3,6);
	lcon("guide",23,14,3,6);
	lcon("on",61,14,3,6);
	delay(700);
	upb(4);

	lcon("smart",26,7,0,12);
	lcon("phones",23,14,0,12);
	delay(700);
	downb(4);

	fin.open("data\\text\\bp.dat");
	for(i=0;i<20;i++)
	{      	fin.getline(s,80,'p');
		for(j=0;s[j]!=NULL;j++)
		{	if(s[j]=='l')
				s[j]='Û';
			if(s[j]=='k')
				s[j]=char(223);
			if(s[j]=='o')
				s[j]=char(220);
		}
		textcolor(14);
		gotoxy(28,3);
		if(i>1)    gotoxy(28,2+i);
		cprintf(s);
		delay(30);
	}
	delay(700);
	upb(3);
}
void overview()
{
	int i,j,n;
	char s[80],s2[81];

	hbox(2,1,80,24,"Û",1,14);
	hbox(3,2,79,23,":",1,3);
	lcon("overview",18,5,0,3);
	hbox(11,18,65,11,"Û",1,14);

	ifstream fin("data\\text\\ov.dat");

	for(i=0;i<6;i++)
	{
		fin>>n;
		fin.getline(s,80,'*');

		for(j=0;j<n;j++)
			s2[j]=' ';

		int k=j;

		for(j=0;s[j]!=NULL;j++)
			s2[k+j]=s[j];

		s2[k+j]=NULL;

		textcolor(0);
		textbackground(3);

		gotoxy(4,14+i);
		cprintf(s2);
		delay(40);
	}
	delay(700);
	fin.close();
	downb(2);
}
void guideline()
{  	int i,j,n;
	char s[80];

	hbox(2,1,80,24,"Û",10,14);
	hbox(3,2,79,23,":",10,2);
	lcon("guideline",15,5,0,10);
	hbox(11,15,67,11,"Û",0,14);

	ifstream fin("data\\text\\gl.dat");
	for(i=0;i<6;i++)
	{     	char s2[81];
		fin>>n;
		fin.getline(s,80,'*');
		for(j=0;j<n;j++)
			s2[j]=' ';

		int k=j;

		for(j=0;s[j]!=NULL;j++)
				s2[k+j]=s[j];
		s2[k+j]=NULL;

		textcolor(0); textbackground(2);

		gotoxy(11,14+i);
		cprintf(s2);
		delay(30);

	}
	fin.close();
	delay(700);
}

login()
{     	clrscr();
	char k='0', s1[50]=">> NEW USER? CREATE A NEW ACCOUNT NOW!";
	char  s2[30]=">> EXISTING USER? LOGIN NOW!";
	char s3[30]=">> CHANGE PASSWORD";
	char s4[30]=">> FORGOT PASSWORD? RENEW IT!";
	char s5[80]="(ARROW KEYS / W,A,S,D)-SELECTION  || 'C'-CONFIRMATION  || 'M'-ADMINISTRATOR";

	int ch=1,f=0;
	for(int i=0;i<=14;i++)
	{    	textbackground(i);
		clrscr();
		delay(40);
	}
	textbackground(1);
	clrscr();

	textcolor(1);

	hbox(2,1,80,24,"Û",15,1);
	lcon("login",26,4,15,1);
	hbox(10,26,55,10,"Û",7,7);
	fbox(12,18,62,22,"Û",0,7);
	hbox(12,18,62,22,"Û",15,2);
	textcolor(15); textbackground(0);
	gotoxy(22,14); cprintf(s1);
	textcolor(15); textbackground(1);
	gotoxy(22,16); cprintf(s2);
	gotoxy(22,18); cprintf(s3);
	gotoxy(22,20); cprintf(s4);

	textcolor(15); textbackground(1);
	gotoxy(3,23); cprintf(s5);
	gotoxy(70,4); cprintf("'E'-EXIT");

	while(1)
	{	k=getch();
		if((k=='2'||k=='4'||k=='w'||k=='a'|| k=='W'||k=='A' ||k==72||k==75 )&&ch!=1)
			ch-=1;

		else if((k=='5'||k=='6'||k=='s'||k=='d' || k=='S'||k=='D' ||k==80||k==77 ) &&ch!=4)
			ch+=1;

		else if(k=='c'||k=='C'||k==13)
		{	fbox(12,3,78,23,"Û",1,1);
			hbox(10,26,55,10,"Û",7,1);
			textcolor(0); textbackground(6);
			switch(ch)
			{      	case 1: newp();       break;
				case 2: loginsub();   break;
				case 3:	cp();         break;
				case 4: fp();         break;
			}
			f=1;
		}

		else if(k=='e'||k=='E')
			exite();
		else if(k=='m'||k=='M')
			{ admin(); f=1; }
		if(f)
		{	hbox(10,26,55,10,"Û",7,1,0);
			fbox(12,4,76,23,"Û",1,1,0);
			fbox(12,18,62,22,"Û",0,7,0);
			hbox(12,18,62,22,"Û",15,2,0);
			textcolor(15); textbackground(0);
			gotoxy(22,14); cprintf(s1);
			textcolor(0); textbackground(7);
			gotoxy(22,16); cprintf(s2);
			gotoxy(22,18); cprintf(s3);
			gotoxy(22,20); cprintf(s4);
			textcolor(15); textbackground(1);
			gotoxy(3,23); cprintf(s5);
			gotoxy(70,4); cprintf("'E'-EXIT");
			gotoxy(70,5); cprintf("        ");
			f=0;
		}

		switch(ch)
		{     	case 1: textcolor(15); textbackground(0);
				gotoxy(22,14); cprintf(s1);
				textcolor(15); textbackground(1);
				gotoxy(22,16); cprintf(s2);
				gotoxy(22,18); cprintf(s3);
				gotoxy(22,20); cprintf(s4); break;
			case 2: textcolor(15); textbackground(1);
				gotoxy(22,14); cprintf(s1);
				textcolor(15); textbackground(0);
				gotoxy(22,16); cprintf(s2);
				textcolor(15); textbackground(1);
				gotoxy(22,18); cprintf(s3);
				gotoxy(22,20); cprintf(s4); break;
			case 3: textcolor(15); textbackground(1);
				gotoxy(22,14); cprintf(s1);
				gotoxy(22,16); cprintf(s2);
				textcolor(15); textbackground(0);
				gotoxy(22,18); cprintf(s3);
				textcolor(15); textbackground(1);
				gotoxy(22,20); cprintf(s4); break;
			case 4: textcolor(15); textbackground(1);
				gotoxy(22,14); cprintf(s1);
				gotoxy(22,16); cprintf(s2);
				gotoxy(22,18); cprintf(s3);
				textcolor(15); textbackground(0);
				gotoxy(22,20); cprintf(s4); break;
		}
       }
}