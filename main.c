


/******************************************************************************************

Chipper keyden aldığım ilk round key ile 

9 rounddan oluşan 
    SubBytes
    ShiftRows
    MixColumns
    ve son olarak yeni bir anahtar oluşturup döngü devam ettirilir.

Final Round 
    SubBytes
    shiftRows
    addroundkey
Sonuç--> Chipper Text


    Step1
    Substitute Bytes:
    Orjinal mesaj matrisin 8 bitlik bilgilerini Sbox a yerleştirilme işlemini yapar
    
    Step2
    Shift Rows:
    matrisin satırının index numarasınca sola shift etme işlemi

    Step3
    Mix Matrix:
    matrisin 1.colon ile bir matris ile çarpılıp kendi kolanuna konulması


    Step4
    AddRoundKey:
    matrisimizin anahtar matrisi ile xor lanması işlemi


*********************************************************************************************/

/**********************************************************************************************/



#include "cbc.h"
#include "cbc.c"
int main(int argc, char *argv[])
{
    if(argc < 5) {
        printf("ERROR: expecting 5 paths \"key_file, plaintext_file, sbox_file, inv_sbox_file,Init_Chipper_file\"\n");
        exit(-1);
    }

    char* key_file = NULL, *state_file = NULL, *sbox_file = NULL, *inv_sbox_file = NULL  ,*Init_Chipper_file = NULL;
    key_file = argv[1];
    sbox_file = argv[2];
    inv_sbox_file = argv[3];
    Init_Chipper_file = argv[4];
     state_file = argv[5];
     int count = 5;
    initialize(key_file, state_file, sbox_file, inv_sbox_file,Init_Chipper_file);





   for(int a=0;a<3;a++){

        state_file=argv[count+a];
        initFromFile(STATE_SIZE, state, state_file);
        printf("%d. PLAIN TEXT\n-----------------------------------------\n",a+1 );
            printMatrix(STATE_SIZE ,state);
        if(a==0){
           
            for(int i=0;i<STATE_SIZE;i++){
                for(int j = 0;j<STATE_SIZE;j++){
                    state[i][j] ^= initChipper[i][j];
                }
          
            }
            
           
            
        }

        else{
           
            for(int i=0;i<STATE_SIZE;i++){
                for(int j = 0;j<STATE_SIZE;j++){
                   state[i][j] ^= chipper[i][j];
                }
          
            }


           
           
        }

        encrypt();
         printf("%d. CHIPPER TEXT\n-----------------------------------------\n",a+1 );
            printMatrix(STATE_SIZE ,state);
   }


   
printf("decrypt decrypt decrypt decrypt decrypt decrypt decrypt decrypt decrypt decrypt decrypt decrypt decrypt decrypt decrypt decrypt\n");



   for(int a=0;a<3;a++){
    
       
        if(a==0){
            decrypt();        
             for(int i=0;i<STATE_SIZE;i++){
                for(int j = 0;j<STATE_SIZE;j++){
                    state[i][j] ^= initChipper[i][j];
                }
          
            }
            state_file=argv[count+2-a];
            initFromFile(STATE_SIZE, state, state_file);
            printf("%d. PLAIN TEXT\n-----------------------------------------\n",3-a );
            printMatrix(STATE_SIZE ,state);
        
        }
        else
        {

            decrypt();
           
        
            for(int i=0;i<STATE_SIZE;i++){
                for(int j = 0;j<STATE_SIZE;j++){
                    state[i][j] ^= chipper[i][j];
                }
          
            }
            state_file=argv[count+2-a];
            initFromFile(STATE_SIZE, state, state_file);
            printf("%d. PLAIN TEXT\n-----------------------------------------\n",3-a );
            printMatrix(STATE_SIZE ,state);
            
        }
   }
 
   

   
    return 0;
}


/**********************************************************************************************/
