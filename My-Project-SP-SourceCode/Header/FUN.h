void halfb(int t, int l, int r, int b, int c, int d=5)
{    	int i,j,k;
	textcolor(c);
	for(i=r/2,k=(r/2)+1;i>=l;i--,k++)
	{      	for(j=t;j<b+1;j++)
		{	gotoxy(i,j); cprintf("Û");
			if(k==80&&j==25)
			{ gotoxy(k,j); cprintf("Û\b"); }
			else
			{ gotoxy(k,j); cprintf("Û");   }
		}
		delay(d);
	}
}

downb(int c)
{ 	int i,j;
	textcolor(c);
	for(i=24;i>=1;i--)
	{      	for(j=1;j<81;j++)
		{  gotoxy(j,i); cprintf("Û"); }
		delay(2);
	}
	return 0;
}
upb(int c)
{  	int i,j;
	textcolor(c);
	for(i=1;i<25;i++)
	{       for(j=1;j<=80;j++)
		{	gotoxy(j,i); cprintf("Û");
		}
		delay(2);
	}
	return 0;
}
void hbox(int t=2,int l=1,int r=80,int b=24,char p[]="" , int c=7, int bg=0,int d=5)
{   	int i,j,tb=b,tr=r,rr,bb;
	textcolor(c);
	textbackground(bg);
	if((r-l)%2==0) rr=((r-l)/2)+1;
	else rr=((r-l)/2)+1;
	if((b-t)%2==0) bb=((b-t)/2)+1;
	else bb=((b-t)/2)+1;
	for(i=1 ; i<=rr ; i++)
	{    	gotoxy(i+l-1,t); cprintf(p);
		gotoxy(tr,t); cprintf(p);
		gotoxy(i+l-1,b); cprintf(p);
		gotoxy(tr,b); cprintf(p);
		if(i<=bb)
		{    	gotoxy(l,i+t-1); cprintf(p);
			gotoxy(l,tb); cprintf(p);
			gotoxy(r,i+t-1); cprintf(p);
			gotoxy(r,tb); cprintf(p);
		}
		tb--;
		tr--;
		delay(d);
	}
}

void fbox (int t=2,int l=1,int r=80,int b=24,char p[]="" , int c=7, int bg=0, int d=5)
{   	int tt;
	if((b-t)<(r-l))
		tt=((b-t)/2)+1;
	else
		tt=((r-l)/2)+1;
	for(int i=0 ; i<=tt ; i++)
		hbox(t+i,l+i,r-i,b-i,p,c,bg,d);
}

void lcon(char s[],int x, int y,int c ,int bg)
{    	int i,j,k,n;
	textcolor(c);
	textbackground(bg);
	char ch,s2[100];
	for(i=0 ; s[i]!=NULL ; i++)
	{    	ifstream fin("data\\text\\ab.dat");
		while(!fin.eof())
		{    	fin.get(ch);
			if(ch==s[i])
				break;
		}

		for(j=0 ; j<5 ; j++)
		{    	fin.getline(s2,6,'+');
			for(k=0 ; s2[k]!=NULL ;k++)
				if(s2[k]=='*')
					s2[k]='Û';
			gotoxy(x,y+j);
			cprintf(s2);
			delay(5);
		}
		x+=6;
		fin.close();
	 }
}
void mosaic(int c)
{      	textcolor(c);
	int x,y;
	ifstream fin("data\\text\\random.dat");
	for(int i=0 ; i<=10000 ; i++)
	{    fin>>x;  fin>>y;
		gotoxy(x,y);
		cprintf("Û");
	}
	fin.close();
	
	textbackground(c);
	clrscr();
}
