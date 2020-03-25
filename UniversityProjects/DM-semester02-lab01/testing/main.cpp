#include <iostream>

using namespace std;

struct Graf

{
    
    int x;
    
    int y;
    
};

void smezhnost (int matr_smezhnosti[11][11], int matr_dostizhimosti[11][11])

{
    
    for (int i=0;i<11;++i)
        
        for (int j=0;j<11;++j)
            
            matr_dostizhimosti[i][j]=matr_smezhnosti[i][j];
    
    for (int k=0;k<11;k++)
        
        for (int i=0;i<11;i++)
            
            for (int j=0;j<11;j++)
                
                matr_dostizhimosti[i][j]=(matr_dostizhimosti[i][j]||(matr_dostizhimosti[k][j]&&matr_dostizhimosti[i][k]));
    
}

int main()

{
    
    setlocale(0,"");
    
    Graf g[35]={{1,2},{1,5},{1,6},{1,11},{2,3},{2,4},{2,5},{2,8},{2,9},{2,10},{3,3},{3,5},{3,8},{4,1},{4,2},{4,5},{5,1},
        
        {5,9},{5,11},{6,1},{6,3},{6,8},{7,1},{7,7},{7,10},{7,11},{8,2},{8,7},{9,4},{9,7},{9,9},{10,1},{10,2},{11,4},{11,5}};
    
    int smezhn[11][11]={0};
    
    for(int i=0;i<35;++i)
        
    {
        
        smezhn[g[i].x-1][g[i].y-1]=1;
        
    }
    
    cout<<"Матрица смежности:"<<endl;
    
    for(int i=0;i<11;++i,cout<<'\n')
        
        for(int j=0;j<11;++j)
            
        {
            
            cout.width(3);
            
            cout<<smezhn[i][j]<<' ';
            
        }
    
    int intsed[11][35]={0};
    
    for(int i=0;i<35;++i)
        
    {
        
        intsed[g[i].x-1][i]=1;
        
        intsed[g[i].y-1][i]=-1;
        
        if(g[i].x-1==g[i].y-1)
            
        {
            
            intsed[g[i].x-1][i]=2;
            
            intsed[g[i].y-1][i]=2;
            
        }
        
    }
    
    cout<<"\nМатрица инцедентности:\n";
    
    for(int i=0;i<11;++i,cout<<'\n')
        
        for(int j=0;j<35;++j)
            
        {
            
            cout.width(2);
            
            cout<<intsed[i][j];
            
        }
    
    cout<<"\nМатрица достижимости\n";
    
    int dostezh[11][11]={0};
    
    smezhnost(smezhn,dostezh);
    
    for(int i=0;i<11;++i,cout<<'\n')
        
        for(int j=0;j<11;++j)
            
        {
            
            cout.width(3);
            
            cout<<dostezh[i][j]<<' ';
            
        }
    
    return 0;
    
}
