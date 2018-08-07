struct mi
{	char cname[40],mobnm[40],pro[40],os[40],sensors[40];
	int year,battery,price[5],dim[3],weight,cam[2],mem[2],net;
	float osver;
};
void input(mi &m)
{      	int i;
	textcolor(15); textbackground(14);
	gotoxy(12,12);
	cprintf("Enter Company's Name:               ");
	gotoxy(34,12); gets(m.cname);
	gotoxy(12,13);
	cprintf("Enter Mobile's Name:                            ");
	gotoxy(33,13); gets(m.mobnm);
	gotoxy(12,14);
	gotoxy(12,13);
	cprintf("Enter Mobile's Year:                           ");
	gotoxy(33,13); cin>>m.year;
	gotoxy(12,14);
	cprintf("Enter Processor's Name:                                   ");
	gotoxy(36,14); gets(m.pro);
	gotoxy(12,15);
	cprintf("Enter Operating System's Name:                              ");
	gotoxy(43,15); gets(m.os);
	gotoxy(12,15); cprintf("Enter Operating System's Version:                    ");
	gotoxy(45,15); cin>>m.osver;
	gotoxy(12,16);
	cprintf("Enter Weight(in grams):               ");
	gotoxy(36,16); cin>>m.weight;
	gotoxy(12,17);
	cprintf("Enter Size in order (L,B,H) (in mm):        ");
	gotoxy(49,17);cin>>m.dim[0];
	gotoxy(12,17);
	cprintf("Enter Size in order (L,B,H):                   ");
	gotoxy(41,17);cin>>m.dim[1];
	gotoxy(12,17);
	cprintf("Enter Size in order (L,B,H):                    ");
	gotoxy(41,17);cin>>m.dim[2];
	gotoxy(12,18);
	unsigned long p,p2,p3,p4;
	cprintf("Enter Price in order (A,E,SD,MI/FK) :              ");
	gotoxy(50,18); cin>>p;
	gotoxy(12,18);
	cprintf("Enter Price in order (A,E,SD,MI/FK):                        ");
	gotoxy(50,18); cin>>p2;
	gotoxy(12,18);
	cprintf("Enter Price in order (A,E,SD,MI/FK):                         ");
	gotoxy(50,18); cin>>p3;
	gotoxy(12,18);
	cprintf("Enter Price in order (A,E,SD,MI/FK):                        ");
	gotoxy(50,18); cin>>p4;
	p/=1000; p2/=1000;
	p3/=1000; p4/=1000;
	m.price[0]=p;
	m.price[1]=p2;
	m.price[2]=p3;
	m.price[3]=p4;
	m.price[4]=(m.price[0]+m.price[1]+m.price[2]+m.price[3])/4;
	gotoxy(12,19);
	cprintf("Enter Camera in order (Rear,Front) (Leave 0, if not available):   ");
	gotoxy(75,19); cin>>m.cam[0];
	gotoxy(12,19);
	cprintf("Enter Camera in order (Rear,Front) (Leave 0, if not available):   ");
	gotoxy(75,19); cin>>m.cam[1];
	gotoxy(12,20);
	cprintf("Enter Memory in order (ROM,RAM) (In GBs/MBs):        ");
	gotoxy(58,20);cin>>m.mem[0];
	gotoxy(12,20);
	cprintf("Enter Memory in order (ROM,RAM) (In GBs/MBs):        ");
	gotoxy(58,20);cin>>m.mem[1];
	gotoxy(12,21);
	cprintf("Enter Battery Capacity (in mAh):            ");
	gotoxy(45,21); cin>>m.battery;
	gotoxy(12,22);
	cprintf("Enter specific Sensors (if any):                       ");
	gotoxy(45,22); gets(m.sensors);
	gotoxy(12,23);
	if(strcmp(m.sensors,"Y")==0) strcpy(m.sensors,"FINGERPRINT AND COMMON");
	if(strcmp(m.sensors,"N")==0) strcpy(m.sensors,"COMMON");
	cprintf("Enter Network Type (Eg.4 for 4G):          ");
	gotoxy(46,23);
	cin>>m.net;
}
void print(mi m)
{	textcolor(15); textbackground(0);
	clrscr();
	hbox(2,2,79,24,"Û",7,1,0);
	int l=strlen(m.mobnm);
	l=(80-l)/2; textcolor(15); textbackground(0);
	gotoxy(l,5); cprintf(m.mobnm);
	gotoxy(32,6); cprintf("BROUGHT TO YOU BY");
	l=strlen(m.cname); l=(72-l)/2;
	gotoxy(l,7); cprintf(m.cname); cprintf(" IN "); cout<<m.year;
	gotoxy(5,9); cprintf(">> PROCESSOR: ");     cprintf(m.pro);
	gotoxy(5,10); cprintf(">> OPERATING SYSTEM: ");     cprintf(m.os); cprintf(" ");
	cout<<m.osver;
	if(strcmp(m.os,"ANDROID")==0)
	{  	if(m.osver==4) cprintf(" JELLY BEAN / KITKAT");
		else if(m.osver==5) cprintf(" LOLLIPOP");
		else if(m.osver==6) cprintf(" MARSHMALLOW");
		else if(m.osver==7) cprintf(" NOUGHAT");
	}

	gotoxy(5,11); cprintf(">> BODY: ");
	gotoxy(13,12); cprintf(">> SIZE (L,B,H):                    ");
	gotoxy(30,12); cout<<m.dim[0]<<", " <<m.dim[1]<<", "<<m.dim[2]<<" mm";
	gotoxy(13,13); cprintf(">> WEIGHT:                    ");
	gotoxy(24,13); cout<<m.weight<<" Grams";
	gotoxy(5,14); cprintf(">> STORAGE: ");
	gotoxy(16,15); cprintf(">> ROM:                    ");
	gotoxy(24,15); cout<<m.mem[0]<<" GB";
	gotoxy(16,16); cprintf(">> RAM:                    ");
	if(m.mem[1]<0)
	{ 	m.mem[1]*=-1;
		gotoxy(24,16); cout<<m.mem[1]<<" MB";
	}
	else
	{   	gotoxy(24,16); cout<<m.mem[1]<<" GB"; }
		gotoxy(5,17); cprintf(">> CAMERA: ");
		gotoxy(16,17); cprintf(">> REAR:                    ");

		if(m.cam[0]==0)
		{ gotoxy(26,17); cout<<"NONE"; }

		else
		{ gotoxy(26,17); cout<<m.cam[0]<<" MPs"; }

		gotoxy(16,18); cprintf(">> FRONT:                    ");

		if(m.cam[1]==0)
		{ gotoxy(27,18); cout<<"NONE OR VGA"; }

		else
		{ gotoxy(27,18); cout<<m.cam[1]<<" MPs"; }

		gotoxy(5,19);
		cprintf(">> PRICE (A,E,SD,MI/FK)(0-NA):                        "); gotoxy(36,19);

		unsigned long p,p2,p3,p4;

		p=m.price[0] ;
		p2=m.price[1] ;
		p3=m.price[2] ;
		p4=m.price[3] ;
		p*=1000 ;
		p2*=1000;
		p3*=1000 ;
		p4*=1000;
		cout<<p<<" , "<<p2<<" , "<<p3<<" , "<<p4<<" Rupees"<<endl;

		gotoxy(5,20);
		cprintf(">> BATTERY:        ");
		gotoxy(17,20);
		cout<<m.battery<<" mAh"<<endl;
		gotoxy(5,21);
		cprintf(">> SPECIFIC SENSORS: ");
		gotoxy(26,21);
		cprintf(m.sensors);
		gotoxy(5,22);
		cprintf(">> NETWORK:         ");
		gotoxy(17,22);
		cout<<m.net; cprintf(" G");
		getch();
		textbackground(1); clrscr();
}
void read(char s[])
{
 mi m;
  int a[150],i=0,ch=0;
  char nm[150][30], cnm[150][30] ;
  strupr(s);
	ifstream fin("data\\text\\mobinfo.dat",ios::binary);

	while(!fin.eof())
	{	if(fin.eof()) break;
		fin.read( (char*) &m, sizeof(m) );

		if(strcmp(s,"OTHER")==0)
		{ 	if(strcmp(m.cname,"APPLE")!=0&& strcmp(m.cname,"ASUS")!=0&& strcmp(m.cname,"BLACKBERRY")!=0&& strcmp(m.cname,"HTC")!=0&&   strcmp(m.cname,"GIONEE")!=0&& strcmp(m.cname,"Le ECO")!=0&& strcmp(m.cname,"LENOVO")!=0&& strcmp(m.cname,"LG")!=0&&  strcmp(m.cname,"MICROMAX")!=0&& strcmp(m.cname,"MICROSOFT")!=0&& strcmp(m.cname,"ONEPLUS")!=0&& strcmp(m.cname,"OPPO")!=0&&   strcmp(m.cname,"SAMSUNG")!=0&& strcmp(m.cname,"SONY")!=0&& strcmp(m.cname,"XIAOMI")!=0)
			{	a[i]=fin.tellg()-sizeof(m);
				strcpy(nm[i],m.mobnm);
				strcpy(cnm[i],m.cname);
				i++;
			}
		}

		if(strcmp(s,m.cname)==0)
		{ 	a[i]=fin.tellg()-sizeof(m);
			strcpy(nm[i],m.mobnm);
			i++;
		}

	}
	fin.close();
	if(strcmp(s,"Le ECO")==0) strcpy(s,"LEECO");
	int t=i;
	a[i]=10;
	s=strlwr(s);
	while(1)
	{	int l=strlen(s);
		l=(80-((l*5)+l-1))/2;
		fbox(2,2,79,24,"Û",7,1,0);
		hbox(2,2,79,24,"Û",15,0,0);
		lcon(s,l,4,0,15);
		fbox(11,3,78,20,"Û",0,1,0);
		fbox(21,3,78,23,"Û",7,1,0);
		if(t==0)
		{ 	textcolor(15); textbackground(0);
			gotoxy(5,12); cprintf("SORRY! NO SMART PHONES IN THIS CATEGORY. PRESS ANY KEY TO RETURN BACK");
			getch(); return;
		}
		textcolor(15); textbackground(0);
		if(strcmp(s,"other")==0)
		{	for(i=0 ; a[i]!=10 ; i++)
			{	if(i>7)
				{	gotoxy(35,4+i);
					cprintf("                     ");
					gotoxy(35,4+i); cout<<i+1;
					cprintf(".) "); cprintf(cnm[i]);cprintf(" "); cprintf(nm[i]);
				}
				else
				{ 	gotoxy(5,12+i);
					cprintf("                     ");
					gotoxy(5,12+i); cout<<i+1;
					cprintf(".) "); cprintf(cnm[i]);cprintf(" "); cprintf(nm[i]);
				}
			}
		}

		else
		{	for(i=0 ; a[i]!=10 ; i++)
			{	if(i>7)
				{     	gotoxy(35,4+i);
					cprintf("                     ");
					gotoxy(35,4+i); cout<<i+1;
					cprintf(".) "); cprintf(nm[i]);
				}
				else
				{ 	gotoxy(5,12+i);
					cprintf("                     ");
					gotoxy(5,12+i); cout<<i+1;
					cprintf(".) "); cprintf(nm[i]);
				}
			}
		}
		textcolor(0); textbackground(15);
		gotoxy(15,22); cprintf(">> ENTER YOUR CHOICE (0 for back):       ");
		gotoxy(51,22); cin>>ch;
		if(ch>=1&&ch<=(i))
		{   	fin.open("data\\text\\mobinfo.dat",ios::binary);
			fin.seekg(a[ch-1]);
			fin.read( (char*) &m, sizeof(m) );
			print(m); fin.close();
		}
		else if(ch==0) return;
		else
		{ 	gotoxy(15,22);
			cprintf("OOPS! WRONG CHOICE ! TRY AGAIN BY PRESSING ANY KEY.       ");
			getch();
		}
	}
}

void addrec()
{    	fbox(3,3,78,23,"Û",6,1);
	fbox(3,3,78,10,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("add",18,4,10,6);
	lcon("data",40,4,10,6);
	mi m;
	ptext("data\\text\\addguide.dat",14,7,14);
	getch();
	fbox(12,3,78,23,"Û",6,1,0);
	ofstream fout("data\\text\\mobinfo.dat",ios::binary|ios::app);
	input(m);
	fout.write( (char*) &m, sizeof(m) );
	fbox(12,3,78,23,"Û",6,1,0);
	textcolor(14); textbackground(14);
	gotoxy(25,19);
	cprintf("\nMobile Info added successfully");
	fout.close();
	getch();
	return;
}
void modrec()
{    	fbox(3,3,78,23,"Û",6,1);
	fbox(3,3,78,10,"Û",6,1);
	hbox(2,2,79,10,"Û",14,1);
	lcon("modify",8,4,10,6);
	lcon("data",50,4,10,6);
	ptext("data\\text\\modguide.dat",14,7,14);
	getch(); fbox(12,3,78,23,"Û",6,1,0);
	fstream file("data\\text\\mobinfo.dat",ios::in|ios::out|ios::binary);
	mi m,m2;
	input(m2);
	while(!file.eof())
	{   	file.read( (char*) &m, sizeof(m) );
		if(strcmp(m.mobnm,m2.mobnm)==0)
		{	if(strcmp(m2.cname,".")==0)
				strcpy(m2.cname,m.cname);
			if(strcmp(m2.pro,".")==0)
				strcpy(m2.pro,m.pro);
			if(strcmp(m2.os,".")==0)
				strcpy(m2.os,m.os);
			if(strcmp(m2.sensors,".")==0)
				strcpy(m2.sensors,m.sensors);
			if(m2.battery==0)
				m2.battery=m.battery;
			if(m2.price[0]==0)
				m2.price[0]=m.price[0];
			if(m2.price[1]==0)
				m2.price[1]=m.price[1];
			if(m2.price[2]==0)
				m2.price[2]=m.price[2];
			if(m2.price[3]==0)
				m2.price[3]=m.price[3];
			if(m2.price[4]==0)
				m2.price[4]=m.price[4];
			if(m2.dim[0]==0)
				m2.dim[0]=m.dim[0];
			if(m2.dim[1]==0)
				m2.dim[1]=m.dim[1];
			if(m2.dim[2]==0)
				m2.dim[2]=m.dim[2];
			if(m2.cam[0]==0)
				m2.cam[0]=m.cam[0];
			if(m2.cam[1]==0)
				m2.cam[1]=m.cam[1];
			if(m2.mem[0]==0)
				m2.mem[0]=m.mem[0];
			if(m2.mem[1]==0)
				m2.mem[1]=m.mem[1];
			if(m2.weight==0)
				m2.weight=m.weight;
			if(m2.net==0)
				m2.net=m.net;
			if(m2.osver==0)
				m2.osver=m.osver;
			if(m2.year==0)
				m2.year=m.year;
			int l=-sizeof(m);
			file.seekg(l,ios::cur);
			file.write( (char*) &m2, sizeof(m2) );
			fbox(12,3,78,23,"Û",6,1,0);
			textcolor(14); textbackground(14);
			gotoxy(25,19);
			cprintf("\nMobile Info modified successfully...");
			getch();
			file.close();
			return;
		}
	}
	fbox(12,3,78,23,"Û",6,1,0);
	textcolor(14); textbackground(14);
	gotoxy(33,19);
	cprintf("MOBILE NOT FOUND");
	file.close();
	getch();
	return;
}

void readno(int a[])
{	mi m;
	int i=0,ch;
	char nm[150][30],cnm[150][30];
	for(i=0;a[i]!=10;i++)
	{ 	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
		fin.seekg(a[i]);
		fin.read( (char*) &m, sizeof(m) );
		strcpy(nm[i],m.mobnm);
		strcpy(cnm[i],m.cname);
		fin.close();
	}
	while(1)
	{	fbox(2,2,79,24,"Û",7,1,0);
		hbox(2,2,79,24,"Û",15,0,0);
		lcon("filter",23,4,0,15);
		fbox(11,3,78,20,"Û",0,1,0);
		fbox(21,3,78,23,"Û",7,1,0);
		textcolor(15); textbackground(0);
		for(i=0 ; a[i]!=10 ; i++)
		{ 	if(i>15)
			{ 	textcolor(0); textbackground(15);
				gotoxy(15,22);
				cprintf("OOPS! SO MANY MOBILES IN FILTERING. PLEASE APPLY MORE.");
				getch(); return;
			}
		if(i>7)
		{	gotoxy(35,4+i);
			cprintf("                     ");
			gotoxy(35,4+i); cout<<i+1;
			cprintf(".) "); cprintf(cnm[i]); cprintf(" "); cprintf(nm[i]);}
			else
			{ 	gotoxy(5,12+i);
				cprintf("                     ");
				gotoxy(5,12+i); cout<<i+1;
				cprintf(".) "); cprintf(cnm[i]); cprintf(" "); cprintf(nm[i]);
			}
		}
		textcolor(0); textbackground(15);
		gotoxy(15,22); cprintf(">> ENTER YOUR CHOICE (0 for back):       "); gotoxy(51,22); cin>>ch;
		if(ch>=1&&ch<=(i))
		{   	ifstream fin("data\\text\\mobinfo.dat",ios::binary);
			fin.seekg(a[ch-1]);
			fin.read( (char*) &m, sizeof(m) );
			print(m); fin.close();
		}
		else if(ch==0) return;
		else
		{ 	gotoxy(15,22);
				cprintf("OOPS! WRONG CHOICE ! TRY AGAIN BY PRESSING ANY KEY.       ");
				getch();
		}
	}
}
