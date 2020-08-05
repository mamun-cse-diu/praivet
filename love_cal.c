#include<stdio.h>
#include<string.h>
int main(){
    char boy[50];
    char girl[50];
    char intake[]="loves";
    char temp;
    printf("Enter Your (First/Last)Name in small letter : \n");
    scanf("%[^\n]",boy);
    scanf("%c",&temp);
    printf("Enter Your [GF/BF/Crush/Wife/Hubby]'s(First/Last)Name in small letter : \n");
    scanf("%[^\n]",girl);
    printf("\n");
    strcat(boy,intake);
    strcat(boy,girl);
    //printf("%s\n", boy);
    int num=strlen(boy);
    int repeat[num];
    memset(repeat,0,sizeof repeat);
    int l=0,m=0;
    //sorting
    int counter;
   //array lentgh counting
    for(l=0;l<num;l++){
        counter=1;
    for(m=l+1;m<num;m++){
        if(boy[l]==boy[m]&& boy[l]!=0){
            counter++;
            boy[m]=0;
        }
    }
    //input in repeat array
    if(boy[l]!=0){
        repeat[l]=counter;
    }
   }
   // middle 0 passing to the last
     for(l=0;l<num-1;l++){
        for(m=l+1;m<num-1;m++){
            if(repeat[m]==0){
                    repeat[m]=repeat[m+1];
                    repeat[m+1]=0;
                }
            }
    }
  //counting real repeating array input.
    int count=0;
    int s=0;
    for(s=0;s<num;s++){
        if(repeat[s]>0){
                count++;
        }
    }
  /*for(l=0;l<num;l++){
    printf("%d\n",repeat[l]);
  }
  printf("actual count= %d\n",count);*/
    int first,num1;
    int last;
    if(count%2==0){
        num1=count/2;
    }else{
        num1=(count/2)+1;
    }
    int phase1[num1];
    //printf("num1= %d",num1);//5
 //summation for first time
   int tecount=count;
  for(s=0;s<count/2;s++){
        first=repeat[s];
        last=repeat[tecount-1];
        phase1[s]=first+last;
        tecount--;
  }
//if count is odd number
  if(count%2!=0){
    phase1[(count/2)]=repeat[count/2];
  }
  /*printf("\nafter count= %d\n",count);
  for(s=0;s<num1;s++){
  printf("\n%d\n",phase1[s]);
  }*/
// summation for the second time
//  printf("num1= %d",num1);//5
  int num2,tempo,phase2[20];
  if(num1%2==0){
        num2=num1/2;
        phase2 [num2];
        tempo=num1;
        for(s=0;s<num2;s++){//3
              first=phase1[s];
              last=phase1[tempo-1];
              phase2[s]=first+last;
              tempo--;
        }
    }else{
        num2=(num1/2)+1;
        phase2[num2];
        tempo=num1;
        for(s=0;s<num2-1;s++){//3
              first=phase1[s];
              last=phase1[tempo-1];
              phase2[s]=first+last;
              tempo--;
        }
        if(num1%2!=0){
          phase2[(num2-1)]=phase1[num1/2];
        }
    }
 // printf("num2= %d",num2);//5
  /*for(s=0;s<num2;s++){
    printf("\n hidden%d\n",phase2[s]);
  }*/
//summation for third time
  int num3=(num2/2);//3
  int phase3 [3];
      tempo=num2;//new tempo
  for(s=0;s<(num2/2);s++){//2
      first=phase2[s];
      last=phase2[tempo-1];
      phase3[s]=first+last;
      tempo--;
  }
  if(num2%2!=0){
    phase3[(num2/2)]=phase2[num2/2];
  }
  if((phase3[0]>9 || phase3[1]>9)){
    phase3[0]=(phase2[1]+phase2[2])/10;
    phase3[1]=(phase2[1]+phase2[2])%10;
    phase3[2]=phase2[1];
    num3++;
    if(num3==2){
        phase3[0]=(phase3[0]+phase3[2]);
        phase3[1]=phase3[1];
    }
  }else if(num2>4){
      num3++;
  }
  /*for(s=0;s<=num3;s++){
    printf("\n hid%d\n",phase3[s]);
  }*/
//print the result
  if(num3>2){
      int num4=num2/2;
      int phase4[num4];
        phase4[0]=(phase3[0]+phase3[2]);
        phase4[1]=phase3[1];
        if((phase4[0]>9 || phase4[1]>9)){
            phase4[0]=(phase3[0]+phase3[1])/10;
            phase4[0]=(phase4[0]+phase3[1]);
            phase4[1]=(phase3[0]+phase3[1])%10;
            printf("\nmara\n");
   }
    for(s=0;s<=1;s++){
        printf("%d",phase4[s]);
    }
  }
  else{
        for(s=0;s<2;s++){
        printf("%d",phase3[s]);
        }
    }
  printf("%%\n");
return 0;
}
