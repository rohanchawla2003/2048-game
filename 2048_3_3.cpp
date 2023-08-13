#include <iostream>
using namespace std;

void insert2(int arr[][3]){

    if(arr[1][0]==0){
        arr[1][0]=2;
    }
    else{
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(arr[i][j]==0){
                    arr[i][j] = 2;
                    return;
                }
            }
        }
    }
}

void display(int arr[][3]){
    for(int i{} ; i < 3  ; i++  ){
        for(int j{}  ; j  < 3 ; j++){
          cout << arr[i][j] << " " ;
                    }
                    cout << endl;
                }
}

void move_2 (int arr[][3]){
    for(int j = 0; j<3;j++){
        bool first_operation = 0;
        if(arr[2][j]==arr[1][j]){
            first_operation = 1;
            arr[2][j] *= 2;
            arr[1][j] = 0;

        }
        else if(arr[2][j]==0){
            swap(arr[2][j],arr[1][j]);
        }
        for(int i = 0;i<2;i++){
            if(arr[i+1][j]==0){
                swap(arr[i][j],arr[i+1][j]);

            }
            else if(arr[i][j]==0){
                continue;
            }
            else if(arr[i+1][j]==arr[i][j] and first_operation==0){
                first_operation = 1;
                arr[i+1][j] *= 2;
                arr[i][j] = 0;
            }
        }
    }

      insert2(arr);
      display(arr);
}

void move_4 (int arr[][3]){

    for(int i = 0; i<3;i++){
        bool first_operation = 0;
        if(arr[i][0]==arr[i][1]){
            first_operation = 1;
            arr[i][0] *= 2;
            arr[i][1] = 0;

        }
        else if(arr[i][0]==0){
            swap(arr[i][0],arr[i][1]);
        }
        for(int j = 2;j>0;j--){
            if(arr[i][j-1]==0){
                swap(arr[i][j],arr[i][j-1]);

            }
            else if(arr[i][j]==0){
                continue;
            }
            else if(arr[i][j-1]==arr[i][j] and first_operation==0){
                first_operation = 1;
                arr[i][j-1] *= 2;
                arr[i][j] = 0;
            }
        }
    }



      insert2(arr);
      display(arr);
}

void move_6 (int arr[][3]){

    for(int i = 0; i<3;i++){
        bool first_operation = 0;
        if(arr[i][2]==arr[i][1]){
            first_operation = 1;
            arr[i][2] *= 2;
            arr[i][1] = 0;

        }
        else if(arr[i][2]==0){
            swap(arr[i][2],arr[i][1]);
        }
        for(int j = 0;j<2;j++){
            if(arr[i][j+1]==0){
                swap(arr[i][j],arr[i][j+1]);

            }
            else if(arr[i][j]==0){
                continue;
            }
            else if(arr[i][j+1]==arr[i][j] and first_operation==0){
                first_operation = 1;
                arr[i][j+1] *= 2;
                arr[i][j] = 0;
            }
        }
    }

      insert2(arr);
      display(arr);
}

void move_8 (int arr[][3]){
    for(int j = 0; j<3;j++){
        bool first_operation = 0;
        if(arr[0][j]==arr[1][j]){
            first_operation = 1;
            arr[0][j] *= 2;
            arr[1][j] = 0;

        }
        else if(arr[0][j]==0){
            swap(arr[0][j],arr[1][j]);
        }
        for(int i = 2;i>0;i--){
            if(arr[i-1][j]==0){
                swap(arr[i][j],arr[i-1][j]);

            }
            else if(arr[i][j]==0){
                continue;
            }
            else if(arr[i-1][j]==arr[i][j] and first_operation==0){
                first_operation = 1;
                arr[i-1][j] *= 2;
                arr[i][j] = 0;
            }
        }
    }



      insert2(arr);
      display(arr);
}

void moves(int arr[][3] , int move){
    switch(move){
        case 2:
        move_2(arr); break;
        case 4:
        move_4(arr); break;
        case 6:
        move_6(arr); break;
        case 8:
        move_8(arr); break;
        default : cout << "INVALID MOVE" << endl;
    }
    bool check0 = 0;
    for(int i{} ; i<3 ; i++){
        for(int j{} ; j<3 ; j++){
            if(arr[i][j] == 0){
                check0 = 1; break;
            }
        }
    }
    if(check0){
            cout << "Enter your move: " ;
            cin >> move;
            moves(arr,move) ;
    }
    else{
        cout << "Game over" << endl;
    }
}




int main()
{
    cout << "WELCOME TO 2048 GAME" <<endl;

    int arr [3] [3] {};
    arr[0][1]  = 2 ;
    char choice{};

        while(choice != 'q'|| choice != 'Q'){

          cout << "To play press y or Y" << endl;
          cout << "To exit press q or Q" << endl;


          cout << "Enter your input: " ;
          cin >> choice;

          if(choice == 'y' || choice == 'Y'){
                for(int i{} ; i < 3  ; i++  ){
                    for(int j{}  ; j  < 3 ; j++  ){
                        cout << arr[i][j] << " " ;
                    }
                    cout << endl;
                }
          cout<<"Press '2' for UP "<<endl;
          cout<<"Press '4' for LEFT "<<endl;
          cout<<"Press '6' for RIGHT "<<endl;
          cout<<"Press '8' for DOWN "<<endl;
                int move{};
                cout << "Enter your move: " ;
                cin >> move;
                moves(arr,move);
          break;

        }else if(choice == 'q' || choice == 'Q'){
            cout<<"GAME END";
                break;
        }else{
                cout << "WRONG INPUT" << endl;
        }

    }

	return 0;
}
