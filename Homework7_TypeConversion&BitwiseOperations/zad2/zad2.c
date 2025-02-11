#include <stdio.h>

int main(void) {

  unsigned char lights = 0; //0000 0000

  unsigned char light1 = 1 << 0; //0000 0001
  unsigned char light2 = 1 << 1; //0000 0010
  unsigned char light3 = 1 << 2; //0000 0100
  unsigned char light4 = 1 << 3; //0000 1000
  unsigned char light5 = 1 << 4; //0001 0000
  unsigned char light6 = 1 << 5; //0010 0000
  unsigned char light7 = 1 << 6; //0100 0000
  unsigned char light8 = 1 << 7; //1000 0000

  short answer = 0;

    while(1){
        printf("\n1. Switch Lights\n");
        printf("2. Print State\n");
        printf("Enter '1' or '2': ");
        scanf("%hd", &answer);

        if(answer == 1){
            printf("\nWhich light from 1-8 do you want to switch?\n");
            scanf("%hd", &answer);
            switch(answer)
            {
            case 1: lights = lights ^ light1; break;
            case 2: lights = lights ^ light2; break;
            case 3: lights = lights ^ light3; break;
            case 4: lights = lights ^ light4; break;
            case 5: lights = lights ^ light5; break;
            case 6: lights = lights ^ light6; break;
            case 7: lights = lights ^ light7; break;
            case 8: lights = lights ^ light8; break;

            
            default: printf("Invalid Input"); break;
            }


        } else if(answer == 2){
            int counter = 0;
            int i = 1 << counter;
            printf("\n");
            printf("Currently, Lights: ");

            while(counter < 8){
                if(lights & i){
                    printf("%d, ", (counter+1));
                }
                counter++;
                i = 1 << counter;
            }

            printf(" are turned on!\n");
        } else {
            printf("Invalid Input");
        }
    }
}