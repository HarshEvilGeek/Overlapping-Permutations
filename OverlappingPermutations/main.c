//
//  main.c
//  OverlappingPermutations
//
//  Created by Akhil Verghese on 5/9/13.
//  Copyright (c) 2013 Akhil Verghese. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    int N, ActN, num[5], ord[5], order, rank;
    int fact[4]={1,2,6,24};
    int ordercount[120];
    
    scanf("%d",&N);
    ActN=N;
    if(N<5)
        return 1;
    
    for(int i=0;i<5;i++)
        scanf("%d",&num[i]);
    
    for(int i=0;i<120;i++)
        ordercount[i]=0;
    
    N-=4;
    while(N--)
    {
        for(int i=0;i<5;i++)
            ord[i]=0;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(i!=j)
                {
                    if(num[i]>num[j])
                        ord[i]++;
                    if(num[i]==num[j])//stable ranking
                    {
                        if(i>j)
                            ord[i]++;
                    }
                }
            }
        }
        
        order=0;
        
        for(int i=0;i<4;i++)
        {
            rank=0;
            for(int j=i+1;j<5;j++)
            {
                if(ord[i]>ord[j])
                    rank++;
            }
            order+=(rank*fact[4-i-1]);
        }
        
        ordercount[order]++;
        
        for(int i=1;i<5;i++)
            num[i-1]=num[i];
        
        if(N)
            scanf("%d",&num[4]);
    }
    
    double average_occurrence = 0.0, variance = 0.0, standard_deviation, expected_occurence=(double)ActN/120;
    
    for(int i=0;i<120;i++)
    {
        average_occurrence+=ordercount[i];
    }
    
    average_occurrence/=120;
    
    for(int i=0;i<120;i++)
    {
        variance+=pow((double)ordercount[i]-average_occurrence,2);
    }
    
    variance/=120;
    standard_deviation=sqrt(variance);
    
    printf("Number of occurrences for each permutation:");
    
    for(int i=0;i<120;i++)
    {
        printf("\nNumber of occurrences of permutation #%d = %d",i+1,ordercount[i]);
    }
    
    printf("\nExpected average number of occurrences of each permutation = %lf",expected_occurence);
    printf("\nActual average number of occurrences of each permutation = %lf",average_occurrence);
    printf("\nVariance in number of occurrences = %lf",variance);
    printf("\nStandard Deviation of occurrences = %lf",standard_deviation);
    return 0;
    
}

