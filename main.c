//
//  main.c
//  ECON
//
//  Created by Brent Maxwell Marks on 2015-03-23.
//  Copyright (c) 2015 Brent Maxwell Marks. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    
    int input=0,run=0;
    double percent,year,a,g,total=0;
    double formulas[9];
    do{
    printf("1 for F/A:\n2 for A/F:\n\n3 for A/P:\n4 for P/A:\n\n5 for A/G:\n6 for P/G:\n7 for (P/A,g,i,N):\n\n8 for F_P:\n9 for P_F:\n");
    scanf("%d",&input);
    input=input-1;
    printf("Enter the percent and the years, amount\n");
    scanf("%lf%lf%lf",&percent,&year,&a);
    percent=percent/100;
    
    if(input==6){
        printf("Enter g:\n");
        scanf("%lf",&g);
        g=g/100;
    }
    //formulas for different types of flow charts
    formulas[0]=(pow((1+percent),year)-1)/percent;//F_A
    formulas[1]=(percent/(pow((1+percent),year)-1));//A_F
    formulas[2]=((percent*pow((percent+1),year))/(pow((percent+1),year)-1));//A_P
    formulas[3]=(pow((1+percent),year)-1)/(percent*pow((1+percent),year));//P_A
    formulas[4]=(pow((1+percent),year)-(percent*year)-1)/(percent*(pow((1+percent),year)-1));//A_G
    formulas[5]=((pow((1+percent),year)-(percent*year)-1)/((percent*percent)*(pow((1+percent),year))));//P_G
    formulas[6]=((1-(pow((1+g),year)*pow((1+percent),-year)))/(percent-g));//P_A1
    formulas[7]=(pow((1+percent),year));//F_P
    formulas[8]=((pow((1+percent),year)));//P_F

    printf("%1.4lf %1.4lf\nenter 1 to exit or 0 to run again\n",formulas[input],formulas[input]*a);
        total=total+formulas[input]*a;
        printf("total: %1.4lf",total);
        scanf("%d",&run);
    }while(run==0);
    return 0;
}
