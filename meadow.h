#include <windows.h>

int m[112][112];  //two-dimensional array that controls the location of the symbols

char *morient = "D";

void mfont(){

    CONSOLE_FONT_INFOEX info = {0};
    info.cbSize = sizeof(info);
    info.dwFontSize.X = 9;
    info.dwFontSize.Y = 9;
    info.FontWeight = FW_NORMAL;
    wcscpy(info.FaceName, L"Terminal");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);

}

void meadow(int sizeX, int sizeY){

    printf("%c", 201);  //border top left

    for(int i = 0; i < sizeX; i++){printf("%c", 205);}  //border top middle

    printf("%c\n", 187);    //border top right

    for(int j = 0; sizeY - j > 0; j++){

        printf("%c", 186);    //border left

        for(int i = 1; i < sizeX + 1; i++){

            int x, y;

            if(morient == "lrtb" || morient == "lt" || morient == "D"){x = i; y = j + 1;}    //checking preferred orientation
            if(morient == "lrbt" || morient == "lb" || morient == "A"){x = i; y = sizeY - j;}
            if(morient == "rltb" || morient == "rt" || morient == "C"){x = sizeX - i + 1; y = j + 1;}
            if(morient == "rlbt" || morient == "rb" || morient == "B"){x = sizeX - i + 1; y = sizeY - j;}

            if(m[x][y] == 0){

                printf(" ");
                continue;

            }

            printf("%c", m[x][y]);


        }

        printf("%c\n", 186);    //border right

    }

    printf("%c", 200);  //border bottom left

    for(int i = 0; i < sizeX; i++){printf("%c", 205);}  //border bottom middle

    printf("%c\n", 188);    //border bottom right

}

void mclear(){for(int i = 0; i <= 112; i++){for(int j = 0; j <= 112; j++){m[i][j] = 0;}}}   //function with two loops that clears your meadow

void mfill(int fcoordx1, int fcoordy1, int fcoordx2, int fcoordy2, int material){

    if(fcoordx2 < fcoordx1){    //checking if x coordinates have been switched and fixing them
        int buffer = fcoordx1;
        fcoordx1 = fcoordx2;
        fcoordx2 = buffer;
    }

    if(fcoordy2 < fcoordy1){    //checking if y coordinates have been switched and fixing them
        int buffer = fcoordy1;
        fcoordy1 = fcoordy2;
        fcoordy2 = buffer;
    }

    for(int i = fcoordx1; i <= fcoordx2; i++){    //loop to fill the desired space
        for(int j = fcoordy1; j <= fcoordy2; j++){
            m[i][j] = material;
        }
    }

}
