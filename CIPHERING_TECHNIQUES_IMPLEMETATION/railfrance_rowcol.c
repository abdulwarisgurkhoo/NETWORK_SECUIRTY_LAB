#include <stdio.h>
#include <string.h>

// 8. Rail Fence Cipher
void railFence(char text[], int key) {
    int len = strlen(text);
    char rail[key][len];
    for(int i=0; i<key; i++) for(int j=0; j<len; j++) rail[i][j] = '\n';
    
    int dir_down = 0, row = 0, col = 0;
    for(int i=0; i<len; i++) {
        if(row == 0 || row == key-1) dir_down = !dir_down;
        rail[row][col++] = text[i];
        dir_down ? row++ : row--;
    }
    
    printf("Rail Fence Encrypted: ");
    for(int i=0; i<key; i++)
        for(int j=0; j<len; j++)
            if(rail[i][j] != '\n') printf("%c", rail[i][j]);
    printf("\n");
}

// 7. Row-Column Transposition Cipher (Simplified)
void rowColTransposition(char text[], int cols) {
    int len = strlen(text);
    int rows = (len + cols - 1) / cols;
    
    printf("Row-Col Encrypted: ");
    // Read column by column
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            int index = j * cols + i;
            if(index < len) printf("%c", text[index]);
        }
    }
    printf("\n");
}

int main() {
    railFence("networksecurity", 3);
    rowColTransposition("networksecurity", 4);
    return 0;
}