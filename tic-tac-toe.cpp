#include <bits/stdc++.h>

using namespace std;
vector<vector<string>> matrix={{"1","2","3"},{"4","5","6"},{"7","8","9"}};

bool notEmpty(){
    for(auto a:matrix){
        for(auto b:a){
            if(b!="x" || b!="X" || b!="O" || b!="o")
            return true;
        }
    }
    return false;
}

bool won(){
    for( int i = 0 ; i < 3 ; i++ ){
        set<string> st ;
        for( int j = 0 ; j < 3 ; j++ ){
            st.insert( matrix[i][j] ) ;
        }
        if ( st.size() == 1 )
        return true ;
    }
    return false ;
}


int main(){
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<":::::::::::::::::::::::::::::::TIC - TAC - TOE ::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl<<endl;
    cout<<":::::::::::::::::::::::::::::!!! YOU VS COMPUTER !!!!::::::::::::::::::::::::::::::"<<endl;
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl<<endl;cout<<":::::::::::::::::::::::::::::::: HOW TO PLAY THE GAME ???::::::::::::::::::::::::::"<<endl;
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl<<endl;
    cout<<"::::::::::::::::::::::::::::::::::CHOOSE X OR O:::::::::::::::::::::::::::::::::::::"<<endl<<endl<<endl;
    cout<<":::::::::::::::::::From the above matrix choose number from 1 to 9::::::::::::::::::"<<endl;
    cout<<"::::::::::::::::corresponding to each cell of the 3 by 3 matrix:::::::::::::::::::::"<<endl;
    cout<<":::::::::::::After your turn computer will choose position of it's own choice:::::::"<<endl<<endl;

    for(auto a: matrix){
        for(auto b:a){
            cout<<b<<"|";
        }
        cout<<"\n"<<"------"<<"\n";
    }

    string xo;
    cout<<"Choose X/x or O/o ::: ";
    cin>>xo;

    while(notEmpty()){
        string choice;
        cout<<"ENTER POSITION OF YOUR CHOICE";
        cin>>choice;

        for( int i = 0 ; i < 3 ; i++ ){
            for( int j = 0 ; j < 3 ; j++ ){
                if( matrix[i][j] == choice ){
                    matrix[i][j] = xo;
                    break;
                }
            }
        }
        int c = ( rand() % 9 )+ 1;
        string compChoice = to_string(c);

        string cxo;
        if( xo == "x" || xo =="X" )
        cxo = "O";
        else
        cxo = "X";

        cout<<"COMPUTER'S CHOICE:: "<<compChoice<<endl;
        for( int i = 0 ; i < 3 ; i++ ){
            for( int j = 0 ; j < 3 ; j++ ){
                if( matrix[i][j] == compChoice ){
                    matrix[i][j] = cxo;
                    break;
                }
            }
        }

        for ( auto a : matrix ) {
            for ( auto b : a ) {
                cout<<b<<"|";
            }
            cout<<"\n"<<"------"<<"\n";
        }

        if ( won() ) {
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
            cout<<"::::::::::::::::::::::::::::YOU WON !!!!!!!!!!!::::::::::::::::::::::::::::::::::";
            cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
            break;
        }
    }
    if(!notEmpty()){
        cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
        cout<<"::::::::::::::::::::::::::::YOU LOST 😥😥😥😥😥::::::::::::::::::::::::::::::::";
        cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";

    }

    return 0;

    

}