//Binary-search or Arrays

#include<iostream>

using namespace std;

	//declaring a function binary search that takes the array, the first element , last element and the key as argument and returns the position of the key

int bsearch(int arr[],int l,int h,int k){
	
	//declaring m as an integer that specifies half the array-length
	
    int m=(l+h)/2;
    
	//comparing first and last element of the array
	
    if(k<arr[l]||k>arr[h]){
		cout<<"ERROR!!";
        return -1; 

    }

    if(arr[m]==k){

        return m; //if mid is the key, it returns the position of the mid

    }

    else if(arr[m]>k){

        bsearch(arr,0,(m-1),k); //recursive calling to bsearch function after with mid-1 element as the last array element

    }

    else if(arr[m]<k){

        bsearch(arr,m+1,h,k); ////recursive calling to bsearch function after with mid+1 element as the first array element

    }

    else{
		cout<<"ERROR!!";
        return -1; //this refers to the fact that the key is not there in the user input array

    }

}

//sorting the array elements

class bubblesort{

    public:

    void sort(int arr[], int l){
    	int temp;
	
	//declaring two loops to swap the array elements to place them in an ascending order
	
    for(int i=0;i<l;i++){ 

    for(int j=0;j<(l-i-1);j++){

    if(arr[j]>arr[j+1]){
	
	//declaring temp as an integer that holds the value of a[j+1]th array element to swap the values of a[j] and a[j+1] array element
	 
    temp = arr[j+1];

    arr[j+1] = arr[j];

	arr[j] = temp;

    }

	}

	}

    }

};



int main(){
	
    int key;

	//declaring a class component c belonging to class bubblesort
	
	bubblesort c;
	
 	int a;
	cout<<"Enter the size of the array : ";
	cin>>a;
	int arr[a];
	cout<<"Enter The Array Elements : ";
	
	for(int i=0;i<a;i++){
		cout<<"arr["<<i<<"] : ";
		cin>>arr[i];
		cout<<"\n";
	}
	
	//calling the sort function
	
    c.sort(arr,a);

    cout<<"Which element do you want to find ? ";
    
    cin>>key;

    int ans=bsearch(arr,0,a-1,key);//calling the bsearch function

    cout<<"The element is in this position : "<<ans;

    return 0;

}
