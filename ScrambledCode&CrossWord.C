#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>

void code_magnet();
void java_cross();

void scrambled();
void scrambled1();
void scrambled2();
void scrambled3();
void scrambled4();
void scrambled5();
void scrambled6();
void scrambled7();
void scrambled8();
void scrambled9();

void workspace(int,int,int,int);

int s1=0,a1=0,s2=0,a2=0,s3=0,a3=0,s4=0,a4=0,s5=0,a5=0,s6=0,a6=0,s7=0,a7=0;
int quit=1;

void drawCross();
void wFile(int no);
void rFile();
int vFile(int no);

int get_key()
{
   union REGS i,o;
 
   i.h.ah = 0;
   int86(22,&i,&o);
 
   return ( o.h.ah );
}

void fillBox(int no,int bno[15][3],char *bname[15]);
void auto_fill(int no);
void fill(int no,int bno[15][3],char *bname[15]);

FILE *fp;
int bno,i,size[22],nfilled=0,filled[22],tp,flag=0,ans,key;

int b0[6][3],b1[5][3],b2[7][3],b3[5][3],b4[7][3];
int b5[5][3],b6[6][3],b7[7][3],b8[3][3],b9[9][3];
int b10[9][3],b11[4][3],b12[3][3],b13[15][3],b14[7][3];
int b15[5][3],b16[6][3],b17[7][3],b18[8][3],b19[4][3],b20[8][3];

char *name0[6],*name1[5],*name2[7],*name3[5],*name4[7];
char *name5[5],*name6[6],*name7[7],*name8[3],*name9[9];
char *name10[9],*name11[4],*name12[3],*name13[15],*name14[7];
char *name15[5],*name16[7],*name17[7],*name18[8],*name19[4];
char *name20[8],*name[22],*temp[23];

void main()
{
	int req;

	int gd=DETECT,gm=0;
	initgraph(&gd,&gm,"D:\\tc\\bgi");

      /*	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,10);
	setcolor(BLUE);
	outtextxy(200,100,"EduTainment");
	outtextxy(150,300,"The place to learn Java with fun");
	setbkcolor(WHITE);

	delay(20);   */

	printf("Enter 1 for Code magnet : \nEnter 2 for JavaCross : ");
		scanf("%d",&req);
	if(req==1)
		code_magnet();
	else if(req==2)
		java_cross();
	getch();
}

void code_magnet()
{
	double x,y,x1,y1,r;
	int gd=DETECT,gm=0;
	union REGS i,o;
	initgraph(&gd,&gm,"D:\\tc\\bgi");

	settextstyle(2,HORIZ_DIR,5);

	scrambled();
	scrambled1();
	scrambled2();
	scrambled3();
	scrambled4();
	scrambled5();
	scrambled6();
	scrambled7();
	scrambled8();
	scrambled9();

	i.x.ax=1; //to display mouse pointer or not 0=init,1=display mouse ,2=no
	int86(0x33,&i,&o);
	while(!kbhit())
	{
		i.x.ax = 3;//for moving mouse
		int86(0x33,&i,&o);
		if(o.x.bx==1)
		{
			x=o.x.cx;
			y=o.x.dx;

			while( o.x.bx == 1)
			{
				i.x.ax = 3;
				int86(0x33,&i,&o);
				x1 = o.x.cx;
				y1 = o.x.dx;
			      //	cleardevice();

				setcolor(10);
				workspace(x,y,x1,y1);
			}
			//	line(x,y,x1,y1);
		}
	}
 getch();
}
void scrambled()
{
	rectangle(5,5,635,475);// border

	rectangle(15,15,295,465);
	line(315,5,315,475);   // seperators
	line(325,5,325,475);

	line(15,63,295,63);
	line(15,83,295,83);
	line(15,103,295,103);
	line(15,163,295,163);
	line(15,203,295,203);
	line(15,263,295,263);
	line(15,343,295,343);
	line(15,363,295,363);
	line(15,383,295,383);
	line(15,405,295,405);
	line(15,407,295,407);

	outtextxy(20,410,"Arrange the given code");
	outtextxy(20,430,"bocks in order to get");
	outtextxy(20,450,"the given output");

	line(193,407,193,465);
	line(195,407,195,465);

	outtextxy(200,415,"Output : ");
	outtextxy(220,435,"a-b c-d");
}

void scrambled1()
{
	rectangle(345,15,620,85);         // 325+20

	outtextxy(350,20,"if(x == 1) { ");
	outtextxy(350,35,"   System.out.print(''d'');");
	outtextxy(350,50,"   x = x - 1; ");
	outtextxy(350,65,"}");
}

void scrambled2()
{
	rectangle(345,95,620,150);

	outtextxy(350,100,"if(x == 2) { ");
	outtextxy(350,115,"   System.out.print(''b c'');");
	outtextxy(350,130,"}");
}

void scrambled3()
{
	rectangle(345,160,620,210);

	outtextxy(350,170,"class shuffle {");
	outtextxy(350,185," public static void main(String[] a){");
}

void scrambled4()
{
	rectangle(345,220,620,280);

	outtextxy(350,230,"if(x > 2) {");
	outtextxy(350,245,"   System.out.print(''a'');");
	outtextxy(350,260,"}");
}
void scrambled5()
{
	rectangle(345,290,620,325);

	outtextxy(350,300,"int x=3;");
}
void scrambled6()
{
	rectangle(345,335,620,385);

	outtextxy(350,345,"x= x - 1;");
	outtextxy(350,360,"System.out.print(''-'');");
}
void scrambled7()
{
	rectangle(345,395,620,430);

	outtextxy(350,405,"while ( x > 0 ) {");
}
void scrambled8()
{
	rectangle(345,440,425,465);
	outtextxy(375,445," { ");

	rectangle(445,440,525,465);
	outtextxy(475,445," } ");
}
void scrambled9()
{
	rectangle(545,440,620,465);
	rectangle(547,442,618,463);

	outtextxy(560,445,"MENU");

}
void workspace(int u,int v,int u1,int v1)
{

	if(u>=345 && u<=620 && v>=15 && v<=85)    //s1
	{
		if(u1>15  && u1<295 && v1>265 && v1<345)
		{
			outtextxy(25,265,"  if(x == 1) { ");
			outtextxy(25,285,"     System.out.print(''d'');");
			outtextxy(25,305,"   x = x - 1; ");
			outtextxy(25,325,"  }");
		}
	}
	else if(u>=345 && u<=620 && v>=95 && v<=150)  //s2
	{
		if(u1>15  && u1<295 && v1>205 && v1<265)
		{
			outtextxy(25,205,"  if(x == 2) { ");
			outtextxy(25,225,"     System.out.print(''b c'');");
			outtextxy(25,245,"  }");
		}
	}
	else if(u>=345 && u<=620 && v>=160 && v<=210)
	{
		if(u1>15  && u1<295 && v1>15 && v1<65)
		{
			outtextxy(25,25,"class shuffle {");
			outtextxy(25,45," public static void main(String[] a){");
		}
	}
	else if(u>=345 && u<=620 && v>=220 && v<=280)
	{
		if(u1>15  && u1<295 && v1>105 && v1<130)
		{
			outtextxy(25,105 ,"   if(x > 2) {");
			outtextxy(25,125,"      System.out.print(''a'');");
			outtextxy(25,145,"   }");
		}
	}
	else if(u>=345 && u<=620 && v>=290 && v<=325)
	{
		if(u1>15  && u1<295 && v1>65 && v1<85)
		{
			outtextxy(25,65,"  int x=3;");
		}
	}
	else if(u>=345 && u<=620 && v>=335 && v<=385)
	{
		if(u1>15  && u1<295 && v1>165 && v1<205)
		{
			outtextxy(25,165,"   x= x - 1;");
			outtextxy(25,185,"   System.out.print(''-'');");
		}
	}
	else if(u>=345 && u<=620 && v>=395 && v<=430)
	{
		if(u1>15  && u1<295 && v1>85 && v1<105)
		{
			outtextxy(25,85,"  while ( x > 0 ) {");
		}
	}
    /*	else if(u>=345 && u<=425 && v>=440 && v<=465)
	{
		if(u1>15 && u1<295 && v1>345 && v1<365)
			outtextxy(25,345," {");
	}       */
	else if(u>=445 && u<=525 && v>=440 && v<=465)
	{
		if(u1>15 && u1<295 && v1>345 && v1<365)
			outtextxy(25,345,"   }");
		if(u1>15 && u1<295 && v1>365 && v1<385)
			outtextxy(25,365,"  }");
		if(u1>15 && u1<295 && v1>385 && v1<405)
			outtextxy(25,385," }");
	}
	else if(u>=545 && u<=620 && v>=440 && v<=465)
	{
		if(u>=545 && u<=620 && v>=440 && v<=465)
			quit=0;
	}

}

void java_cross()
{

	int gd=DETECT,gm=0;
       //	int x=0,y=0;
       //	initgraph(&gd,&gm,"c:\\tc\\bgi");

	name0[0]=" F";
	name0[1]=" L";
	name0[2]=" O";
	name0[3]=" A";
	name0[4]=" T";

	name1[0]=" V";
	name1[1]=" O";
	name1[2]=" I";
	name1[3]=" D";

	name2[0]=" P";
	name2[1]=" U";
	name2[2]=" B";
	name2[3]=" L";
	name2[4]=" I";
	name2[5]=" C";

	name3[0]=" J";
	name3[1]=" A";
	name3[2]=" V";
	name3[3]=" A";

	name4[0]=" A";
	name4[1]=" R";
	name4[2]=" R";
	name4[3]=" A";
	name4[4]=" Y";
	name4[5]=" S";

	name5[0]=" L";
	name5[1]=" O";
	name5[2]=" O";
	name5[3]=" P";

	name6[0]=" W";
	name6[1]=" H";
	name6[2]=" I";
	name6[3]=" L";
	name6[4]=" E";

	name7[0]=" B";
	name7[1]=" R";
	name7[2]=" A";
	name7[3]=" N";
	name7[4]=" C";
	name7[5]=" H";

	name8[0]=" D";
	name8[1]=" C";

	name9[0]=" C";
	name9[1]=" O";
	name9[2]=" M";
	name9[3]=" P";
	name9[4]=" I";
	name9[5]=" L";
	name9[6]=" E";
	name9[7]=" R";

	name10[0]=" V";
	name10[1]=" A";
	name10[2]=" R";
	name10[3]=" I";
	name10[4]=" A";
	name10[5]=" B";
	name10[6]=" L";
	name10[7]=" E";

	name11[0]=" I";
	name11[1]=" N";
	name11[2]=" T";

	name12[0]=" I";
	name12[1]=" C";

	name13[0]=" S";
	name13[1]=" Y";
	name13[2]=" S";
	name13[3]=" T";
	name13[4]=" E";
	name13[5]=" M";
	name13[6]=" O";
	name13[7]=" U";
	name13[8]=" T";
	name13[9]=" P";
	name13[10]=" R";
	name13[11]=" I";
	name13[12]=" N";
	name13[13]=" T";

	name14[0]=" S";
	name14[1]=" T";
	name14[2]=" A";
	name14[3]=" T";
	name14[4]=" I";
	name14[5]=" C";

	name15[0]=" M";
	name15[1]=" A";
	name15[2]=" I";
	name15[3]=" N";

	name16[0]=" M";
	name16[1]=" E";
	name16[2]=" T";
	name16[3]=" H";
	name16[4]=" O";
	name16[5]=" D";

	name17[0]=" S";
	name17[1]=" T";
	name17[2]=" R";
	name17[3]=" I";
	name17[4]=" N";
	name17[5]=" G";

	name18[0]=" D";
	name18[1]=" E";
	name18[2]=" C";
	name18[3]=" L";
	name18[4]=" A";
	name18[5]=" R";
	name18[6]=" E";

	name19[0]=" J";
	name19[1]=" V";
	name19[2]=" M";

	name20[0]=" C";
	name20[1]=" O";
	name20[2]=" M";
	name20[3]=" M";
	name20[4]=" A";
	name20[5]=" N";
	name20[6]=" D";

	name[0]="FLOAT";
	name[1]="VOID";
	name[2]="PUBLIC";
	name[3]="JAVA";
	name[4]="ARRAYS";
	name[5]="LOOP";
	name[6]="WHILE";
	name[7]="BRANCH";
	name[8]="DC";
	name[9]="COMPILER";
	name[10]="VARIABLE";
	name[11]="INT";
	name[12]="IC";
	name[13]="SYSTEMOUTPRINT";
	name[14]="STATIC";
	name[15]="MAIN";
	name[16]="METHOD";
	name[17]="STRING";
	name[18]="DECLARE";
	name[19]="JVM";
	name[20]="COMMAND";

	b0[0][0]=185;	b0[0][1]=10;
	b0[1][0]=185;	b0[1][1]=35;
	b0[2][0]=185;	b0[2][1]=60;
	b0[3][0]=185;   b0[3][1]=85;
	b0[4][0]=185;   b0[4][1]=110;

	b1[0][0]=235;	b1[0][1]=10;
	b1[1][0]=235;	b1[1][1]=35;
	b1[2][0]=235;	b1[2][1]=60;
	b1[3][0]=235;   b1[3][1]=85;

	b2[0][0]=385;	b2[0][1]=10;
	b2[1][0]=385;	b2[1][1]=35;
	b2[2][0]=385;	b2[2][1]=60;
	b2[3][0]=385;   b2[3][1]=85;
	b2[4][0]=385;   b2[4][1]=110;
	b2[5][0]=385;   b2[5][1]=135;

	b3[0][0]=10;	b3[0][1]=35;
	b3[1][0]=35;	b3[1][1]=35;
	b3[2][0]=60;	b3[2][1]=35;
	b3[3][0]=85;    b3[3][1]=35;

	b4[0][0]=35;	b4[0][1]=35;
	b4[1][0]=35;	b4[1][1]=60;
	b4[2][0]=35;	b4[2][1]=85;
	b4[3][0]=35;    b4[3][1]=110;
	b4[4][0]=35;    b4[4][1]=135;
	b4[5][0]=35;    b4[5][1]=160;

	b5[0][0]=185;	b5[0][1]=35;
	b5[1][0]=210;	b5[1][1]=35;
	b5[2][0]=235;	b5[2][1]=35;
	b5[3][0]=260;   b5[3][1]=35;

	b6[0][0]=135;	b6[0][1]=60;
	b6[1][0]=135;	b6[1][1]=85;
	b6[2][0]=135;	b6[2][1]=110;
	b6[3][0]=135;   b6[3][1]=135;
	b6[4][0]=135;   b6[4][1]=160;

	b7[0][0]=10;	b7[0][1]=85;
	b7[1][0]=35;	b7[1][1]=85;
	b7[2][0]=60;	b7[2][1]=85;
	b7[3][0]=85;    b7[3][1]=85;
	b7[4][0]=110;	b7[4][1]=85;
	b7[5][0]=135;   b7[5][1]=85;

	b8[0][0]=235;   b8[0][1]=85;
	b8[1][0]=260;   b8[1][1]=85;

	b9[0][0]=260;	b9[0][1]=85;
	b9[1][0]=260;	b9[1][1]=110;
	b9[2][0]=260;	b9[2][1]=135;
	b9[3][0]=260;   b9[3][1]=160;
	b9[4][0]=260;   b9[4][1]=185;
	b9[5][0]=260;   b9[5][1]=210;
	b9[6][0]=260;	b9[6][1]=235;
	b9[7][0]=260;	b9[7][1]=260;

	b10[0][0]=310;	b10[0][1]=85;
	b10[1][0]=310;	b10[1][1]=110;
	b10[2][0]=310;	b10[2][1]=135;
	b10[3][0]=310;  b10[3][1]=160;
	b10[4][0]=310;  b10[4][1]=185;
	b10[5][0]=310;  b10[5][1]=210;
	b10[6][0]=310;	b10[6][1]=235;
	b10[7][0]=310;	b10[7][1]=260;

	b11[0][0]=135;	b11[0][1]=110;
	b11[1][0]=160;	b11[1][1]=110;
	b11[2][0]=185;	b11[2][1]=110;

	b12[0][0]=360;	b12[0][1]=135;
	b12[1][0]=360;	b12[1][1]=160;

	b13[0][0]=35;	b13[0][1]=160;
	b13[1][0]=60;	b13[1][1]=160;
	b13[2][0]=85;	b13[2][1]=160;
	b13[3][0]=110;  b13[3][1]=160;
	b13[4][0]=135;  b13[4][1]=160;
	b13[5][0]=160;  b13[5][1]=160;
	b13[6][0]=185;	b13[6][1]=160;
	b13[7][0]=210;	b13[7][1]=160;
	b13[8][0]=235;	b13[8][1]=160;
	b13[9][0]=260;  b13[9][1]=160;
	b13[10][0]=285; b13[10][1]=160;
	b13[11][0]=310; b13[11][1]=160;
	b13[12][0]=335;	b13[12][1]=160;
	b13[13][0]=360;	b13[13][1]=160;

	b14[0][0]=85;	b14[0][1]=160;
	b14[1][0]=85;	b14[1][1]=185;
	b14[2][0]=85;	b14[2][1]=210;
	b14[3][0]=85;   b14[3][1]=235;
	b14[4][0]=85;   b14[4][1]=260;
	b14[5][0]=85;   b14[5][1]=285;

	b15[0][0]=160;	b15[0][1]=160;
	b15[1][0]=160;	b15[1][1]=185;
	b15[2][0]=160;	b15[2][1]=210;
	b15[3][0]=160;  b15[3][1]=235;
	b15[4][0]=160;  b15[4][1]=260;

	b16[0][0]=385;	b16[0][1]=210;
	b16[1][0]=385;	b16[1][1]=235;
	b16[2][0]=385;	b16[2][1]=260;
	b16[3][0]=385;  b16[3][1]=285;
	b16[4][0]=385;  b16[4][1]=310;
	b16[5][0]=385;  b16[5][1]=335;

	b17[0][0]=60;	b17[0][1]=235;
	b17[1][0]=85;	b17[1][1]=235;
	b17[2][0]=110;	b17[2][1]=235;
	b17[3][0]=135;  b17[3][1]=235;
	b17[4][0]=160;  b17[4][1]=235;
	b17[5][0]=185;  b17[5][1]=235;

	b18[0][0]=235;	b18[0][1]=235;
	b18[1][0]=260;	b18[1][1]=235;
	b18[2][0]=285;	b18[2][1]=235;
	b18[3][0]=310;  b18[3][1]=235;
	b18[4][0]=335;  b18[4][1]=235;
	b18[5][0]=360;  b18[5][1]=235;
	b18[6][0]=385;	b18[6][1]=235;

	b19[0][0]=285;	b19[0][1]=285;
	b19[1][0]=285;	b19[1][1]=310;
	b19[2][0]=285;	b19[2][1]=335;

	b20[0][0]=235;	b20[0][1]=335;
	b20[1][0]=260;	b20[1][1]=335;
	b20[2][0]=285;	b20[2][1]=335;
	b20[3][0]=310;  b20[3][1]=335;
	b20[4][0]=335;  b20[4][1]=335;
	b20[5][0]=360;  b20[5][1]=335;
	b20[6][0]=385;	b20[6][1]=335;

	size[0]=5;	size[10]=8;	size[20]=7;
	size[1]=4;      size[11]=3;
	size[2]=6;      size[12]=2;
	size[3]=4;      size[13]=14;
	size[4]=6;      size[14]=6;
	size[5]=4;      size[15]=4;
	size[6]=5;      size[16]=6;
	size[7]=6;      size[17]=6;
	size[8]=2;      size[18]=7;
	size[9]=8;      size[19]=3;

      /*	x=getmaxx();
		y=getmaxy();

		printf("x: %d \n y: %d ",x,y);

		setbkcolor(WHITE);       */

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	fp=fopen("data.txt","w");

	do{

       //	cleardevice();
	initgraph(&gd,&gm,"d:\\tc\\bgi");
       //	clrscr();
       //	setbkcolor(BLACK);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	abc:
	drawCross();
	rFile();

	if(flag==1)
	{
		flag=0;
		printf("Sorry! Its wrong word for the block\n");
	       //	cleardevice();
		goto abc;
	}
	xyz:
	printf("Enter block number : ");
		scanf("%d",&bno);
	if(bno>21)
	{
		printf("Choose block no in 1 - 21 range\n");
		goto xyz;
	}
	ans=vFile(bno);
	if(ans==1)
	{
		printf("Sorry! Block already filled\n");
	       //	cleardevice();
		goto abc;
	}

	switch(bno)
	{
	case 1:
		fillBox(bno,b0,name0);
		break;

	case 2:
		fillBox(bno,b1,name1);
		break;

	case 3:
		fillBox(bno,b2,name2);
		break;

	case 4:
		fillBox(bno,b3,name3);
		break;

	case 5:
		fillBox(bno,b4,name4);
		break;

	case 6:
		fillBox(bno,b5,name5);
		break;

	case 7:
		fillBox(bno,b6,name6);
		break;

	case 8:
		fillBox(bno,b7,name7);
		break;

	case 9:
		fillBox(bno,b8,name8);
		break;

	case 10:
		fillBox(bno,b9,name9);
		break;

	case 11:
		fillBox(bno,b10,name10);
		break;

	case 12:
		fillBox(bno,b11,name11);
		break;

	case 13:
		fillBox(bno,b12,name12);
		break;

	case 14:
		fillBox(bno,b13,name13);
		break;

	case 15:
		fillBox(bno,b14,name14);
		break;

	case 16:
		fillBox(bno,b15,name15);
		break;

	case 17:
		fillBox(bno,b16,name16);
		break;

	case 18:
		fillBox(bno,b17,name17);
		break;

	case 19:
		fillBox(bno,b18,name18);
		break;

	case 20:
		fillBox(bno,b19,name19);
		break;
	case 21:
		fillBox(bno,b20,name20);
		break;

	default:
		printf("Sorry ! Wrong choice.");
		break;
	       //	exit();
	}
       //	cleardevice();

       //	drawCross();

     /*	if(kbhit())
	{
	  key = get_key();
	}
	if( key == 1 )
	{
	    closegraph();
	    main();
	}
       }   */
	}
	while(bno!=0);

	fclose(fp);
	getch();

}
void drawCross()
{
	rectangle(10,10,410,360);   // the big boundry

	setcolor(WHITE);
	rectangle(185,10 ,210,135);  // 1
	rectangle(235,10 ,260,110);  // 2
	rectangle(385,10 ,410,160);  // 3
	rectangle(10 ,35 ,110,60 );  // 4
	rectangle(35 ,35 ,60 ,185);  // 5
	rectangle(185,35 ,285,60 );  // 6
	rectangle(135,60 ,160,185);  // 7
	rectangle(10 ,85 ,160,110);  // 8
	rectangle(235,85 ,285,110);  // 9
	rectangle(260,85 ,285,285);  // 10
	rectangle(310,85 ,335,285);  // 11
	rectangle(135,110,210,135);  // 12
	rectangle(360,135,385,185);  // 13
	rectangle(35 ,160,385,185);  // 14
	rectangle(85 ,160,110,310);  // 15
	rectangle(160,160,185,260);  // 16
	rectangle(385,210,410,360);  // 17
	rectangle(60 ,235,210,260);  // 18
	rectangle(235,235,410,260);  // 19
	rectangle(285,285,310,360);  // 20
	rectangle(235,335,410,360);  // 21

	// horizontal lines
	line(385,35 ,410,35 );  // 3
	line(385,60 ,410,60 );  // 3
	line(385,85 ,410,85 );  // 3
	line(385,110,410,110);  // 3
	line(385,135,410,135);  // 3

	line(185,85 ,210,85 );  // 1,6
	line(85 ,35 ,85 ,60 );  // 4,5
	line(35 ,135,60 ,135);  // 5
	line(260,135,285,135);  // 10
	line(310,110,335,110);  // 11
	line(310,135,335,135);  // 11
	line(85 ,210,110,210);  // 15
	line(160,210,185,210);  // 16
	line(260,210,285,210);  // 10
	line(310,210,335,210);  // 11
	line(85 ,285,110,285);  // 15
	line(285,310,310,310);  // 20
	line(385,285,410,285);  // 17
	line(385,310,410,310);  // 17

	// vertical lines

	line(85 ,85 ,85 ,110);  // 8
	line(110,85 ,110,110);  // 8
	line(210,160,210,185);  // 16
	line(235,160,235,185);  // 16
	line(135,235,135,260);  // 18
	line(260,335,260,360);  // 21
	line(335,335,335,360);  // 21
	line(360,335,360,360);  // 21

	// Labeling the cross and down

       //	settextstyle(0,HORIZ_DIR,2);

	settextstyle(2,HORIZ_DIR,3);

	outtextxy(187,12 ,"1");
	outtextxy(237,12 ,"2");
	outtextxy(387,12 ,"3");
	outtextxy(12 ,37 ,"4");
	outtextxy(37 ,37 ,"5");
	outtextxy(187,37 ,"6");
	outtextxy(137,62 ,"7");
	outtextxy(12 ,87 ,"8");
	outtextxy(237,87 ,"9");
	outtextxy(262,87 ,"10");
	outtextxy(312,87 ,"11");
	outtextxy(137,112,"12");
	outtextxy(362,137,"13");
	outtextxy(37 ,162,"14");
	outtextxy(87 ,162,"15");
	outtextxy(162,162,"16");
	outtextxy(387,212,"17");
	outtextxy(62 ,237,"18");
	outtextxy(237,237,"19");
	outtextxy(287,287,"20");
	outtextxy(237,337,"21");

	// cross words

	settextstyle(1,HORIZ_DIR,1);

	outtextxy(500,5,"Across");
	outtextxy(415,10,"_________________________________");

	settextstyle(0,HORIZ_DIR,1);

	outtextxy(415,40,"4. Command-line invoker");
	outtextxy(415,50,"6. Back again ?");
	outtextxy(415,60,"8. Can't go both ways");
	outtextxy(415,70,"9. Acronym 4 ur laptop's ");
	outtextxy(415,80,"   power");
	outtextxy(415,90,"12.Number variable type");
	outtextxy(415,100,"13.Acronym 4 a chip");
	outtextxy(415,110,"14.Say something");
	outtextxy(415,120,"18.Quite a crew of");
	outtextxy(415,130,"   characters");
	outtextxy(415,140,"19.Announce a new class");
	outtextxy(415,150,"   or method");
	outtextxy(415,160,"21.What's a prompt good 4");

	outtextxy(413,170,"_________________________________");

	settextstyle(1,HORIZ_DIR,1);

	outtextxy(500,185,"Down");

	outtextxy(415,190,"_________________________________");

	settextstyle(0,HORIZ_DIR,1);

	outtextxy(415,220,"1. Not an integer");
	outtextxy(415,230,"   or___your boat");
	outtextxy(415,240,"2. Come back emty handed");
	outtextxy(415,250,"3. Open house");
	outtextxy(415,260,"5. 'Things' holders");
	outtextxy(415,270,"7. Until attitude improves");
	outtextxy(415,280,"10.Source code consumer");
	outtextxy(415,290,"11.Can't pin it down");
     //		outtextxy(415,300,"13.Dept. of LAN jockeys");
	outtextxy(415,300,"15.Shocking modifier");
	outtextxy(415,310,"16.Just gotta have one");
	outtextxy(415,320,"17.How to get things done");
	outtextxy(415,330,"20. Bytecode consumer");

	outtextxy(415,340,"_________________________________");
}
void fillBox(int no,int bno[15][3],char *bname[15])
{
	settextstyle(1,HORIZ_DIR,3);

       printf("Enter word for block %d :",no );
			scanf("%s",temp[1]);

       if(stricmp(name[no-1],temp[1])==0)
       {
	      //	printf("its done :)");
		for(i=0;i<size[no-1];i++)
		{
			outtextxy(bno[i][0],bno[i][1],bname[i]);
			//	printf("%s",bname[i]);
		}
		wFile(no);
       }
       else
       {
		flag=1;
		outtextxy(10,370,"Sorry! It's wrong word.");
		printf("Sorry!");

       }
}
void wFile(int no)
{

	fclose(fp);
	fp=fopen("data.txt","a");
	tp=no;
	putw(tp,fp);
	fclose(fp);
}
int vFile(int no)
{
	int fg=0;
	fclose(fp);
	fp=fopen("data.txt","r");

	while((tp=getw(fp))!=EOF)
	{
	       //	printf("%d",tp);
	       if(tp==no)
		fg=1;
	}
	fclose(fp);
	return fg;
}
void rFile()
{
	fp=fopen("data.txt","r");

      //   while(fscanf(fp,"%d",&tp) != EOF)    compile time 	error

	while((tp=getw(fp))!=EOF)
	{
	       //	printf("%d",tp);
		auto_fill(tp);
	}
	fclose(fp);

//     fprintf(stderr,"ERROR: unable to open file ","data");
//     outtextxy(10,340,":}");

}
void auto_fill(int no)
{
	switch(no)
	{
	case 1:
		fill(no,b0,name0);
		break;

	case 2:
		fill(no,b1,name1);
		break;

	case 3:
		fill(no,b2,name2);
		break;

	case 4:
		fill(no,b3,name3);
		break;

	case 5:
		fill(no,b4,name4);
		break;

	case 6:
		fill(no,b5,name5);
		break;

	case 7:
		fill(no,b6,name6);
		break;

	case 8:
		fill(no,b7,name7);
		break;

	case 9:
		fill(no,b8,name8);
		break;

	case 10:
		fill(no,b9,name9);
		break;

	case 11:
		fill(no,b10,name10);
		break;

	case 12:
		fill(no,b11,name11);
		break;

	case 13:
		fill(no,b12,name12);
		break;

	case 14:
		fill(no,b13,name13);
		break;

	case 15:
		fill(no,b14,name14);
		break;

	case 16:
		fill(no,b15,name15);
		break;

	case 17:
		fill(no,b16,name16);
		break;

	case 18:
		fill(no,b17,name17);
		break;

	case 19:
		fill(no,b18,name18);
		break;

	case 20:
		fill(no,b19,name19);
		break;
	case 21:
		fill(no,b20,name20);
		break;
	}
}
void fill(int no,int bno[15][3],char *bname[15])
{
	settextstyle(1,HORIZ_DIR,3);

    for(i=0;i<size[no-1];i++)
    {
	outtextxy(bno[i][0],bno[i][1],bname[i]);
       //	printf("%s",bname[i]);
    }
}
