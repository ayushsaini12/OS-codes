#include <iostream>
using namespace std;

bool search (int key , int fr[], int pn){

   
    for (int i = 0; i < pn; i++)
    {
        if (fr[i]== key)
        {
            return true;
        }
        return false;    
    }
    
}

int predict( int pg[], int fr [], int pn, int index){

    int res = -1, farthest = index;
    for (int i = 0; i < pn; i++)
    {
        int j;
        for ( j = index; j < pn; i++)
        {
            if (fr[i]== pg[i])
            {
                if (j> farthest)
                {
                    farthest =j;
                    res = i;
                }
                break;
                
            }
            
        }
        if (j == pn)
            return i;
        
    }
    return(res== -1) ? 0:res;
    
}

void optimal(int pg[], int pn, int fn){
    int fr[fn];
    int hit = 0;
    int index = 0;
        for (int i = 0; i < pn; i++) {
 
            if (search(pg[i], fr, pn)) {
                hit++;
                continue;
            }

            if (index < fn)
                fr[index++] = pg[i];
 
            else {
                int j = predict(pg, fr, pn, i + 1);
                fr[j] = pg[i];
            }
        }
        cout<<"No of page fault: "<<hit<<endl;

}

int main(){
    int pg []= {7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};
    int pn = sizeof(pg) / sizeof(pg[0]);
    int fn = 3;
    optimal(pg, pn, fn);
    return 0;
}