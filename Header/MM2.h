#include"header\mm3.h"
#include"header\data.h"
#include"header\filter.h"
#include"header\export.h"
void help()
{   	int i,j,n;
	char s[80];
	fbox(3,3,78,23,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("help",29,4,10,6);
	ifstream fin("data\\text\\help.dat");
	for(i=0;i<6;i++)
	{      	char s2[81];
		fin>>n;
		fin.getline(s,80,'*');

		for(j=0;j<n;j++)
			s2[j]=' ';

		int k=j;

		for(j=0;s[j]!=NULL;j++)
			s2[k+j]=s[j];
		s2[k+j]=NULL;

		textcolor(14);
		textbackground(14);

		gotoxy(8,14+i);
		cprintf(s2);
		delay(40);
	}
	fin.close();
	getch();
	return;
}

void about()
{   	int i,j,n;
	char s[80];
	fbox(3,3,78,23,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("about",26,4,10,6);
	ifstream fin("data\\text\\about.dat");
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
		textcolor(14); textbackground(14);

		gotoxy(7,14+i);
		cprintf(s2);
		delay(40);
	}
	getch();
	return;
}

void info()
{   	char k='0';
	int ch=1,f=0;
	hbox(2,2,79,24,"Û",14,1);
	fbox(3,3,78,10,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("information",9,4,10,6);
	fbox(11,3,43,23,"Û",3,1);
	fbox(11,44,78,23,"Û",2,1);
	textcolor(1); textbackground(3);
	gotoxy(4,12); cprintf("Û HISTORY OF SMART PHONES");
	textcolor(11); textbackground(1);
	gotoxy(4,12); cprintf("Û");
	textcolor(1); textbackground(3);
	gotoxy(4,14); cprintf("Û FEATURES OF SMART PHONES");
	gotoxy(4,22); cprintf("'B'-BACK");
	textbackground(2);
	gotoxy(45,12); cprintf(">> USE ARROW KEYS OR");
	gotoxy(45,13); cprintf("   W/A/S/D FOR SELECTION");
	gotoxy(45,15); cprintf(">> 'C'-CONFIRMATION");
	gotoxy(45,17); cprintf(">> 'E'- EXIT");

	while(1)
	{ 	k=getch();
		if((k=='2'||k=='4'||k=='w'||k=='a'|| k=='W'||k=='A' ||k=='A'||k==72||k==75 )&&ch!=1)
			ch-=1;

		else if((k=='5'||k=='6'||k=='s'||k=='d' || k=='S'||k=='D' ||k=='A'||k==80||k==77 )&&ch!=2)
			ch+=1;

		else if(k=='c'||k=='C'||k==13)
		{	fbox(3,3,78,23,"Û",6,7);
			textcolor(1); textbackground(3);
			switch(ch)
			{    	case 1: history();  f=1;break;
				case 2: features(); f=1;break;
			}

		}

		else if(k=='e'||k=='E')
			exite();

		else if(k=='b'||k=='B')
			return;
		if(f)
		{	hbox(2,2,79,24,"Û",14,1,0);
			fbox(3,3,78,10,"Û",6,1,0);
			hbox(2,2,79,10,"Û",14,1,0);
			lcon("information",9,4,10,6);
			fbox(11,3,43,23,"Û",3,1,0);
			fbox(11,44,78,23,"Û",2,1,0);
			textcolor(1); textbackground(3);
			gotoxy(4,12); cprintf("Û HISTORY OF SMART PHONES");
			textcolor(11); textbackground(1);
			gotoxy(4,12); cprintf("Û");
			textcolor(1); textbackground(3);
			gotoxy(4,14); cprintf("Û FEATURES OF SMARTPHONES");
			gotoxy(4,22); cprintf("'B'-BACK");
			textbackground(2);
			gotoxy(45,12); cprintf(">> USE ARROW KEYS OR");
			gotoxy(45,13); cprintf("   W/A/S/D FOR SELECTION");
			gotoxy(45,15); cprintf(">> 'C'-CONFIRMATION");
			gotoxy(45,17); cprintf(">> 'E'- EXIT");
			f=0;
		}
		int i;
		switch(ch)
		{      	case 1: for(i=0;i<2;i++)
				{	gotoxy(4,12+(2*i));
					if(i==0)  textcolor(11);
					else      textcolor(1);
					cprintf("Û");
				}  break;
			case 2: for(i=0;i<2;i++)
				{  	gotoxy(4,12+(2*i));
					if(i==1)  textcolor(11);
					else      textcolor(1);
					cprintf("Û");
				}  break;
		}
	}
}

void desc()
{	int ch=1,g=0;
	char k='0';
	fbox(2,2,79,24,"Û",7,1);
	hbox(2,2,79,24,"Û",15,0);
	lcon("description",8,4,0,15);
	fbox(11,3,78,23,"Û",0,1,0);
	ptext("data\\text\\dguide.dat",15,8,12,0,0);
	getch();
	fbox(2,2,79,24,"Û",7,1,0);
	hbox(2,2,79,24,"Û",15,0,0);
	lcon("brands",23,4,0,15);
	fbox(11,3,78,20,"Û",0,1,0);
	fbox(21,3,78,23,"Û",7,1,0);
	textcolor(15); textbackground(0);
	gotoxy(5,12);
	cprintf("Û APPLE        Û MICROMAX ");
	textcolor(2); textbackground(0);
	gotoxy(5,12); cprintf("Û");
	textcolor(15); textbackground(0);
	gotoxy(5,13);
	cprintf("Û ASUS         Û MICROSOFT ");
	gotoxy(5,14);
	cprintf("Û BLACKBERRY   Û ONE PLUS ");
	gotoxy(5,15);
	cprintf("Û GIONEE       Û OPPO ");
	gotoxy(5,16);
	cprintf("Û HTC          Û SAMSUNG ");
	gotoxy(5,17);
	cprintf("Û Le ECO       Û SONY ");
	gotoxy(5,18);
	cprintf("Û LENOVO       Û XIAOMI ");
	gotoxy(5,19);
	cprintf("Û LG           Û OTHER ");
	textcolor(0); textbackground(15);
	gotoxy(20,22); cprintf("'B'-BACK || 'E'-EXIT || 'C'-CONFIRMATION");
	while(1)
	{	k=getch();
		if((k=='2'||k=='4'||k=='w'||k=='a'|| k=='W'||k=='A' ||k==72||k==75 )&&ch!=1)
			ch-=1;
		else if((k=='5'||k=='6'||k=='s'||k=='d' || k=='S'||k=='D'   ||k==80||k==77) &&ch!=16)
			ch+=1;

		else if(k=='c'||k=='C'||k==13)
		{	textcolor(1); textbackground(3);
			switch(ch)
			{    	case 1:  read("APPLE");   break;
				case 2:  read("ASUS");    break;
				case 3:  read("BLACKBERRY");   break;
				case 4:  read("GIONEE");   break;
				case 5:  read("HTC");   break;
				case 6:  read("Le ECO");   break;
				case 7:  read("LENOVO");   break;
				case 8:  read("LG");   break;
				case 9:  read("MICROMAX");   break;
				case 10:  read("MICROSOFT");   break;
				case 11:  read("ONEPLUS");   break;
				case 12:  read("OPPO");   break;
				case 13:  read("SAMSUNG");   break;
				case 14:  read("SONY");   break;
				case 15:  read("XIAOMI");   break;
				case 16:  read("OTHER");   break;
			}
			g=1;
		}
		else if(k=='e'||k=='E')
			exite();

		else if(k=='b'||k=='B')
			return;
		if(g)
		{	fbox(2,2,79,24,"Û",7,1,0);
			hbox(2,2,79,24,"Û",15,0,0);
			lcon("brands",23,4,0,15);
			fbox(11,3,78,20,"Û",0,1,0);
			fbox(21,3,78,23,"Û",7,1,0);
			textcolor(15); textbackground(0);
			gotoxy(5,12);
			cprintf("Û APPLE        Û MICROMAX ");
			gotoxy(5,13);
			cprintf("Û ASUS         Û MICROSOFT ");
			gotoxy(5,14);
			cprintf("Û BLACKBERRY   Û ONE PLUS ");
			gotoxy(5,15);
			cprintf("Û GIONEE       Û OPPO ");
			gotoxy(5,16);
			cprintf("Û HTC          Û SAMSUNG ");
			gotoxy(5,17);
			cprintf("Û Le ECO       Û SONY ");
			gotoxy(5,18);
			cprintf("Û LENOVO       Û XIAOMI ");
			gotoxy(5,19);
			cprintf("Û LG           Û OTHER ");
			textcolor(0); textbackground(15);
			gotoxy(20,22); cprintf("'B'-BACK || 'E'-EXIT || 'C'-CONFIRMATION"); g=0;
		}
		int i;
		switch(ch)
		{       case 1: for(i=0;i<=7;i++)
				{	gotoxy(5,12+(i));
					if(i==0) textcolor(2);
					else     textcolor(15);
					cprintf("Û");
				} break;
			case 2: for(i=0;i<=7;i++)
				{	gotoxy(5,12+(i));
					if(i==1) textcolor(2);
					else     textcolor(15);
					cprintf("Û");
				} break;
			case 3: for(i=0;i<=7;i++)
				{	gotoxy(5,12+(i));
					if(i==2) textcolor(2);
					else     textcolor(15);
					cprintf("Û");
				} break;
			case 4: for(i=0;i<=7;i++)
				{	gotoxy(5,12+(i));
					if(i==3) textcolor(2);
					else     textcolor(15);
					cprintf("Û");
				} break;
			case 5: for(i=0;i<=7;i++)
				{	gotoxy(5,12+(i));
					if(i==4) textcolor(2);
					else     textcolor(15);
					cprintf("Û");
				} break;
			case 6: for(i=0;i<=7;i++)
				{	gotoxy(5,12+(i));
					if(i==5) textcolor(2);
					else     textcolor(15);
					cprintf("Û");
				} break;
			case 7: for(i=0;i<=7;i++)
				{	gotoxy(5,12+(i));
					if(i==6) textcolor(2);
					else     textcolor(15);
					cprintf("Û");
				} break;
			case 8: for(i=0;i<=7;i++)
				{	gotoxy(20,12+(i));
					textcolor(15);
					cprintf("Û");
				}
				for(i=0;i<=7;i++)
				{	gotoxy(5,12+(i));
					if(i==7) textcolor(2);
					else     textcolor(15);
					cprintf("Û");
				} break;
			case 9: for(i=0;i<=7;i++)
				{	gotoxy(5,12+(i));
					textcolor(15);
					cprintf("Û");
				}
				for(i=0;i<=7;i++)
				{	gotoxy(20,12+(i));
					if(i==0) textcolor(2);
					else	 textcolor(15);
					cprintf("Û");
				} break;
			case 10:for(i=0;i<=7;i++)
				{	gotoxy(20,12+(i));
					if(i==1) textcolor(2);
					else	 textcolor(15);
					cprintf("Û");
				} break;
			case 11:for(i=0;i<=7;i++)
				{	gotoxy(20,12+(i));
					if(i==2) textcolor(2);
					else	 textcolor(15);
					cprintf("Û");
				} break;
			case 12:for(i=0;i<=7;i++)
				{	gotoxy(20,12+(i));
					if(i==3) textcolor(2);
					else	 textcolor(15);
					cprintf("Û");
				} break;
			case 13:for(i=0;i<=7;i++)
				{	gotoxy(20,12+(i));
					if(i==4) textcolor(2);
					else	 textcolor(15);
					cprintf("Û");
				} break;
			case 14:for(i=0;i<=7;i++)
				{	gotoxy(20,12+(i));
					if(i==5) textcolor(2);
					else	 textcolor(15);
					cprintf("Û");
				} break;
			case 15:for(i=0;i<=7;i++)
				{	gotoxy(20,12+(i));
					if(i==6) textcolor(2);
					else	 textcolor(15);
					cprintf("Û");
				} break;
			case 16:for(i=0;i<=7;i++)
				{	gotoxy(20,12+(i));
					if(i==7) textcolor(2);
					else	 textcolor(15);
					cprintf("Û");
				} break;
		}
	}
}

void add()
{     	fbox(3,3,78,23,"Û",6,1);
	fbox(3,3,78,10,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("modification",5,4,10,6);
	int f=0;
	fbox(11,3,43,23,"Û",3,1);
	fbox(11,44,78,23,"Û",2,1);
	textcolor(1); textbackground(3);
	gotoxy(4,12); cprintf("Û ADD DATA");
	textcolor(11); textbackground(1);
	gotoxy(4,12); cprintf("Û");
	textcolor(1); textbackground(3);
	gotoxy(4,14); cprintf("Û MODIFY DATA");
	gotoxy(4,16); cprintf("Û EXPORT DATA");
	gotoxy(4,22); cprintf("'B'-BACK");
	textbackground(2);
	gotoxy(45,12); cprintf(">> USE ARROW KEYS OR");
	gotoxy(45,13); cprintf("   W/A/S/D FOR SELECTION");
	gotoxy(45,15); cprintf(">> 'C'-CONFIRMATION");
	gotoxy(45,17); cprintf(">> 'E'- EXIT");
	char k='0';
	int ch=1;
	while(1)
	{	k=getch();

		if((k=='2'||k=='4'||k=='w'||k=='a'|| k=='W'||k=='A'||k==72||k==75)&&ch!=1)
			ch-=1;

		else if((k=='5'||k=='6'||k=='s'||k=='d' || k=='S'||k=='D' ||k==80||k==77) &&ch!=3)
			ch+=1;

		else if(k=='c'||k=='C'||k==13)
		{	fbox(3,3,78,23,"Û",6,1);
			textcolor(1); textbackground(3);
			switch(ch)
			{      	case 1: addrec(); f=1; break;
				case 2: modrec(); f=1; break;
				case 3: exprec(); f=1; break;
			}

		}

		else if(k=='e'||k=='E')
			exite();

		else if(k=='b'||k=='B')
			return;

		if(f)
		{	hbox(2,2,79,24,"Û",14,1,0);
			fbox(3,3,78,10,"Û",6,1,0);
			hbox(2,2,79,10,"Û",14,1,0);
			lcon("modification",5,4,10,6);
			fbox(11,3,43,23,"Û",3,1,0);
			fbox(11,44,78,23,"Û",2,1,0);
			textcolor(1); textbackground(3);
			gotoxy(4,12); cprintf("Û ADD DATA");
			textcolor(11); textbackground(1);
			gotoxy(4,12); cprintf("Û");
			textcolor(1); textbackground(3);
			gotoxy(4,14); cprintf("Û MODIFY DATA");
			gotoxy(4,16); cprintf("Û EXPORT DATA");
			gotoxy(4,22); cprintf("'B'-BACK");
			textbackground(2);
			gotoxy(45,12); cprintf(">> USE ARROW KEYS OR");
			gotoxy(45,13); cprintf("   W/A/S/D FOR SELECTION");
			gotoxy(45,15); cprintf(">> 'C'-CONFIRMATION");
			gotoxy(45,17); cprintf(">> 'E'- EXIT");
			f=0;
		}
		int i;
		switch(ch)
		{      	case 1: for(i=0;i<=4;i+=2)
				{	gotoxy(4,12+(i));
					if(i==0) textcolor(11);
					else	 textcolor(1);
					cprintf("Û");
				} break;
			case 2: for(i=0;i<=4;i+=2)
				{	gotoxy(4,12+(i));
					if(i==2) textcolor(11);
					else     textcolor(1);
					cprintf("Û");
				} break;
			case 3: for(i=0;i<=4;i+=2)
				{	gotoxy(4,12+(i));
					if(i==4) textcolor(11);
					else     textcolor(1);
					cprintf("Û");
				} break;
		}
	}
}

void filter()
{    	fbox(3,3,78,23,"Û",6,1,0);
	fbox(3,3,78,10,"Û",6,1,0);
	hbox(2,2,79,10,"Û",14,1,0);
	lcon("filteration",8,4,10,6);
	hbox(2,2,79,24,"Û",14,1,0);
	ptext("data\\text\\fguide.dat",14,7,12);
	getch(); fbox(12,3,78,23,"Û",6,1,0);
	while(1)
	{	fbox(3,3,78,23,"Û",6,1,0);
		fbox(3,3,78,10,"Û",6,1,0);
		hbox(2,2,79,10,"Û",14,1,0);
		lcon("filteration",8,4,10,6);
		hbox(2,2,79,24,"Û",14,1,0);
		fbox(12,3,78,23,"Û",6,1,0);
		int fno=1,mno=0,a[150],*p;
		char s[7];
		fbox(11,3,43,23,"Û",3,1,0);
		fbox(11,44,78,23,"Û",2,1,0);
		textcolor(1); textbackground(3);
		gotoxy(4,12); cprintf("1 FILTER BY COMPANY NAME");
		textcolor(11); textbackground(1);
		gotoxy(4,13); cprintf("Û");
		textcolor(1); textbackground(3);
		gotoxy(4,13); cprintf("2 FILTER BY PROCESSOR");
		gotoxy(4,14); cprintf("3 FILTER BY OPERATING SYSTEM");
		gotoxy(4,15); cprintf("4 FILTER BY CAMERA");
		gotoxy(4,16); cprintf("5 FILTER BY MEMORY");
		gotoxy(4,17); cprintf("6 FILTER BY PRICE");
		gotoxy(4,18); cprintf("7 FILTER BY NETWORK");
		gotoxy(4,19); cprintf("8 FILTER BY BATTERY");
		gotoxy(4,20); cprintf("9 FILTER BY YEAR");
		gotoxy(4,21); cprintf("> ENTER FILTERATION SEQUENCE:           ");
		textbackground(2);
		gotoxy(45,12); cprintf(">> WRITE FILTERATION SEQUENCE ");
		gotoxy(45,13); cprintf("   FOR FILTERING IN THAT ");
		gotoxy(45,14); cprintf("   ORDER");
		gotoxy(45,15); cprintf(">> 'E'- EXIT");
		gotoxy(45,17); cprintf(">> 'B'- BACK");
		gotoxy(45,18); cprintf(">> 0 - FINGERPRINT SCANNER");
		gotoxy(34,21);  gets(s);

		if(s[0]=='e'||s[0]=='E')
			exite();

		else if(s[0]=='b'||s[0]=='B')
			return;

		a[0]=10;

		int i,j;
		for(i=0;s[i]!=NULL;i++,fno++)
		{	switch(s[i])
			{ 	case '0':  p=fbysens(a); break;
				case '1':  p=fbycnm(a); break;
				case '2':  p=fbypro(a); break;
				case '3':  p=fbyos(a); break;
				case '4':  p=fbycam(a); break;
				case '5':  p=fbymem(a); break;
				case '6':  p=fbypr(a); break;
				case '7':  p=fbynet(a); break;
				case '8':  p=fbybat(a); break;
				case '9':  p=fbyyear(a); break;
				default :  fbox(22,3,78,23,"Û",7,0,0);
					   textcolor(0); textbackground(15);
					   gotoxy(4,22); cprintf("NO MOBILES FOUND. PRESS ANY KEY TO RETURN");
					   getch(); return;
			}

			for(j=0;*(p+j)!=10;j++)
			a[j]=*(p+j);
			a[j]=10;
			mno=j;
			if(fno>=1&&mno==0)
			{    	fbox(22,3,78,23,"Û",7,0,0);
				textcolor(0); textbackground(15);
				gotoxy(4,22); cprintf("NO MOBILES FOUND. PRESS ANY KEY TO RETURN");
				getch(); return;
			}

		}
		readno(a);
	}
}

void sta()
{   	mi m;
	int i,n=5;
	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
	fin.seekg(0,ios::end);
	i=fin.tellg();
	fin.close();
	n=i/sizeof(m);
	fbox(3,3,78,23,"Û",6,1,0);
	fbox(3,3,78,10,"Û",6,1,0);
	hbox(2,2,79,10,"Û",14,1,0);
	lcon("status",23,4,10,6);
	if(n==0)
	{	textcolor(0); textbackground(6);
		gotoxy(7,15); cprintf("THIS PROGRAM IS HAS NO SMART PHONES DESCRIPTION");
	}
	else
	{	textcolor(0); textbackground(6);
		gotoxy(7,15);cprintf("THIS PROGRAM IS MAINTAINED BY A TOTAL OF      "); gotoxy(48,15); cout<<n;
		cprintf(" SMART PHONE'S DECRIPTION");
		getch();
		return;
	}
}

void ama()
{     	fbox(3,3,78,23,"Û",6,1);
	fbox(3,3,78,10,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("amaze",19,4,10,6);
	lcon("me",51,4,10,6);
	mi m;
	ptext("data\\text\\ama.dat",14,9,16);
	getch();
	ptext("data\\text\\ama2.dat",14,4,12);
	char k=getch();
	if(k=='B'||k=='b') return;
	fbox(12,3,78,23,"Û",6,1);
	ptext("data\\text\\ama3.dat",14,4,12);
	getch();
	return;
}
