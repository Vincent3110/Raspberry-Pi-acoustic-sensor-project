/*this program just for testing*/
#include "wave.h"
#include <stdio.h>
#include <math.h>
#include <sys/wait.h>
#include "screen.h"
#include <stdlib.h>     //eliminate the warning when -c99
//this program will open a wave header, and display WAV header information
int main(int argc, char *argv[])
{
        FILE *fp;
        WAVHDR myhdr;
        short int sa[SAMPLE_RATE];
        int ret;
        /*if(argc != 2)
        {
                printf("Usage: %s wav_file\n", argv[0]);
                return -1;
        }
        fp=fopen(argv[1], "r");

        if(fp == NULL)
        {
                printf("Cannot find file %s\n", argv[1]);
                return -1;
        }*/


        while(1)
        {
                ret = system("arecord -r16000 -c1 -d1 -f S16_LE -q data.wav");
                clearScreen();          //a fresh screen to display
                if(WIFSIGNALED(ret) && (WTERMSIG(ret) == SIGINT || WTERMSIG(ret) == SIGQUIT))
                        break;
                fp = fopen("data.wav", "r");
                fread(&myhdr, sizeof(myhdr), 1, fp);
        //printf("ChunkID: %c%c%c%c\n", myhdr.ChunkID[0],myhdr.ChunkID[1], myhdr.ChunkID[2], myh$

        /*printID(myhdr.ChunkID);
        printf("ChunkSize: %d\n", myhdr.ChunkSize);
        printID(myhdr.Format);
        printID(myhdr.Subchunk1ID);*/

                displayWAVHDR(myhdr);
                fread(&sa, sizeof(short int), SAMPLE_RATE, fp);
                displayWAVdata(sa);
                fclose(fp);
        }

        int answer;
        printf("Do you want to generate a test tone? (1: yes, 0: no) ");
        scanf("%d", &answer);
        if(answer == 1)
                testTone(1000, 5);
}

