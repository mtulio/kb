// matriz multidimensional
#include <iostream> 
#define WIDTH 5
#define HEIGHT 3 
int jimmy [HEIGHT][WIDTH];
int n,m; 
int main (){  
    for (n=0;n<HEIGHT;n++)    
    for (m=0;m<WIDTH;m++)    {
        jimmy[n][m]=(n+1)*(m+1);
              std::cout<<"vet["<<n<<"]["<<m<<"]"<<jimmy[n][m]<<std::endl<<std::endl;
    }
    getchar();
        getchar();
    return 0;
}
