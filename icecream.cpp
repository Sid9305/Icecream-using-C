#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int abs_val(int n) 
{
    if (n >= 0) 
	{
        return n;
    } 
	else 
	{
        return -n;
    }
}

void dda(int x1, int y1, int x2, int y2 , int color) 
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, k;
    float xinc, yinc, x = x1, y = y1;

    if (abs_val(dx) > abs_val(dy)) 
	{
        steps = abs_val(dx);
    } 
	else 
	{
        steps = abs_val(dy);
    }

    xinc = (float) dx / steps;
    yinc = (float) dy / steps;

    putpixel(x, y, color);

    for (k = 0; k < steps; k++) 
	{
        x += xinc;
        y += yinc;
        putpixel(round(x), round(y), color);
        delay(2);
    }
}

int main() 
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

	setfillstyle(SOLID_FILL,BROWN);
    dda(150, 170, 220, 300,6);
    dda(220, 300, 290, 170,6);
    dda(290,170,150,170,6);
    floodfill(170,200,BROWN);
    
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL,YELLOW);
    arc(220,170,0,-177,70);
    dda(149,170,289,170,14);
    floodfill(220,160,YELLOW);
    
    getch();
    closegraph();
    return 0;
}

