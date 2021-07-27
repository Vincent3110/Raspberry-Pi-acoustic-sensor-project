typedef struct
{
        char ChunkID[4];
        int ChunkSize;
        char Format[4];
        char Subchunk1ID[4];
        int Subchunk1Size;
        short int AudioFormat;
        short int NumChannels;
        int SampleRate;
        int ByteRate;
        short int BlockAlign;
        short int BitsPerSample;
        char Subchunk2ID[4];
        int Subchunk2Size;
}WAVHDR;

#define DEBUG
#define SAMPLE_RATE 16000
#define PI 3.1415926

//function prototypes
void displayWAVHDR(WAVHDR hdr);
void printID(char *);
void fillID(const char *, char []);
void testTone(int freq, double duration);
void displayWAVdata(short int []);





