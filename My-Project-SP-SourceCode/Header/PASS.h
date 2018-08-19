#include"header\mm.h"
class id
{   char un[12],pass[12],email[30],mono[20],hintq[20],hinta[20];
public:
      giveun(char s[])
      {strcpy(un,s);
      return 0;
      }
      givepass(char s[])
      {strcpy(pass,s);
      return 0;
      }
      giveemail(char s[])
      {strcpy(email,s);
      return 0;
      }
      givemono(char s[])
      {strcpy(mono,s);
      return 0;
      }
      givehintq(char s[])
      {strcpy(hintq,s);
      return 0;
      }
      givehinta(char s[])
      {strcpy(hinta,s);
      return 0;
      }
      char* getun()
      {return un ;}
       char* getpass()
      {return pass ;}
       char* getemail()
      {return email ;}
       char* getmono()
      {return mono ;}
       char* gethintq()
      {return hintq ;}
       char* gethinta()
      {return hinta ;}
};
int acchk(char s[])
{      	id i1;
	int i=1;
	ifstream fin("data\\text\\id.dat",ios::binary);
	while(!fin.eof())
	{    	fin.read( (char *)&i1,sizeof(i1) );
		if(strcmp(s,i1.getun())==0)
		{    	fin.close();
			return i;
		}
	}
	fin.close();
	i=0;
	return i;
}
void input(id &i1)
{   char s[50];
	gotoxy(9,18);
	cprintf("ENTER USERNAME:                      ");
	gotoxy(26,18); gets(s); i1.giveun(s);
	fbox(17,8,70,19,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(9,18);
	cprintf("ENTER PASSWORD:                        ");
	gotoxy(25,18); gets(s); i1.givepass(s);
	fbox(16,8,70,19,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(9,18);
	cprintf("ENTER EMAIL ID:                                          ");
	gotoxy(25,18);  gets(s); i1.giveemail(s);
	fbox(16,8,70,19,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(9,18);
	cprintf("ENTER MOBILE NO:                          ");
	gotoxy(26,18);  gets(s); i1.givemono(s);
	fbox(16,8,70,19,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(9,18);
	cprintf("ENTER HINT QUESTION:                         ");
	gotoxy(30,18);  gets(s); i1.givehintq(s);
	fbox(16,8,70,19,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(9,18);
	cprintf("ENTER HINT QUESTION'S ANSWER:                                         "); 
	gotoxy(39,18);  gets(s); i1.givehinta(s);
}
void print(id i1)
{
	textcolor(15); textbackground(1);
	gotoxy(9,20);
	cprintf("USERNAME: "); cprintf(i1.getun()); getch();
	fbox(20,8,72,21,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(9,20);
	cprintf("PASSWORD: "); cprintf(i1.getpass()); getch();
	fbox(20,8,72,21,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(9,20);
	cprintf("EMAIL ID: "); cprintf(i1.getemail()); getch();
	fbox(20,8,72,21,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(9,20);
	cprintf("MOBILE NO: "); cprintf(i1.getmono()); getch();
	fbox(20,8,72,21,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(9,20);
	cprintf("HINT QUESTION: "); cprintf(i1.gethintq()); getch();
	fbox(20,8,72,21,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(9,20);
	cprintf("HINT QUESTION'S ANSWER: "); cprintf(i1.gethinta());
}

void pall()
{	hbox(12,26,55,14,"*",15,1);
	hbox(14,7,74,22,"*",15,1); textcolor(15);
	textbackground(1);
	gotoxy(31,13); cprintf(">> PRINT ALL DATA <<");
	id i1;
	char s[20],p[20]="admin";
	int i=1,l=0,k=0;
	gotoxy(25,16);
	cprintf("> ENTER ADMINISTRATOR PASSWORD:                     ");
	gotoxy(57,16);  gets(s);
	if(strcmp(s,p)!=0)
	{	gotoxy(20,19);
		cprintf("ACCESS DENIED! ENTER ANY KEY TO RETURN BACK");
		getch(); return;
	}
	else
	{      	gotoxy(25,17);
		cprintf("# FORMAT : USERNAME,PASSWORD");
		gotoxy(9,18); cprintf("                                    ");
		gotoxy(9,18);
		ifstream fin("data\\text\\id.dat",ios::binary);
		while(!fin.eof())
		{      	fin.read( (char *)&i1,sizeof(i1) );
			if(fin.eof())  break;
			cout<<" "<<i<<".) ";
			cprintf(" ");
			cprintf(i1.getun());
			cprintf(" , ");
			cprintf(i1.getpass());
			i++;
			l+=strlen(i1.getun());
			l+=strlen(i1.getpass());
			l+=10;
			if(l>(61+(k*61))) {gotoxy(9,19+k); k++;}
		}
		fin.close();
	}
	getch(); return;
}

void delall()
{	hbox(12,26,55,14,"*",15,1);
	hbox(14,7,74,22,"*",15,1);
	textcolor(15); textbackground(1);
	gotoxy(30,13); cprintf(">> DELETE ALL DATA <<");
	id i1;
	char s[20],p[20]="admin";
	gotoxy(25,16);
	cprintf("> ENTER ADMINISTRATOR PASSWORD:                   ");
	gotoxy(57,16);	gets(s);
	if(strcmp(s,p)!=0)
	{	gotoxy(20,19);
		cprintf("ACCESS DENIED! ENTER ANY KEY TO RETURN BACK");
		getch(); return;
	}
	else
	{      	ofstream fout("data\\text\\id.dat",ios::binary);
		fout.close();
		gotoxy(15,19);
		cprintf("ALL DATA CLEARED ! ENTER ANY KEY TO KEY TO RETURN BACK");
	}
	getch(); return;
}

void admin()
{     	char s1[50]= "> PRINT ALL THE ACCOUNTS DATA" ;
	char s2[50]= "> DELETE ALL THE ACCOUNTS DATA" ;
	char k='0';
	int ch=1,f=0;
	fbox(12,3,78,23,"Û",1,0);
	textcolor(0); textbackground(14);
	hbox(12,29,51,14,"*",15,1);
	hbox(14,7,74,22,"*",15,1);
	gotoxy(31,13); cprintf(">> ADMINISTRATOR <<");
	textcolor(15); textbackground(1);
	gotoxy(20,16); cprintf(s1);
	textcolor(0); textbackground(7);
	gotoxy(20,18); cprintf(s2);
	textcolor(15); textbackground(1);
	gotoxy(70,4); cprintf("'E'-EXIT");
	gotoxy(70,5); cprintf("'B'-BACK");
	while(1)
	{	k=getch();
		if((k=='2'||k=='4'||k=='w'||k=='a'|| k=='W'||k=='A' ||k==72||k==75 )&&ch!=1)
			ch-=1;

		else if((k=='5'||k=='6'||k=='s'||k=='d' || k=='S'||k=='D' ||k==80||k==77) &&ch!=2)
			ch+=1;

		else if(k=='c'||k=='C'||k==13)
		{   	fbox(12,3,78,23,"Û",1,0,0);
			hbox(12,26,55,14,"*",15,1);
			textcolor(15); textbackground(1);
			switch(ch)
			{     	case 1:	pall();  f=0; break;
				case 2:	delall();  f=0; break;
			}
		}

		else if(k=='e'||k=='E')
			exite();

		else if(k=='b'||k=='B')
			return;
    if(f)
    {
		fbox(12,3,78,23,"Û",1,0,0);
		hbox(12,29,51,14,"*",15,1,0);
		hbox(14,7,74,22,"*",15,1,0);
		gotoxy(31,13); cprintf(">> ADMINISTRATOR <<");
		textcolor(15); textbackground(1);
		gotoxy(20,16); cprintf(s1);
		textcolor(0); textbackground(7);
		gotoxy(20,18); cprintf(s2);
		textcolor(15); textbackground(1);
		gotoxy(70,4); cprintf("'E'-EXIT");
		gotoxy(70,5); cprintf("'B'-BACK");
		}
		switch(ch)
		{     	case 1: textcolor(15); textbackground(1);
				gotoxy(20,16); cprintf(s1);
				textcolor(0); textbackground(7);
				gotoxy(20,18); cprintf(s2); break;
			case 2: textcolor(0); textbackground(7);
				gotoxy(20,16); cprintf(s1);
				textcolor(15); textbackground(1);
				gotoxy(20,18); cprintf(s2); break;
		}
	}
}

void newp()
{	hbox(12,26,55,14,"*",15,1);
	hbox(14,7,74,22,"*",15,1); textcolor(15);
	textbackground(1);
	gotoxy(29,13); cprintf(">> CREATE NEW ACCOUNT <<");
	ofstream fout("data\\text\\id.dat",ios::app|ios::binary);
	if(!fout)  cprintf("ERROR");
	id i1;
	input(i1);

	if(acchk(i1.getun())!=0)
	{ 	gotoxy(17,19);
		cprintf("AN ID WITH SAME USERNAME ALREADY EXISTS.. TRY AGAIN..");
	}
	else
	{	fout.write((char *)&i1,sizeof(i1));
		gotoxy(17,19); cprintf("CONGRATS! YOU ARE NOW A REGISTERED USER");
		fout.close();
	}
	getch(); return;
}

void loginsub()
{	hbox(12,25,56,14,"*",15,1);
	hbox(14,7,74,22,"*",15,1);
	textcolor(15);	textbackground(1);
	gotoxy(27,13); cprintf(">> LOGIN TO  YOUR ACCOUNT <<");
	id i1,i2;
	fbox(16,8,72,19,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(9,18); cprintf("ENTER YOUR USERNAME:                       ");
	gotoxy(30,18); gets(i1.getun());
	fbox(16,8,72,19,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(9,18); cprintf("ENTER YOUR PASSWORD:                         ");
	gotoxy(30,18);
	gets(i1.getpass());
	ifstream fin("data\\text\\id.dat",ios::binary);
	if(!fin)  cout<<"ERROR";
	while(!fin.eof())
	{       fin.read( (char *)&i2,sizeof(i2) );
		if(fin.eof())  break;
		if((strcmp(i1.getun(),i2.getun())==0)&& (strcmp(i1.getpass(),i2.getpass())==0))
		{ 	fin.close();
			gotoxy(9,20);
			cprintf("LOGIN SUCCESSFULL");
			delay(1000);
			mainmenu();
		}
	}
	gotoxy(9,20);
	cprintf("WRONG PASSWORSD/(&)USERNAME! TRY AGAIN..");
	getch(); return;
}

void cp()
{	hbox(12,26,55,14,"*",15,1);
	hbox(14,7,74,22,"*",15,1);
	textcolor(15);	textbackground(1);
	fbox(16,8,72,19,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(28,13);
	cprintf(">> CHANGE YOUR PASSWORD <<");
	id i1,i2;
	int j;
	char s[30],s2[20];
	fbox(16,8,72,19,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(9,18);
	cprintf("ENTER YOUR USERNAME:                          ");
	gotoxy(30,18);
	gets(s); i1.giveun(s);
	if(acchk(i1.getun())==0)
	{	gotoxy(9,19);
		cprintf("USERNAME DOES NOT EXISTS! TRY AGAIN..");
	}
	else
	{      	fbox(16,8,72,19,"Û",1,0,0);
		textcolor(15); textbackground(1);
		gotoxy(9,18);
		cprintf("ENTER YOUR OLD PASSWORD:                             ");
		gotoxy(34,18);	gets(s); i1.givepass(s);
		fbox(16,8,72,19,"Û",1,0,0);
		textcolor(15); textbackground(1);
		gotoxy(9,18);
		cprintf("ENTER YOUR NEW PASSWORD:                      ");
		gotoxy(34,18);	gets(s2);

		fstream file("data\\text\\id.dat",ios::in|ios::out|ios::binary);

		while(!file.eof())
		{    	file.read( (char *)&i2,sizeof(i2) );
			if(strcmp(i2.getpass(),i1.getpass())==0)
			{      	strcpy(i2.getpass(),s2);
				int p=-sizeof(i1);
				file.seekg(p,ios::cur);
				file.write( (char *)&i2,sizeof(i2) );
				fbox(16,8,72,19,"Û",1,0,0);
				textcolor(15); textbackground(1);
				gotoxy(9,18);
				cprintf("PASSWORD CHANGED SUCCESSFULLY! ");
				gotoxy(9,19);
				textcolor(15); textbackground(1);
				cprintf("NOW, YOUR DETAILS ARE AS FOLLOWS PROCEED BY PRESSING ANY KEY: ");
				getch();
				print(i2);
				getch(); return;
			}
			else
			{    	gotoxy(9,19);
				cprintf("DETAILS ENTERED BY YOU ARE WRONG RETURN BACK BY PRESSING ANY KEY ");
			}
		}

	}
	getch(); return;
}
void fp()
{	hbox(12,26,55,14,"*",15,1);
	hbox(14,7,74,22,"*",15,1);
	textcolor(15);	textbackground(1);
	gotoxy(29,13); cprintf(">> RESET YOUR PASSWORD <<");
	id i1,i2;
	char s[20];
	fbox(16,8,70,19,"Û",1,0,0);
	textcolor(15); textbackground(1);
	gotoxy(9,18);
	cprintf("ENTER YOUR USERNAME: ");
	gets(s); i1.giveun(s);

	if(acchk(i1.getun())==0)
	{	fbox(16,8,70,19,"Û",1,0,0);
		textcolor(15); textbackground(1);
		gotoxy(9,19);
		cprintf("USERNAME DOES NOT EXISTS! TRY AGAIN..");
	}
	else
	{	fstream file("data\\text\\id.dat",ios::in|ios::out|ios::binary);
		while(!file.eof())
		{   	if(file.eof()) break;
			file.read( (char *)&i2,sizeof(i2) );
			if(strcmp(i2.getun(),i1.getun())==0)
			{	fbox(16,8,72,19,"Û",1,0,0);
				textcolor(15); textbackground(1);
				gotoxy(9,18);
				cprintf("ANSWER YOUR GIVEN HINT QUESTION: ");
				cprintf(i2.gethintq()); cprintf("? ");
				gotoxy(9,19);    gets(s); i1.givehinta(s);

				if(strcmp(i1.gethinta(),i2.gethinta())==0)
				{	gotoxy(9,19); cprintf("ENTER NEW PASSWORD: ");
					gets(i2.getpass());
					int p=-sizeof(i1);
					file.seekg(p,ios::cur);
					file.write( (char *)&i2,sizeof(i2) );
					fbox(16,8,72,19,"Û",1,0,0);
					textcolor(15); textbackground(1);
					gotoxy(9,18);
					cprintf("PASSWORD RESET SUCCESSFULLY! ");
					gotoxy(9,19);
					textcolor(15); textbackground(1);
					cprintf("NOW, YOUR DETAILS ARE AS FOLLOWS PROCEED BY PRESSING ANY KEY: ");
					getch();   print(i2);
					file.close();
					getch(); return;
				}
				else
				{    	gotoxy(9,19);
					cprintf("DETAILS ENTERED BY YOU ARE WRONG RETURN BACK BY PRESSING ANY KEY ");
				}
			}
		}
	}
	getch(); return;

}
