//include the function prototypes for screen mainipulation
enum COLOR{BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA,  CYAN, WHITE};
#define UNICODE
#define BAR "\u2590"    //unicode of a bar

//function prototype
void setFColor(int fg);
void resetColors(void);
void gotoXY(int row, int col);
void clearScreen(void);
void displayBar(double rms, int col);


