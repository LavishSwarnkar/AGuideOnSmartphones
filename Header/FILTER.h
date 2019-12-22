int* fbycnm(int a[])
{      	mi m;
	int b[15],i=0,ch,j=0;
	char nm[20][20],s[30];
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22);cprintf("ENTER COMPANY'S NAME:                          "); gotoxy(26,22); gets(s);
	if(a[0]==10)
	{ 	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
		while(!fin.eof())
		{	if(fin.eof())
			break;
			fin.read( (char*) &m, sizeof(m) );
			if(strcmp(s,m.cname)==0)
			{ 	int l=-sizeof(m);
				b[i]=fin.tellg()+l;i++;
			}
		}
		fin.close();
	}
	else
	{  	for(j=0;a[j]!=10;j++)
		{	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
			fin.seekg(a[i]);
			fin.read( (char*) &m, sizeof(m) );
			if(strcmp(s,m.cname)==0)
			{  	b[i]=fin.tellg()-sizeof(m); i++; 	}
			fin.close();
		}
	}
	b[i]=10;
	return b;
}
int* fbypro(int a[])
{      	mi m;
	int b[150],i=0,ch;
	char nm[20][20],s[30];
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22); cprintf("ENTER PROCESSOR'S NAME:                          "); gotoxy(28,22); gets(s);
	int j=0;
	if(a[0]==10)
	{ 	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
		while(!fin.eof())
		{	if(fin.eof()) break;
			fin.read( (char*) &m, sizeof(m) );
			if(strcmp(s,m.pro)==0)
			{  b[j]=fin.tellg()-sizeof(m);  j++;}
		}
		fin.close();
	}
	else
	{  	for(i=0;a[i]!=10;i++)
		{	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
			fin.seekg(a[i]);
			fin.read( (char*) &m, sizeof(m) );
			if(strcmp(s,m.pro)==0)
			{   b[j]=fin.tellg()-sizeof(m);j++; }
		fin.close();
		}
	}
	b[j]=10;
	return b;
}
int* fbyos(int a[])
{      	mi m;
	int b[150],i=0,ch;
	float v; int j;
	char nm[20][20],s[30],k='1';
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22); 	cprintf("ENTER OPERATING SYSTEM'S NAME:                          "); gotoxy(36,22); gets(s);
	gotoxy(4,22); 	cprintf("ENTER OPERATING SYSTEM'S VERSION:                          "); gotoxy(38,22); cin>>v;
	gotoxy(36,22); gotoxy(4,22); 	cprintf("ENTER OS VERSION'S NO. (0 FOR SAME,1 FOR GREATER AND 2 FOR LESSER):     "); gotoxy(73,22); k=getch();

	if(a[0]==10)
	{ 	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
		while(!fin.eof())
		{	if(fin.eof()) break;
			fin.read( (char*) &m, sizeof(m) );
			if(k=='0')
			{ 	if(strcmp(s,m.os)==0&&m.osver==v)
				{  	b[i]=fin.tellg()-sizeof(m); i++; }
			}
			if(k=='2')
			{ 	if(strcmp(s,m.os)==0&&m.osver<=v)
				{  	b[i]=fin.tellg()-sizeof(m); i++; }
			}
			if(k=='1')
			{ 	if(strcmp(s,m.os)==0&&m.osver>=v)
				{  	b[i]=fin.tellg()-sizeof(m); i++; }
			}
		}
		fin.close();
	}
	else
	{  	i=0;
		for(int j=0;a[j]!=10;j++)
		{	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
			fin.seekg(a[j]);
			fin.read( (char*) &m, sizeof(m) );
			if(k=='0')
			{ 	if(strcmp(s,m.os)==0&&m.osver==v)
				{  	b[i]=fin.tellg()-sizeof(m); i++; }
			}
			if(k=='2')
			{ 	if(strcmp(s,m.os)==0&&m.osver<=v)
				{  	b[i]=fin.tellg()-sizeof(m); i++; }
			}
			if(k=='1')
			{ 	if(strcmp(s,m.os)==0&&m.osver>=v)
				{  	b[i]=fin.tellg()-sizeof(m); i++; }
			}
			fin.close();
		}
	}
	b[i]=10;
	return b;
}
int* fbycam(int a[])
{      	mi m;
	int b[150],i=0,ch,rl,ru,fl,fu;
	char nm[20][20],s[30];
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22); 	cprintf("ENTER REAR CAMERA'S LOWER LIMIT:                          ");  gotoxy(37,22); cin>>rl;
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22);
	cprintf("ENTER REAR CAMERA'S UPPER LIMIT:                          "); gotoxy(37,22); cin>>ru;
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22); 	 cprintf("ENTER FRONT CAMERA'S LOWER LIMIT:                          "); gotoxy(38,22); 	 cin>>fl;
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22); cprintf("ENTER FRONT CAMERA'S UPPER LIMIT:                          "); gotoxy(38,22); cin>>fu;
	int j=0;
	if(a[0]==10)
	{ 	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
		while(!fin.eof())
		{	if(fin.eof()) break;
			fin.read( (char*) &m, sizeof(m) );
			if((m.cam[0]>=rl&&m.cam[0]<=ru)&& (m.cam[1]>=fl&&m.cam[1]<=fu) )
			{  	b[j]=fin.tellg()-sizeof(m);  j++;}
		}
		fin.close();
	}
	else
	{ 	for(i=0;a[i]!=10;i++)
		{	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
			fin.seekg(a[i]);
			fin.read( (char*) &m, sizeof(m) );
			if((m.cam[0]>=rl&&m.cam[0]<=ru)&& (m.cam[1]>=fl&&m.cam[1]<=fu) )
			{ b[j]=fin.tellg()-sizeof(m); j++;}
			fin.close();
		}
	}
	b[j]=10;
	return b;
}
int* fbymem(int a[])
{      	mi m;
	int b[150],i=0,ch,rl,ru,fl,fu,j=0;
	char nm[20][20],s[30];
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22); cprintf("ENTER ROM'S LOWER LIMIT:                          "); gotoxy(29,22); cin>>rl;
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22); 	 cprintf("ENTER ROM'S UPPER LIMIT:                          ");  gotoxy(29,22); cin>>ru;
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22); 	 cprintf("ENTER RAM'S LOWER LIMIT:                          "); gotoxy(29,22); cin>>fl;
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22); 	 cprintf("ENTER RAM'S UPPER LIMIT:                          ");    gotoxy(29,22); cin>>fu;
	if(a[0]==10)
	{ 	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
		while(!fin.eof())
		{	if(fin.eof()) break;
			fin.read( (char*) &m, sizeof(m) );
			if((m.mem[0]>=rl&&m.mem[0]<=ru)&& (m.mem[1]>=fl&&m.mem[1]<=fu) )
			{  	b[j]=fin.tellg()-sizeof(m);  j++;}
		}
		fin.close();
	}
	else
	{  	for(i=0;a[i]!=10;i++)
		{	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
			fin.seekg(a[i]);
			fin.read( (char*) &m, sizeof(m) );
			if((m.mem[0]>=rl&&m.mem[0]<=ru)&& (m.mem[1]>=fl&&m.mem[1]<=fu) )
			{	b[j]=fin.tellg()-sizeof(m); j++;}
			fin.close();
		}
	}
	b[j]=10;
	return b;
}
int* fbypr(int a[])
{      	mi m;
	int b[150],i=0,ch,j=0,mpr=0,k=0;
	unsigned long rl,ru;
	char nm[20][20],s[30];
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22);
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22); 	 cprintf("ENTER PRICE'S LOWER LIMIT:                          "); gotoxy(31,22); cin>>rl;
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22);
	cprintf("ENTER PRICE'S UPPER LIMIT:                          "); gotoxy(31,22); cin>>ru;
	ru/=1000;
	rl/=1000;
	if(a[0]==10)
	{ 	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
		while(!fin.eof())
		{	if(fin.eof()) break;
			fin.read( (char*) &m, sizeof(m) );
			for(j=0;j<4;j++)
			{	if(m.price[j]!=0)
				mpr=m.price[j];
			}
			if((mpr>=rl&&mpr<=ru) )
			{  b[k]=fin.tellg()-sizeof(m);  k++;}
		}
		fin.close();
	}
	else
	{  	for(i=0;a[i]!=10;i++)
		{	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
			fin.seekg(a[i]);
			fin.read( (char*) &m, sizeof(m) );
			for(j=0;j<4;j++)
			{	if(m.price[j]!=0)
					mpr=m.price[j];
			}
			if((mpr>=rl&&mpr<=ru) )
			{	b[k]=fin.tellg()-sizeof(m); k++;}
			fin.close();
		}
	}
	b[k]=10;
	return b;
}
int* fbynet(int a[])
{      	mi m;
	int b[150],i=0,ch,rl,ru,j=0;
	char nm[20][20],s[30];
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22);
	cprintf("ENTER NETWORK'S GENERATION:                          "); gotoxy(32,22); cin>>rl;
	if(a[0]==10)
	{ 	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
		while(!fin.eof())
		{	if(fin.eof()) break;
			fin.read( (char*) &m, sizeof(m) );
			if(m.net==rl)
			{  	b[j]=fin.tellg()-sizeof(m);  j++;}
		}
		fin.close();
	}
	else
	{  	for(i=0;a[i]!=10;i++)
		{	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
			fin.seekg(a[i]);
			fin.read( (char*) &m, sizeof(m) );
			if(m.net==rl)
			{ 	b[j]=fin.tellg()-sizeof(m); j++;}
			fin.close();
		}
	}
	b[j]=10;
	return b;
}
int* fbybat(int a[])
{      	mi m;
	int b[150],i=0,ch,rl,ru,j=0;
	char nm[20][20],s[30];
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22);
	cprintf("ENTER BATTERY'S LOWER CAPACITY:                          "); gotoxy(36,22); cin>>rl;
	gotoxy(4,22); cprintf("ENTER BATTERY'S UPPER CAPACITY:                          "); gotoxy(36,22); cin>>ru;
	if(a[0]==10)
	{ 	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
		while(!fin.eof())
		{	if(fin.eof()) break;
			fin.read( (char*) &m, sizeof(m) );
			if(m.battery>=rl&&m.battery<=ru)
			{  	b[j]=fin.tellg()-sizeof(m);  j++;}
		}
		fin.close();
	}
	else
	{  	for(i=0;a[i]!=10;i++)
		{	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
			fin.seekg(a[i]);
			fin.read( (char*) &m, sizeof(m) );
			if(m.battery>=rl&&m.battery<=ru)
			{ 	b[j]=fin.tellg()-sizeof(m); j++;}
			fin.close();
		}
	}
	b[j]=10;
	return b;
}
int* fbyyear(int a[])
{      	mi m;
	int b[150],i=0,ch,rl,ru,j=0;
	char nm[20][20],s[30];
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	gotoxy(4,22);
	cprintf("ENTER YEAR OF LAUNCH:                          "); gotoxy(26,22); cin>>rl;
	if(a[0]==10)
	{ 	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
		while(!fin.eof())
		{	if(fin.eof()) break;
			fin.read( (char*) &m, sizeof(m) );
			if(m.year==rl)
			{  	b[j]=fin.tellg()-sizeof(m);  j++;}
		}
		fin.close();
	}
	else
	{	for(i=0;a[i]!=10;i++)
		{	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
			fin.seekg(a[i]);
			fin.read( (char*) &m, sizeof(m) );
			if(m.year==rl)
			{   	b[j]=fin.tellg()-sizeof(m);
				j++;
			}
			fin.close();
		}
	}
	b[j]=10;
	return b;
}
int* fbysens(int a[])
{      	mi m;
	int b[150],i=0,ch,j=0;
	char nm[20][20],s[30];
	fbox(22,3,78,23,"Û",7,0,0);
	textcolor(0); textbackground(15);
	if(a[0]==10)
	{ 	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
		while(!fin.eof())
		{	if(fin.eof()) break;
			fin.read( (char*) &m, sizeof(m) );
			if(strcmp(m.sensors,"FINGERPRINT AND COMMON")==0)
			{  	b[j]=fin.tellg()-sizeof(m);  j++;}
		}
		fin.close();
	}
	else
	{  	for(i=0;a[i]!=10;i++)
		{	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
			fin.seekg(a[i]);
			fin.read( (char*) &m, sizeof(m) );
			if(strcmp(m.sensors,"FINGERPRINT AND COMMON")==0)
			{ 	b[j]=fin.tellg()-sizeof(m); j++;}
			fin.close();
		}
	}
	b[j]=10;
	return b;
}
