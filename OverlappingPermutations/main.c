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
    int N, ActN, num[5], ord[5], order, rank, num_to_rem;
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
    while(N--)
    {
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
        
        num_to_rem=num[0];
        
        for(int i=0;i<4;i++)
        {
            num[i]=num[i+1];
            if(num[i]>=num_to_rem)
                ord[i]=ord[i+1]-1;
            else
                ord[i]=ord[i+1];
        }
        
        if(N)
            scanf("%d",&num[4]);
        else
            break;
        
        ord[4]=0;
        
        for(int i=0;i<4;i++)
        {
            if(num[4] >= num[i])
                ord[4]++;
            else
                ord[i]++;
        }
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
    
    printf("Expected average number of occurrences of each permutation = %lf",expected_occurence);
    printf("\nActual average number of occurrences of each permutation = %lf",average_occurrence);
    printf("\nVariance in number of occurrences = %lf",variance);
    printf("\nStandard Deviation of occurrences = %lf",standard_deviation);
    return 0;
    
}

