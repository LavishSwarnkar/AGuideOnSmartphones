# A Guide on Smart-phones

## INTRODUCTION
This is my C++ Project made in Turbo C++ and submitted to CBSE in XIIth standard.\
\
"A Guide on Smart-phones" is a MS- DOS Console Application where you can browse smart-phones, their specifications, features, price, etc. Also, you can filter them as per your needs. Export to XLS is also available.\
\
Who says one can't create GUI using Turbo C++? I took inspiration from Turbo C++ IDE itself and some other DOS applications built in Turbo C++. And what I built next is illustrated below.

## FEATURES
* Brief history of smart phones.
* Brief description on some important features of smart phones, viz. OS, Memory, etc.
* Some popular smart phones description.
* Filter Smart phones as required.
* Add more smart phones description.
* Interesting facts on smart phones.

## SCREENSHOTS
![Screenshots](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Screenshots/screenshots.gif)
> You can see more (actually, a lot of) screenshots [here](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Screenshots/README.md)

## MAJOR ATTRACTIONS
* This project purely uses Text mode of Turbo C++. **GRAPHICS MODE IS NOT USED ANYWHERE!**
* The animations are used everywhere : to draw boxes, borders, large text, etc.
* Images are just text shown by Block character
* File handling is used a lot to show data

## BEHIND THE SCENES
### 1. The headings
* The headings are drawn using Text mode only. 
* Each alphabet is represented using a char matrix of size 5x5
* To save this representation in a [file](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Data/Text/ab.dat), each alphabet was then converted to array of size 1x25 and seperated using new line.
![](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Other%20Images/BTS1.png)
* A function `lcon` was created which takes string, coordinates and colors as argument and prints the heading taking care of spacing.
```c
void lcon(char s[],int x, int y,int c ,int bg)
{       int i,j,k,n;
	textcolor(c);
	textbackground(bg);
	char ch,s2[100];
	for(i=0 ; s[i]!=NULL ; i++)
	{       ifstream fin("data\\text\\ab.dat");
		while(!fin.eof())
		{ fin.get(ch);
			if(ch==s[i])
				break;
		}

		for(j=0 ; j<5 ; j++)
		{       fin.getline(s2,6,'+');
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
```
### 2. The images
* You might be thinking the images shown are bitmaps but they are not. They are just text (char matrix) printed using Block character.
![](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Other%20Images/BTS2.png)

### 3. The animations
* Multiple functions were created to draw boxes, fill boxes, draw borders and for other animations. Some of the creations are illustrated below:

.		           |  .
:-------------------------:|:-------------------------:
![](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Other%20Images/GIFs/1.gif)  |  ![](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Other%20Images/GIFs/2.gif)
![](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Other%20Images/GIFs/3.gif)  |  ![](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Other%20Images/GIFs/4.gif)
![](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Other%20Images/GIFs/5.gif)  |  ![](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Other%20Images/GIFs/6.gif)
![](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Other%20Images/GIFs/7.gif)  |  ![](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Other%20Images/GIFs/8.gif)
![](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Other%20Images/GIFs/9.gif)

### 4. The interactive menu
* An interactive menu controlled by arrow keys was created. Asking like "Enter your choice:" is no longer required. Look how cursor changes its position on pressing arrow keys. To select an option user just have to press Enter!

![](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Other%20Images/GIFs/10.gif)

## VIDEO
[![Video](https://github.com/lswarnkar1/AGuideOnSmartphones/blob/master/Other%20Images/VideoThumbnail.png)](http://www.youtube.com/watch?v=M24kpvbXRj8 "A Guide on Smartphones - C++ Project - XIIth CBSE")

## MORE INFO COMING SOON...
