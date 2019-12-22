
void pimage(char st[],int c=15,int x=35,int y=12)
{     	int i,j;
	 char s[80];
	ifstream fin(st);
	for(i=0;i<20;i++)
	{     	fin.getline(s,80,'p');
		for(j=0;s[j]!=NULL;j++)
		{      	if(s[j]=='l')
				s[j]='Û';
			if(s[j]=='k')
				s[j]=char(223);
			if(s[j]=='u')
				s[j]=char(222);
		}
		textcolor(c);
		gotoxy(x,y);
		if(i>1) gotoxy(x,y-1+i);
		cprintf(s);
		delay(20);
	}
	delay(700);
	fin.close();
}

void ptext(char st[],int c=14,int x=7,int y=12,int tb=14,int t=6)
{     	fbox(12,7,78,23,"Û",t,1,0);
	int i,n,j;
char s[80];
	ifstream fin(st);
	for(i=0;i<12;i++)
	{     	char s2[81];
		fin>>n;
		fin.getline(s,80,'p');
		for(j=0;j<n;j++)
			s2[j]=' ';

		int k=j;

		for(j=0;s[j]!=NULL;j++)
				s2[k+j]=s[j];

		s2[k+j]=NULL;

		for(j=0;s[j]!=NULL;j++)
		{      	if(s2[j]=='l')
				s2[j]='Û';
			if(s2[j]=='k')
				s2[j]=char(223);
			if(s2[j]=='o')
				s2[j]=char(220);
		}
		textcolor(c);
		textbackground(tb);
		gotoxy(x,y+i);
		cprintf(s2);
		delay(20);
	}
	fin.close();
}

void pro()
{    	
	
	fbox(3,3,78,23,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("processor",15,4,10,6);
	pimage("data\\images\\pro.im",15,33);
	ptext("data\\text\\pro.dat",14,5);
	getch();
	return;
}
void os()
{    
	
	fbox(3,3,78,23,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("os",35,4,10,6);
	pimage("data\\images\\os.im",10,30);
	ptext("data\\text\\os.dat",14,5);
	getch();
	return;
}
void bat()
{    
	 
	fbox(3,3,78,23,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("battery",20,4,10,6);
	pimage("data\\images\\bat.im");
	ptext("data\\text\\bat.dat",14,9);
	getch();
	return;
}
void cam()
{    	
	
	fbox(3,3,78,23,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("camera",23,4,10,6);
	pimage("data\\images\\cam.im",15,32,13);
	ptext("data\\text\\cam.dat",14,8);
	getch();
	return;
}
void disp()
{    	
	
	fbox(3,3,78,23,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("display",20,4,10,6);
	ptext("data\\text\\disp.dat");
	getch();
	return;
}
void body()
{    	
	
	fbox(3,3,78,23,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("body",29,4,10,6);
	ptext("data\\text\\body.dat",14,9);
	getch();
	return;
}
void net()
{    
	
	fbox(3,3,78,23,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("network",20,4,10,6);
	pimage("data\\images\\net.im",15,25,14);
	ptext("data\\text\\net.dat");
	getch();
	return;
}
void sens()
{  
	
	fbox(3,3,78,23,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("sensors",20,4,10,6);
	ptext("data\\text\\sens.dat",14);
	getch();
	return;
}
void mem()
{  
	
	fbox(3,3,78,23,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("memory",23,4,10,6);
	pimage("data\\images\\mem.im");
	ptext("data\\text\\mem.dat",14,6);
	getch();
	return;
}
void exite()
{	textbackground(1);
	clrscr();
	 
	char s[10],s2[10],s3[10];
	strcpy(s,"do");
	strcpy(s2,"you");
	strcpy(s3,"know");
	int i=strlen(s)+strlen(s2)+strlen(s3)+19;
	hbox(2,2,79,24,"Û",15,0);
	i=(80-i)/2;
	lcon(s,i/2,4,15,1);
	lcon(s2,i/2+15,4,15,1);
	lcon(s3,i/2+36,4,15,1);
	ptext("data\\text\\dyk.dat",15,6,12,1,1);
	getch(); exit(1);
}
