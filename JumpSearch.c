#include<stdio.h>
#include<math.h>


int min(int first, int second){
    if(second>first){
        return first;
    }else{
        return second;
    }
}

int jumpSearch(int arr[],int size,int key){
    int step = sqrt(size);
    int previous = 0;
    
    while(arr[min(step,size)-1]<key){
        previous = step;
        step = step+sqrt(size);
        if(previous>=size){
            return -1;
        }
    }
    
    while(arr[previous]<size){
      previous = previous+1;
      
      if(previous == min(step,size) ){
        return -1;
      }
    }
    
    if(arr[previous]== key){
      return previous;
    }
    return -1;
    
    for(int j =previous ; j<step ; j++){
        if(arr[j] == key){
            return j;
        }
    }
}
 int main(){
     int arr[]= {1,2,3,4,5,6,7,8,9,100,101,105};
     int size = sizeof(arr)/sizeof(arr[0]);
     int toFind = 100;
     int indexNumber = jumpSearch(arr,size,toFind);
     if(indexNumber!=-1){
         printf("We found \n");
         printf("Found at index %d   data : %d ",indexNumber,arr[indexNumber]);
     }else{
         printf("Not found!\n");
     }
     return 0;
 }
