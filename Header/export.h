void exprec()
{    mi m;
      ofstream fout("data.xls");
      ifstream fin("data\\text\\mobinfo.dat",ios::binary);
    fout<<"COMPANY NAME"<<"\t"<<"MOBILE NAME"<<"\t"<<"PROCESSOR NAME"<<"\t"<<"OS NAME"<<"\t"<<"OS VERSION"<<"\t"<<"SENSORS"<<"\t"<<"YEAR OF LAUNCH"<<"\t"<<"BATTERY"<<"\t"<<"PRICE ON AMAZON"<<"\t"<<",EBAY"<<"\t"<<",SNAPDEAL"<<"\t"<<",FLIPKART OR MI SHOP (IN RS )"<<"\t"<<"LENGTH,"<<"\t"<<"BREADTH AND"<<"\t"<<"WIDTH (IN mm)"<<"\t"<<"WEIGHT (IN GRAMS)"<<"\t"<<"CAMERA (REAR),"<<"\t"<<"(FRONT) (IN MPs)"<<"\t"<<"MEMORY (ROM),"<<"\t"<<"(RAM)"<<"\t"<<"NETWORK GENRATION"<<"\t";
    while(!fin.eof())
     { if(fin.eof()) break;
      fin.read( (char*) &m, sizeof(m) );
      fout<<"\n"<<m.cname<<"\t"<<m.mobnm<<"\t"<<m.pro<<"\t"<<m.os<<"\t"<<m.osver<<"\t"<<m.sensors<<"\t"<<m.year<<"\t"<<m.battery<<"\t";
      for(int i=0 ; i<4 ; i++)
     {
       
       fout<<m.price[i];
       if(m.price[i]>0) fout<<",000";
       fout<<"\t";
      
     }
      
      fout<<m.dim[0]<<"\t"<<m.dim[1]<<"\t"<<m.dim[2]<<"\t"<<m.weight<<"\t"<<m.cam[0]<<"\t"<<m.cam[1];
      for(i=0 ; i<2 ; i++)
      {   if(m.mem[i]<0)
          {   m.mem[i]*=-1;
              fout<<m.mem[i]<<" MBs"<<"\t";
          }
      	   else
      	       fout<<m.mem[i]<<" GBs"<<"\t";
      }
      fout<<m.net<<" G"<<"\t";
      }
	    fin.close();
	    fout.close();
	    ptext("data\\text\\expguide.dat",14,9,7);
	getch();
	  }