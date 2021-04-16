#include<stdio.h>
#include<stdlib.h>
#include <math.h>

struct Freq{
   float el;
   int f;

};

void sortinascendingorder (float *array, size_t len){

float temp;
   for(int i=0;i<len;i++){
      for(int j=i+1;j<len;j++){
          if(*(array+i)>*(array+j)){
              temp=*(array+i);
              *(array+i)=*(array+j);

              *(array+j)=temp;

          }
      }
   }


}

void largestandsmallestelement (const float *array, size_t len){
    float max,min;
    max=*(array+0);
    min=*(array+0);

    for(int i=0;i<len;i++){
        if(max<*(array+i)){
            max=*(array+i);
        }
    }
    printf("Largest Element:%f\n",max);

    for(int i=0;i<len;i++){
        if(min>*(array+i)){
            min=*(array+i);
        }
    }
    printf("Smallest Element:%f\n",min);
}


void checks_repeats(const float *array, size_t len) {


struct Freq *Z;
Z=(struct Freq*)malloc(len*sizeof(struct Freq));


for(int k=0;k<len;k++){
    Z[k].el=*(array+k);
    Z[k].f=1;


}



for(int i=0;i<len;i++){


    for(int j=0;j<len;j++){
        if(i!=j && (Z[i].el==Z[j].el)){
            Z[i].f++;
        }


    }

     if(Z[i].f==1){

            printf("Element  %f||Frequency %d\n",Z[i].el,Z[i].f);

        }
        else{


            printf("Element  %f||Frequency %d\n",Z[i].el,Z[i].f);



        }


}



float mode=Z[0].el;
int modal_freq=Z[0].f;


for(int t=0;t<len;t++){
    if(modal_freq<Z[t].f){
    modal_freq=Z[t].f;
    mode=Z[t].el;

    }
}


printf("\n\nMode:%f ||Frequency:%d",mode,modal_freq);
//Mode might be multiple numbers
for(int i=0;i<len;i++){

        if(Z[i].el!=mode && Z[i].f==modal_freq){

            printf("\nOR\nMode:%f ||Frequency:%d",Z[i].el,modal_freq);
        }

}






float mean=0;




for(int i=0;i<len;i++){
    mean+=Z[i].el;
}

float Y=(mean/(float)len);

printf("\n\nMean:%f ",Y);
printf("\n\nMedian:%f ",(2*Y+mode)/(float)3);

float x;

for(int i=0;i<len;i++){
     x+=(Z[i].el-Y)*(Z[i].el-Y);
}
printf("\n\nVariance:%f ",(x/len));
printf("\n\nStandard Deviation:%f ",sqrt(x/len));

}

int main()
{


int z;

float *c;

printf("Input size of array:\n");
scanf("%d",&z);

c=(float*)malloc(z*sizeof(float));

for(int i=0;i<z;i++){
    printf("Element %d:\n",i+1);
    scanf("%f",&*(c+i));
}



sortinascendingorder(c, z);
printf("\n");
largestandsmallestelement(c, z);
printf("\n");
checks_repeats(c, z);

free(c);
c=NULL;



}
