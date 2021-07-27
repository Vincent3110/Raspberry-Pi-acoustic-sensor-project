/*this program just for testing*/
#include "wave.h"
#include <stdio.h>
#include <math.h>

//this program will open a wave header, and display WAV header information
int main(int argc, char *argv[])
{
        FILE *fp;
        WAVHDR myhdr;
        if(argc != 2)
        {
                printf("Usage: %s wav_file\n", argv[0]);
                return -1;
        }
        fp=fopen(argv[1], "r");

        if(fp == NULL)
        {
                printf("Cannot find file %s\n", argv[1]);
                return -1;
        }
        fread(&myhdr, sizeof(myhdr), 1, fp);
        //printf("ChunkID: %c%c%c%c\n", myhdr.ChunkID[0],myhdr.ChunkID[1], myhdr.ChunkID[2], myhdr.Chunk$

        /*printID(myhdr.ChunkID);
        printf("ChunkSize: %d\n", myhdr.ChunkSize);
        printID(myhdr.Format);
        printID(myhdr.Subchunk1ID);*/

        displayWAVHDR(myhdr);
        fclose(fp);

        int answer;
        printf("Do you want to generate a test tone? (1: yes, 0: no) ");
        scanf("%d", &answer);
        if(answer == 1)
                testTone(1000, 5);
}

void testTone(int freq, double duration)
{
        FILE *fp;
        int i;
        WAVHDR h;
        double sample;
        fp = fopen("testtone.wave", "w");
        fillID("RIFF", h.ChunkID);
        //chunk1Size will be calculated later
        fillID("WAVE", h.Format);
        fillID("fmt ", h.Subchunk1ID);
        h.Subchunk1Size = 16;
        h.AudioFormat = 1;
        h.NumChannels = 1;
        h.SampleRate = SAMPLE_RATE;
        h.BitsPerSample = 16;
        h.ByteRate = SAMPLE_RATE * h.NumChannels * (h.BitsPerSample/8);
        h.BlockAlign = h.NumChannels * (h.BitsPerSample/8);
        fillID("data", h.Subchunk2ID);
        h.Subchunk2Size = (int)h.ByteRate * duration;
        h.ChunkSize = h.Subchunk2Size + 36;
        fwrite(&h, sizeof(h), 1, fp);

        for(i=0; i< duration*SAMPLE_RATE; i++)
        {
                sample = 32768*sin(2*PI*freq*i/SAMPLE_RATE);
                fwrite(&sample, sizeof(sample), 1, fp);
        }
        fclose(fp);
}

void displayWAVHDR(WAVHDR hdr)
{
        double duration;
        printf("ChunkID: ");    printID(hdr.ChunkID);
        printf("ChunkSize: %d\n", hdr.ChunkSize);
        printf("Format: ");     printID(hdr.Format);
        printf("Subchunk1 ID; ");       printID(hdr.Subchunk1ID);
        printf("Subchunk1 Size: %d\n", hdr.Subchunk1Size);
        printf("Audio Format: %d\n", hdr.AudioFormat);
        printf("Number of Channel: %d\n", hdr.NumChannels);
        printf("Sample Rate; %d\n", hdr.SampleRate);
        printf("Byte Rate: %d\n", hdr.ByteRate);
        printf("Block Align: %d\n", hdr.BlockAlign);
        printf("Bits per Sample: %d\n", hdr.BitsPerSample);
        printf("Subchunk2 ID; ");       printID(hdr.Subchunk2ID);
        printf("Subchunk2 Size: %d\n", hdr.Subchunk2Size);

        duration = (double)hdr.Subchunk2Size/hdr.ByteRate;
        printf("Duration of Audio: %.3fs\n", duration);
}

void printID(char id[])
{
        int i;
        for(i=0; i<4; i++)
                putchar(id[i]);
        printf("\n");
}

void fillID(const char *s, char duration[])
{
        int i;
        for(i=0; i<4; i++)
    duration[i] = *s++;
}


